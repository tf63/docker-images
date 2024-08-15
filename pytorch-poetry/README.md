# PyTorch + Poetry 環境

> [!CAUTION] > `docker.sh`の TORCH_VERSION はただのタグであり，切り替えて自動でバージョンが変わるわけでは無い

torch のバージョンを切り替えたい場合は`pyproject.toml`をいじる

```pyproject.toml
[tool.poetry.dependencies]
python = "^3.8"
# ↓
torch = "1.9.0+cu111"
```

lock ファイルと`pyproject.toml`の一貫性がなくなり，イメージのビルドが失敗するはず

その場合，`Dockerfile`から`RUN poetry install`をコメントアウトしてビルドする

```Dockerfile
FROM base AS torch-1.9.0

COPY --chown=$USER_NAME:$GROUP_NAME pyproject.toml poetry.lock ./
# ↓
RUN poetry install
```

コンテナ内で次のコマンドを実行し，lock ファイルを更新する

```shell
poetry lock
```

`RUN poetry install`のコメントを外してビルドしなおせば上手くいく
