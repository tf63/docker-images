FROM golang:1.19-alpine as base

# ワークディレクトリの指定
WORKDIR /app

# ----------------------------------------------------------------
# 依存関係の解決
# ----------------------------------------------------------------
FROM base as deps

# モジュールのダウンロード
COPY go.mod go.sum ./
RUN go mod download

# ----------------------------------------------------------------
# ビルド
# ----------------------------------------------------------------
FROM base as builder

COPY --from=deps /go/pkg /go/pkg
COPY . .

# 外部依存の無い実行ファイルを作る
ARG CGO_ENABLED=0
# 64bit linux用にビルドする
ARG GOOS=linux
ARG GOARCH=amd64
# ビルド成果物にデバック情報が含まれないようにする
RUN go build -ldflags '-s -w' -o ./server

# ----------------------------------------------------------------
# 本番環境
# ----------------------------------------------------------------
FROM alpine as runner-alpine

WORKDIR /app

RUN addgroup --system --gid 10001 nonroot
RUN adduser --system --uid 10001 nonroot

COPY --from=builder --chown=nonroot:nonroot /app/server .
ENTRYPOINT ["./server"]

USER nonroot

# ポートの開放
EXPOSE 8080

# ----------------------------------------------------------------
# 本番環境 (distroless)
# https://github.com/GoogleContainerTools/distroless?tab=readme-ov-file
# ----------------------------------------------------------------
FROM gcr.io/distroless/static-debian12:nonroot as runner-distroless

WORKDIR /app

USER nonroot

COPY --from=builder /app/server .

ENTRYPOINT ["./server"]

# ポートの開放
EXPOSE 8080
# ----------------------------------------------------------------
# 開発環境
# ----------------------------------------------------------------
FROM golang:1.19-alpine as dev

WORKDIR /app

RUN go install github.com/cosmtrek/air@v1.40.0

ENTRYPOINT ["air"]
