# syntax=docker/dockerfile:1
FROM python:3.9

WORKDIR /app

# # ユーザー名を指定
# ARG USERNAME=user
# ARG GROUPNAME=user

# # UID, GIDはidコマンドで確認し，ホストのユーザーのUID, GIDを指定する
# ARG UID=1000
# ARG GID=1000

# # ユーザーを作成
# RUN groupadd -g $GID $GROUPNAME && \ 
#     useradd -m -u $UID -g $GID -s /bin/bash $USERNAME

# # 初期ユーザーの変更
# USER $USERNAME

# # pathを通す
# ENV PATH="$PATH:/home/user/.local/bin"

COPY docker/python/requirements.txt /app

RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir -r requirements.txt