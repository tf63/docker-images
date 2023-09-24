# syntax=docker/dockerfile:1
FROM python:3.9
# FROM nvcr.io/nvidia/pytorch:22.10-py3

# setup (root) ------------------------------------------------------
ENV PYTHONDONTWRITEBYTECODE 1 # .pycを作らないように
ENV PYTHONUNBUFFERED 1 # バッファの無効化
ENV TORCH_HOME /app/.cache # torchvisionでpretrainedのモデルを保存する場所

# ワークディレクトリの指定
WORKDIR /app

RUN apt update && apt install -y \
    libgl1-mesa-dev # opencvで使う

# create user -------------------------------------------------------

# UIDとGIDは外から与える
ARG USER_UID
ARG USER_GID

# コンテナ内でのユーザー名， グループ名
ARG USER_NAME=user
ARG GROUP_NAME=user

# グループが存在しなかったら，　適当なグループを作成
RUN if ! getent group $USER_GID >/dev/null; then \
    groupadd -g $USER_GID $GROUP_NAME; \
    fi

# ユーザーを作成
RUN useradd -m -u $USER_UID -g $USER_GID -s /bin/bash $USER_NAME

# 初期ユーザーの変更
USER $USER_NAME

# setup (user) ------------------------------------------------------

COPY docker/nvc/requirements.txt .
RUN pip install -r requirements.txt
