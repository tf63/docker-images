# GoのDocker環境

```
    # 開発用
    docker compose up -d
    # 本番用イメージビルド
    docker build . --target runner -t <image_name>
```

### 備考
- go.modが空だと`go mod download`しても`/go/pkg`が作成されない
