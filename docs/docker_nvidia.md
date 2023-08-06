## Ubuntu で nvidia-docker を使って PyTorch の環境を作りたい

ML 系の論文の実装を試していると，複数バージョンの CUDA と PyTorch を使い分ける必要があったりします

今回は `nvidia-docker` を使って複数バージョンの環境を構築してみます

**ソースコード**

https://github.com/tf63/docker_images/tree/pytorch

**ディレクトリ構成**

```bash
    .
    ├── .devcontainer
    │   └── devcontainer.json
    ├── docker
    │   └── pytorch
    │       ├── Dockerfile.111
    │       ├── Dockerfile.171
    │       ├── Dockerfile.171.2
    │       └── requirements.txt
    ├── docker-compose.yml
    └── src
        └── pytorch
```

**動作環境**

Ubuntu 22.04

NVIDIA GeForce RTX 3060 Ti

Docker Engine ( Docker Desktop は非推奨です )

**事前知識**

Ubuntu で Docker のインストール

https://qiita.com/tf63/items/c21549ba44224722f301

Docker の使い方的な話

https://qiita.com/tf63/items/684fe4b818ecd715aed9

### 前準備

公式ドキュメント

https://matsuand.github.io/docs.docker.jp.onthefly/config/containers/resource_constraints/#gpu

まずは Docker で GPU を認識するために必要なパッケージをインストールします

```bash
    sudo apt install nvidia-container-runtime
    # インストール確認
    which nvidia-contaier-runtime-hook

    sudo apt install nvidia-docker2
```

Docker デーモンを再起動

```bash
    sudo service docker restart
```

### Docker イメージの作成

作成したい環境の `nvidia-docker` イメージを選びます

[Docker hub](https://hub.docker.com/r/nvidia/cuda/tags) から 必要な CUDA のバージョンのイメージを選択しましょう

![](img/docker_tag.png)

私は CUDA 11.1 or CUDA 11.7 を使うことが多いので，

- `nvidia/cuda:11.1.1-cudnn8-runtime-ubuntu20.04`
- `nvidia/cuda:11.7.1-cudnn8-runtime-ubuntu20.04`

を選んでみます

選んだイメージをベースに `Dockerfile` を作ります

```Dockerfile
  # サンプルファイル docker/pytorch/Dockerfile
  FROM nvidia/cuda:11.1.1-cudnn8-runtime-ubuntu20.04

  ENV DEBIAN_FRONTEND=noninteractive

  WORKDIR /app

  RUN apt update && \
      apt install -y \
      wget \
      bzip2 \
      build-essential \
      git \
      git-lfs \
      curl \
      ca-certificates \
      libsndfile1-dev \
      libgl1 \
      python3.8 \
      python3-pip

  COPY docker/pytorch/requirements.txt /app

  RUN pip3 install --no-cache-dir -U pip && \
      pip3 install --no-cache-dir -r requirements.txt

  RUN pip3 install --no-cache-dir torch==1.9.0+cu111 torchvision==0.10.0+cu111 -f https://download.pytorch.org/whl/torch_stable.html
```

### Dockerfile で PyTorch をインストールしてみる

https://download.pytorch.org/whl/torch_stable.html で CUDA のバージョンに合った PyTorch を探します

いくつか例を載せておきます

**CUDA11.1**

`cu111/torch-1.9.0%...`，`cu111/torchvision-0.10.0%...`があるので，pip でインストールようにしておく

```Dockerfile
  pip3 install --no-cache-dir torch==1.9.0+cu111 torchvision==0.10.0+cu111 -f https://download.pytorch.org/whl/torch_stable.html
```

**CUDA11.7**

`cu117/torch-1.13.0%...`，`cu117/torchvision-0.14.0%...`があるので，pip でインストールようにしておく

```Dockerfile
  pip3 install torch==1.13.0+cu117 torchvision==0.14.0+cu117 -f https://download.pytorch.org/whl/torch_stable.html
```

**CUDA11.7, PyTorch 2.0**

`cu117/torch-2.0.0%...`，`cu117/torchvision-0.15.0%...`があるので，pip でインストールようにしておく

```Dockerfile
  pip3 install torch==2.0.0+cu117 torchvision==0.15.0+cu117 -f https://download.pytorch.org/whl/torch_stable.html
```

### コンテナに GPU を割り当てる

`docker compose up` で GPU を割り当てる

公式ドキュメント

https://matsuand.github.io/docs.docker.jp.onthefly/compose/gpu-support/

GPU 接続したい Docker サービスで deploy を指定する

```docker-compose.yml
  version: '3.3'

  services:

    pytorch_111:
      build:
        context: .
        dockerfile: docker/pytorch/Dockerfile.111
      container_name: 'nvidia-docker_111'
      stdin_open: true
      tty: true
      volumes:
        - ./:/app

    deploy:
      resources:
        reservations:
          devices:
            - driver: nvidia
            - count: 1
            - capabilities: [gpu]
```

### Docker コンテナの起動

`docker compose up`で起動できるようになっていると思います

```bash
  docker compose up -d
```

## VSCode にコンテナをアタッチしたい

VSCode の拡張機能 `Remote Development` と `Docker` を使うことで，コンテナの中に入って VSCode 上で作業ができます (VSCode にアタッチできる)

  <img src="img/vscode_remote.png" width=70%>
  <img src="img/vscode_docker.png" width=70%>

`Remote Development` では VSCode のワークディレクトリに `.devcontainer/devcontainer.json` を作成することでコンテナを VSCode にアタッチします

**devcontainer.json の例**

Docker サービス名，`docker-compose.yml`へのパスなどを指定する

```
    "name": "PyTorch",
    "dockerComposeFile": "../docker-compose.yml",
    "service": "pytorch_111",
    "workspaceFolder": "/app",
```

`ctrl + shift + P`とかでコマンドパレットを開いて，`Dev Containers: Open Folder in Container...`を実行します

  <img src="img/vscode_attach.png" width=70%>

ターミナルを開くとコンテナの中に入っていることが確認できます

  <img src="img/vscode_gpu_available.png" width=70%>

`PyTorch` で GPU を認識できるか確認します

```
  >>> import torch
  >>> print(torch.cuda.get_device_name())
  NVIDIA GeForce RTX 3060 Ti
```

コンテナから抜ける場合は左下の`Dev Container: Python`をクリックして，`Close Remote Connection`をしてください

  <img src="img/vscode_close.png">

---

以上

### おまけ

**docker run で GPU を割り当てたい**

コンテナを起動するときに `--gpus all` を指定すれば ok です

`nvidia-smi` が通るか確認してみます

```bash
    docker build . -f docker/pytorch/Dockerfile.111 -t pytorch_111:1.0 # Dockerfileをビルドしてイメージを作成
    docker run -it --rm --gpus all pytorch_111:1.0 nvidia-smi # イメージからコンテナを起動
```

**Docker Desktop を使う場合**

私がやったときはエラーを吐いてしまったので，Docker Desktop を完全に削除してから Docker Engine を入れ直しました
