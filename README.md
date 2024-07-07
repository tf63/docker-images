## Dockerfileをまとめておく場所

### 備考
- 一部のイメージではコンテナ内にユーザーを作成しています
- コンテナ側とホスト側でUID/GIDが一致してない場合，権限周りのエラーを起こすことがあります
- そのため，UID/GIDは`docker-compose.yml`や`docker.sh`で外から`USER_UID, USER_GID`という形で与えています

- ホスト側のUID/GIDの確認はターミナルで次のコマンドを打ちます (Windowsでの動作は分かりません)
```
    # USER_UID
    id -u 
    # USER_GID
    id -g
```

### 記事

[**Docker ってなんぞやという話 ~ Docker, Docker Compose のチュートリアル ~ VSCode の Remote Development まで**](https://qiita.com/tf63/items/684fe4b818ecd715aed9)
[**Ubuntu で Docker のインストール**](https://qiita.com/tf63/items/c21549ba44224722f301)
[**Ubuntu で nvidia-docker を使って PyTorch の環境を作りたい**](https://qiita.com/tf63/items/618f192a810c28e4d2b7)
[**AtCoder の環境を Docker で作りたい**](https://qiita.com/tf63/items/c93c6f24d73599e637d8)
