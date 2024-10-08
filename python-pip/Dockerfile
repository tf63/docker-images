FROM python:3.8.19-slim

WORKDIR /app

# UIDとGIDは外から与える
ARG USER_UID=10001
ARG USER_GID=10001

# コンテナ内でのユーザー名， グループ名
ARG USER_NAME=user
ARG GROUP_NAME=user

ENV PYTHONUNBUFFERED=1
ENV PYTHONDONTWRITEBYTECODE=1
ENV PIP_DISABLE_PIP_VERSION_CHECK=on
ENV PIP_DEFAULT_TIMEOUT=100

# グループが存在しなかったら，適当なグループを作成
RUN if ! getent group $USER_GID >/dev/null; then \
    groupadd -g $USER_GID $GROUP_NAME; \
    fi

# ユーザーを作成
RUN useradd -m -u $USER_UID -g $USER_GID -s /bin/bash $USER_NAME
RUN chown ${USER_UID}:${USER_GID} /app

# 初期ユーザーの変更
USER $USER_NAME
ENV PATH="$PATH:/home/${USER_NAME}/.local/bin"

COPY requirements.txt /app

RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir -r requirements.txt
