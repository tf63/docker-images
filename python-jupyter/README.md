# Jupter 環境
コンテナの起動
```
    docker compose up -d
```

ホスト側のVSCodeからコンテナ内のJupyterに接続する

適当な`ipynb`ファイルを開いて右上の**Select Kernel > Existing Jupyter Server...**を選択

<img src=img/README.png width=300px>

`http://localhost:8888/?token=token`と入力 (接続情報は保存できるので2回目以降はそれを使う)
- tokenは`docker-compose.yml`で指定したもの

正直，VSCodeの自動補完が効かないのでdevcontainerを使った方が良いと思う．

## 環境構築の参考

https://blog.studysapuri.jp/entry/Poetry-Docker-Build-and-Run

https://miguel-mendez-ai.com/2024/03/12/poetry-torch-docker
