# GoのDocker環境

```
    # 開発用
    docker compose up -d
    # 本番用イメージビルド
    docker build . --target runner -t <image_name>
```

### 備考
- go.modが空だと`go mod download`しても`/go/pkg`が作成されない


### 参考

distrolessイメージ

https://github.com/GoogleContainerTools/distroless?tab=readme-ov-file

Dockerfileの参考

https://zenn.dev/awonosuke/articles/dfe3a44486feb9
