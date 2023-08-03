### Ubuntu で Docker のインストール

- Docker のインストール方法は[色々](https://kinsta.com/jp/blog/install-docker-ubuntu/)あるみたいですが，今回は Docker Engine を apt で普通にインストールします．

**動作環境**

- Ubuntu 22.04

**前準備**

- (参考) https://docs.docker.com/engine/install/ubuntu/#set-up-the-repository

- 必要なパッケージのインストール

```
    sudo apt-get update
    sudo apt-get install ca-certificates curl gnupg
```

- Docker GPG key の登録

```
    sudo install -m 0755 -d /etc/apt/keyrings
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
    sudo chmod a+r /etc/apt/keyrings/docker.gpg
```

- リポジトリの設定

```
    echo \
    "deb [arch="$(dpkg --print-architecture)" signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
    "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | \
    sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

- Docker Engine のインストール

```
    sudo apt install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

**Docker グループの作成**

- ユーザーを Docker グループに所属させる

```
    sudo groupadd docker
    sudo usermod -aG docker <ユーザー名>
```

**インストール確認**

- Docker のインストール確認

```
    docker --version
```

- Docker compose が利用可能か確認

```
    # ハイフンは不要です
    docker compose version
```

**VSCode に Docker 拡張機能をインストール**

- `Docker`と`Remote Development`をインストールしましょう
  <img src="img/vscode_docker.png" width=70%>
  <img src="img/vscode_remote.png" width=70%>

- `devcontainer.json`を設定することで VSCode にコンテナをアタッチできるようになります (次回以降に紹介)

---

以上
