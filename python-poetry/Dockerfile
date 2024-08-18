FROM python:3.8.19-slim AS base

# 非インタラクティブモードにする (入力待ちでブロックしなくなる)
ARG DEBIAN_FRONTEND=noninteractive

# .pycを作らないように
ENV PYTHONDONTWRITEBYTECODE 1
# バッファの無効化
ENV PYTHONUNBUFFERED 1

ENV POETRY_VERSION 1.8.2
ENV POETRY_NO_INTERACTION 1
ENV POETRY_VIRTUALENVS_CREATE true
ENV POETRY_VIRTUALENVS_IN_PROJECT true

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

# ユーザー周りのセットアップ
RUN chown $USER_UID:$USER_GID /app

RUN --mount=type=cache,target=/var/lib/apt,sharing=locked \
    --mount=type=cache,target=/var/cache/apt,sharing=locked \
    apt-get update && \
    apt-get install -y --no-install-recommends curl ca-certificates

# 初期ユーザーの変更
USER $USER_NAME
ENV PATH /home/$USER_NAME/.local/bin:$PATH

# poetryのインストール
RUN curl -sSL https://install.python-poetry.org | python3 -

# python環境構築
COPY --chown=$USER_NAME:$GROUP_NAME pyproject.toml poetry.lock ./

# キャッシュを作っておく
RUN poetry install --only main

# ----------------------------------------------------------------
# develepment environement
# ----------------------------------------------------------------
FROM base AS development

USER root

RUN --mount=type=cache,target=/var/lib/apt,sharing=locked \
    --mount=type=cache,target=/var/cache/apt,sharing=locked \
    apt-get update && \
    apt-get install -y \
    build-essential

USER $USER_NAME

RUN poetry install

# ----------------------------------------------------------------
# production environement
# ----------------------------------------------------------------
FROM base AS production

RUN poetry install --only main
