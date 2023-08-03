### Docker + Python の環境を作りたい

- ベーシックな Python コンテナを作ってみます

### Dockerfile

- ベースイメージ: `python:3.9`
- ワークディレクトリ: `/app`
- `requirements.txt` でパッケージをインストールするようにしています

```
    # syntax=docker/dockerfile:1
    FROM python:3.9

    WORKDIR /app

    COPY docker/python/requirements.txt /app

    RUN pip install --no-cache-dir --upgrade pip && \
        pip install --no-cache-dir -r requirements.txt
```

---

- 以上
