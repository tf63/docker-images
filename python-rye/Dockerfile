FROM debian:bullseye-slim as base

WORKDIR /app

# UIDとGIDは外から与える
ARG USER_UID
ARG USER_GID

# コンテナ内でのユーザー名， グループ名
ARG USER_NAME=user
ARG GROUP_NAME=user

ENV PYTHON_VERSION=3.9.19
ENV PYTHONUNBUFFERED=1
ENV PYTHONDONTWRITEBYTECODE=1
ENV RYE_VERSION=0.38.0
ENV RYE_HOME=/opt/rye

ENV PATH=$PATH:$RYE_HOME/shims

# グループが存在しなかったら，適当なグループを作成
RUN if ! getent group $USER_GID >/dev/null; then \
    groupadd -g $USER_GID $GROUP_NAME; \
    fi

# ユーザーを作成
RUN useradd -m -u $USER_UID -g $USER_GID -s /bin/bash $USER_NAME
RUN chown $USER_UID:$USER_GID /app && \
    mkdir $RYE_HOME && \
    chown $USER_UID:$USER_GID $RYE_HOME

# ----------------------------------------------------------------
# develepment environement
# ----------------------------------------------------------------
FROM base as dev

RUN apt-get update && \
    apt-get install -y curl && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 初期ユーザーの変更
USER $USER_NAME

# ryeのインストール
RUN curl -sSf https://rye.astral.sh/get | RYE_VERSION=$RYE_VERSION RYE_INSTALL_OPTION="--yes" RYE_TOOLCHAIN_VERSION=$PYTHON_VERSION bash

RUN rye config --set-bool behavior.global-python=false && \
    rye config --set-bool behavior.use-uv=true

# python環境構築
COPY --chown=$USER_NAME:$USER_NAME .python-version pyproject.toml requirements.lock requirements-dev.lock ./
RUN rye pin "$(cat .python-version)" && rye sync
