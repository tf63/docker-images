# PyTorch + poetry環境
> [!CAUTION]
> `docker.sh`のTORCH_VERSIONはただのタグ
> 切り替えて自動でバージョンが変わるわけでは無い

初回に`poetry install`してプロジェクト直下に仮想環境`.venv/`を作成する
仮想環境を使うには`poetry run python3`する必要があることに注意

## 環境をカスタムする場合
`poetry add`でtorchを入れて`pyproject.toml`と`poetry.lock`を作る作戦
```
    # + -> %2B としないと弾かれます

    # https://download.pytorch.org/whl/cu111/torch/
    poetry add https://download.pytorch.org/whl/cu111/torch-1.9.0%2Bcu111-cp38-cp38-linux_x86_64.whl
    # https://download.pytorch.org/whl/cu111/torchvision
    poetry add https://download.pytorch.org/whl/cu111/torchvision-0.10.0%2Bcu111-cp38-cp38-linux_x86_64.whl
```
