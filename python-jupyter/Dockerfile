FROM python:3.8.19

WORKDIR /app

# UIDとGIDは外から与える
ARG USER_UID
ARG USER_GID

# コンテナ内でのユーザー名， グループ名
ARG USER_NAME=user
ARG GROUP_NAME=user

ENV PYTHONUNBUFFERED=1 
ENV PYTHONDONTWRITEBYTECODE=1 
ENV PIP_DISABLE_PIP_VERSION_CHECK=on 
ENV PIP_DEFAULT_TIMEOUT=100 
ENV POETRY_VERSION=1.8.2 
ENV POETRY_NO_INTERACTION=1 
ENV POETRY_VIRTUALENVS_CREATE=true
ENV POETRY_VIRTUALENVS_IN_PROJECT=true
ENV VENV_PATH="/app/.venv"

# グループが存在しなかったら，適当なグループを作成
RUN if ! getent group $USER_GID >/dev/null; then \
    groupadd -g $USER_GID $GROUP_NAME; \
    fi

# ユーザーを作成
RUN useradd -m -u $USER_UID -g $USER_GID -s /bin/bash $USER_NAME
RUN chown ${USER_UID}:${USER_GID} /app

# 初期ユーザーの変更
USER $USER_NAME
ENV PATH="$PATH:/home/${USER_NAME}/.local/bin:${VENV_PATH}/bin"

COPY poetry.lock pyproject.toml ./

RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir poetry==$POETRY_VERSION

RUN poetry install

EXPOSE 8888
ARG JUPYTER_TOKEN

CMD jupyter notebook --port=8888 --ip=0.0.0.0 --NotebookApp.token=${JUPYTER_TOKEN}
