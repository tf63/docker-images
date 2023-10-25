# syntax=docker/dockerfile:1
FROM python:3.9

# コンテナのワークディレクトリを/appに指定
WORKDIR /app

RUN apt update && \
    apt install -y libgl1-mesa-dev

COPY docker/python_cv/requirements.txt /app

RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir -r requirements.txt
