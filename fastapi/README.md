# FastAPI 環境
コンテナの起動
```
    # これだけでuvicornサーバーは立ち上がります
    docker compose up -d
    # シェルにコンテナをアタッチする場合
    docker compose exec python /bin/bash
```

production用のビルド
```
    docker build . --build-arg USER_UID=1000 --build-arg USER_GID=1000 --target production -t image_name
```

## 環境構築の参考

https://blog.studysapuri.jp/entry/Poetry-Docker-Build-and-Run

https://miguel-mendez-ai.com/2024/03/12/poetry-torch-docker
