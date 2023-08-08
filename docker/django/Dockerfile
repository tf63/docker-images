# syntax=docker/dockerfile:1
FROM python:3.8
ENV PYTHONUNBUFFERED 1

# コンテナのワークディレクトリを/appに指定
WORKDIR /app

# ソースコードをコンテナにコピー
COPY ./docker/django/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

# # ユーザー名を指定
# ARG USERNAME=user
# ARG GROUPNAME=user

# # UID, GIDはidコマンドで確認し，ログインユーザーのUID, GIDを指定する
# ARG UID=1000
# ARG GID=1000

# # ユーザーを作成
# RUN groupadd -g $GID $GROUPNAME && \ 
#     useradd -m -u $UID -g $GID -s /bin/bash $USERNAME

# # 初期ユーザーの変更
# USER $USERNAME

# # pathを通す
# ENV PATH="$PATH:/home/user/.local/bin"

# ローカルのrequirements.txtをコンテナの/app直下に置く
COPY docker/django/requirements.txt /app

# コンテナ内でpipをアップグレードした後、pip install -r requirements.txtを実行
RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir -r requirements.txt

# 8000番を開く
EXPOSE 8000