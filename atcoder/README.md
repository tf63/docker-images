# AtCoder の環境を Docker で作りたい

**やりたいこと**

- AtCoder 用の`C++`の環境を Docker で構築したい
- AtCoder の問題のテスト･提出を CLI でやりたい
- 各種コマンドを VSCode のタスクを使って自動化したい

**ソースコード**

https://github.com/tf63/docker_images/tree/atcoder

**ディレクトリ構成**

```bash
    .
    ├── .devcontainer
    │   └── devcontainer.json
    ├── .vscode
    │   ├── c_cpp_properties.json
    │   └── tasks.json
    ├── cmd
    │   ├── abc_dl.sh
    │   ├── arc_dl.sh
    │   ├── other_dl.sh
    │   └── typical.sh
    ├── docker
    │   └── atcoder
    │       └── Dockerfile
    ├── docker-compose.yml
    ├── src
    │   └── atcoder
    │       ├── abc
    │       │   └── abc001
    │       ├── arc
    │       │   └── arc001
    │       └── other
    └── templates
        ├── atcoder.cpp
        └── input.txt
```

## 使用するツール

**online-judge-tools (oj)**

CLI で問題のダウンロードやテスト，提出をやってくれる

https://github.com/online-judge-tools/oj

**atcoder-cli (acc)**

oj の問題のダウンロードと提出をうまいことやってくれる

https://github.com/Tatamo/atcoder-cli/tree/develop

## 環境構築

**Dockerfile**

```Dockerfile
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

    # ojのインストール
    RUN pip install online-judge-tools==11.5.1
```

**docker-compose.yml**

```docker-compose.yml
    version: '3.3'

    services:
        atcoder:
            build:
                context: .
                dockerfile: docker/atcoder/Dockerfile
            container_name: atcoder
            stdin_open: true
            tty: true
            volumes:
                - ./:/app
```

**Docker コンテナの立ち上げ**

```bash
    docker compose up -d
```

**VSCode へのアタッチ**

`.devcontainer/devcontainer.json`を作成

```devcontainer.json
    "name": "AtCoder",
    "dockerComposeFile": "../docker-compose.yml",
    "service": "atcoder",
    "workspaceFolder": "/app",
```

`ctrl + shift + P`とかでコマンドパレットを開いて，`Dev Containers: Open Folder in Container...`を実行

  <img src="img/vscode_attach.png" width=70%>

**タスクの登録**

`.vscode/tasks.json`を作成する

```tasks.json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "abc_dl",
                "type": "shell",
                "command": "${workspaceFolder}/cmd/abc_dl.sh ${input:abc_dl}",
                "presentation": {
                    "reveal": "always",
                    "focus": true,
                    "panel": "shared",
                },
            },
        (略)
```

**VSCode の拡張機能 Task Runner**

VSCode へのアタッチ時に拡張機能 `Task Runner` をインストールするように設定してある

これを使うと `.vscode/tasks.json`に登録されたタスクを GUI で実行できる

  <img src="img/task_runner.png" width=40%>

## 初期設定

**acc, oj のログイン**

acc, oj で AtCoder のユーザー名とパスワードを入力してログインする

```bash
    # ダウンロードの確認
    acc check-oj
    # accのログイン
    acc login
    # ojのログイン
    oj login https://beta.atcoder.jp
```

**acc の設定の変更**

デフォルトで全部の問題がダウンロードされるようにしておく

```bash
    acc config default-task-choice all
```

## 問題のダウンロード

vscode のタスク`abc_dl`, `arc_dl`を実行すると，abc, arc 問題のダウンロードができる

- abc 問題のダウンロード -> `src/atcoder/abc/`にダウンロードされる
- arc 問題のダウンロード -> `src/atcoder/arc/`にダウンロードされる

    <img src="img/task_dl.png" width=70%>

**結果**

- `abc001/` -> A, B, C, ...問題のディレクトリ
- `abc001/a/test/` -> A 問題のテストケースがダウンロードされる
- `abc001/a/abc001_a.cpp` -> A 問題の解答ファイルが`/app/templates/atcoder.cpp`をコピーして作られる

```bash
└── src/atcoder/abc
　　        　    └── abc001
　　        　        │── a
　　        　        │    ├── abc001_a.cpp
　　        　        │    └── tests
　　        　        │        ├── sample-1.in
　　        　        │        ├── sample-1.out
　　        　        │        ├── sample-2.in
　　        　        │        ├── sample-2.out
　　        　        │        ├── sample-3.in
　　        　        │        └── sample-3.out
　　　　　　　　      　└── b
                    (略)
```

## テストの実行

解答用の cpp ファイルを開いて，vscode のタスク`test`を実行すると，例題でのテストが開始される

![](img/task_test.png)

## 解答の提出

解答用の cpp ファイルを開いて，vscode のタスク`submit`を実行すると，自動で提出できる

(おそらく問題と一緒に作成された`contest.acc.json`をもとに提出先を決めている)

![](img/task_submit.png)

警告が出ているが問題ない，指示通り abc1 とか入力すれば OK

AtCoder の提出ページに行けば提出が確認できる

---

以上

---

## おまけ

**acc のインストール先**

`/lib/ac-library`

**c++の formatter の設定**

`.clang-format`でいじる

```.clang-format
    # デフォルト設定
    BasedOnStyle: Chromium
    # インデント幅
    IndentWidth: 4
    # 言語
    Language: Cpp
    Standard: Auto
    # 1行あたりの
    ColumnLimit: 120
```

**解答ファイルのテンプレート**

解答用の cpp ファイルは`./templates/atcoder.cpp`をコピーして作成される

(`./cmd/abc_dl.sh`, `./cmd/arc_dl.sh`で`./templates/atcoder.cpp`をコピーしている)

```cmd/abc_dl.sh
    TEMPLATE="${WORKDIR}/templates/atcoder.cpp"
    (略)
    cp -n $TEMPLATE "${DIRPATH}/$1_${DIRPATH##*/}.cpp"
```

**タスクをコマンドで実行する場合**

```bash
    # 問題のダウンロード
    ./cmd/abc_dl.sh abc123
    # 解答のテスト
    oj t -d tests/へのパス -c 実行ファイルへのパス
    # 解答の提出
    acc submit 提出するファイルへのパス
```

## 参考

一連の流れ

https://qiita.com/Adaachill/items/3d4ddad56c5c2cc372cd

タスク(compile)

https://iconcreator.hatenablog.com/entry/2021/09/19/200000

タスク(submit, test)

https://blog.knshnb.com/posts/vscode-oj-acl/
