FROM debian:bullseye-slim AS base

# 非インタラクティブモードにする (入力待ちでブロックしなくなる)
ARG DEBIAN_FRONTEND=noninteractive

# .pycを作らないように
ENV PYTHONDONTWRITEBYTECODE=1
# バッファの無効化
ENV PYTHONUNBUFFERED=1
# pythonのバージョン
ENV PYTHON_VERSION=3.9.19

ENV RYE_VERSION=0.38.0
ENV RYE_HOME=/opt/rye

ENV PATH=$PATH:$RYE_HOME/shims

WORKDIR /app

# UIDとGIDは外から与える
ARG USER_UID=10001
ARG USER_GID=10001

# コンテナ内でのユーザー名， グループ名
ARG USER_NAME=user
ARG GROUP_NAME=user

# グループが存在しなかったら，適当なグループを作成
RUN if ! getent group $USER_GID >/dev/null; then \
    groupadd -g $USER_GID $GROUP_NAME; \
    fi

# ユーザーを作成
RUN useradd -m -u $USER_UID -g $USER_GID -s /bin/bash $USER_NAME

RUN chown $USER_UID:$USER_GID /app && \
    mkdir $RYE_HOME && \
    chown $USER_UID:$USER_GID $RYE_HOME

RUN --mount=type=cache,target=/var/lib/apt,sharing=locked \
    --mount=type=cache,target=/var/cache/apt,sharing=locked \
    apt-get update && \
    apt-get install -y --no-install-recommends curl ca-certificates

# 初期ユーザーの変更
USER $USER_NAME

# ryeのインストール
RUN curl -sSf https://rye.astral.sh/get | RYE_VERSION=$RYE_VERSION RYE_INSTALL_OPTION="--yes" RYE_NO_AUTO_INSTALL=1 RYE_TOOLCHAIN_VERSION=$PYTHON_VERSION bash && \
    rye config --set-bool behavior.global-python=true && \
    rye config --set-bool behavior.use-uv=true

# python環境構築
COPY --chown=$USER_NAME:$GROUP_NAME .python-version pyproject.toml requirements.lock requirements-dev.lock ./

# キャッシュを作っておく
RUN rye pin "$(cat .python-version)" && rye sync --no-lock --no-dev

# ----------------------------------------------------------------
# develepment environement
# ----------------------------------------------------------------
FROM base AS development

RUN rye sync --no-lock

# ----------------------------------------------------------------
# production environement
# ----------------------------------------------------------------
FROM base AS production

RUN rye sync --no-lock --no-dev

COPY ./src /app/src

EXPOSE 8080

CMD ["rye", "run", "uvicorn", "src.main:app", "--host", "0.0.0.0", "--port", "8080"]

