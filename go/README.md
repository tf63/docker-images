# GoのDocker環境
- [**マルチステージビルドとdistrolessイメージを活用してGoイメージを極限まで軽量化する**](https://qiita.com/tf63/items/b6e12887048bccdb2332)
```shell
    # 開発環境の立ち上げ
    docker compose up -d

    # 本番環境のビルド (alpine)
    docker build . --target runner-alpine -t go-alpine

    # 本番環境のビルド (distroless)
    docker build . --target runner-distroless -t go-distroless
```

### 備考
- go.modが空だと`go mod download`しても`/go/pkg`が作成されない
