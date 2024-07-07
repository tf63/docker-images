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

ARG CGO_ENABLED=0
ARG GOOS=linux
ARG GOARCH=amd64
RUN go build -ldflags '-s -w' -o ./server

# ----------------------------------------------------------------
# 本番環境
# ----------------------------------------------------------------
FROM alpine as runner

RUN apk update

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
