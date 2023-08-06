## Ubuntu で Docker のインストール

Docker のインストール方法は[色々](https://kinsta.com/jp/blog/install-docker-ubuntu/)あるみたいですが，

- **パターン 1: Docker Engine のインストール**
- ( パターン 2: Docker Desktop のインストール )

の 2 つについて紹介します

Docker Desktop が Ubuntu をサポートしたのは最近なので，まだ Docker Desktop に対応していないツールがあります

そのため，私は **パターン 1: Docker Engine のインストール** を推奨します

**動作環境**

Ubuntu 22.04

### 前準備

公式ドキュメント https://docs.docker.com/engine/install/ubuntu/#set-up-the-repository

必要なパッケージのインストール

```
    sudo apt-get update
    sudo apt-get install ca-certificates curl gnupg
```

Docker GPG key の登録

```
    sudo install -m 0755 -d /etc/apt/keyrings
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
    sudo chmod a+r /etc/apt/keyrings/docker.gpg
```

リポジトリの設定

```
    echo \
    "deb [arch="$(dpkg --print-architecture)" signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
    "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | \
    sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

docker グループを作成し，ユーザーを所属させる

```bash
    sudo groupadd docker
    sudo usermod -aG docker <ユーザー名>
```

これで前準備は完了です

## パターン 1: Docker Engine のインストール

Docker Engine のインストール

```bash
    sudo apt install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

**インストール確認**

Docker のインストール確認

```bash
    docker --version
```

最新バージョンの Docker には `docker-compose` もデフォルトで付属しているはず

```bash
    # ハイフンは不要です
    docker compose version
```

これで完了です

## パターン 2: Docker Desktop のインストール

**Docker Desktop のインストール**

公式ドキュメント https://docs.docker.com/desktop/install/ubuntu/

Deb パッケージを[公式](https://docs.docker.com/desktop/install/ubuntu/)からダウンロードし，インストール

```bash
    sudo apt-get update
    sudo apt-get install path/to/docker-desktop-<version>-<arch>.deb
```

Docker Desktop のアプリケーションがインストールされてます

![](img/docker_install.png)

ログインとかはしなくとも大丈夫です

---

以上
