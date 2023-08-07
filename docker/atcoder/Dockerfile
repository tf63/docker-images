# syntax=docker/dockerfile:1
FROM node:19

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive

# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo

WORKDIR /app

# 起動シェルをshからbashに変更
SHELL ["/bin/bash", "-c"]

# パッケージなど
RUN apt update && \
    apt install -y \
    time \
    tzdata \
    tree \
    git \
    curl \
    gcc-9 \
    g++-9 \
    gdb \
    python3.9 \
    python3-pip

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

# atcoder-cliのインストール
RUN npm install -g atcoder-cli@2.2.0

# ユーザー名を指定
# ARG USERNAME=user
# ARG GROUPNAME=user

# UID, GIDはidコマンドで確認し，ログインユーザーのUID, GIDを指定する
# ARG UID=1000
# ARG GID=1000

# ユーザーを作成
# RUN groupadd -g $GID $GROUPNAME && \ 
# RUN useradd -m -u $UID -g $GID -s /bin/bash $USERNAME

# 初期ユーザーの変更
# USER $USERNAME

# コンテスト補助アプリケーションをインストール
RUN pip install online-judge-tools==11.5.1