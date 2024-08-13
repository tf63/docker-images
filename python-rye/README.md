# Rye 環境

ベースイメージを`FROM debian:bullseye-slim`として rye で python を入れる

### コマンド

Rye でパッケージをインストール

```
# プロジェクトの初期化
rye init

# 環境のセットアップ
rye sync

# ロックファイルを更新しない場合
rye sync --no-lock

# 開発用パッケージを含めない
rye sync --no-dev

# パッケージの追加
rye add <package>

# 開発用パッケージの追加
rye add -d <package>

# バージョンを指定したインストール
rye add <package>==x.x.x

# パッケージの削除
# rye remove <package>

# インストールされているパッケージの確認
rye list
```

Rye のその他のコマンド

```
# 環境にあるバイナリの実行
rye run <command>

# テストを実行する
rye test

# format
rye fmt

# lint
rye lint

# pythonパッケージをビルドする
rye build

# pythonパッケージを公開する
rye publish
```

コンテナの起動

```
docker compose up -d
docker compose exec python /bin/bash
```

### インストール可能な Python の確認

```
rye toolchain list --include-downloadable
```

-   cpython だけでなく pypy もある
-   このへんを使いたい
    -   `cpython3.8.15`, `cpython3.9.18`, `cpython3.10.14`, `cpython3.11.9`, `cpython3.12.4`

### Virtual Project

-   `.venv` を volume マウントしているせい (?) で Docker 環境では次のエラーが出る

```
warning: Failed to hardlink files; falling back to full copy. This may lead to degraded performance. If this is intentional, use `--link-mode=copy` to suppress this warning.
```

-   `tool.rye.virtual`を true にすると回避できる
-   パッケージがインストール可能でなくなるので注意

> When syncing the project itself is never installed into the virtualenv as it's not considered to be a valid package. Likewise you cannot publish virtual packages to PyPI or another index.
> https://rye.astral.sh/guide/virtual/

### Rye の設定

-   `~/.rye/config.toml`に記載される
-   rye config で設定すると`~/.rye/config.toml`に追記される
-   デフォルトで`uv`を使うようになっているが，`Dockerfile`で一応設定しておく

-   https://zenn.dev/dena/articles/rye_python_in_devcontainer#2.2.-uv-%E3%82%92%E4%BD%BF%E3%81%88%E3%82%8B%E6%A7%98%E3%81%AB%E3%81%99%E3%82%8B
