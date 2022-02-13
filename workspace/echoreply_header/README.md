### header型通信動作確認用アプリ

header型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

1.workspaceディレクトリにて、`make app=echoreply_header` によりアプリをビルド

2.Serial Console (picocomなど) を立ち上げて、初期化

3.hostのros2アプリからheader型のmessageを送信

4.messageを受信、これを再びhostのros2アプリに向かって送信 (以下)

```
subscribed msg!!
publishing msg!!
subscribed msg!!
publishing msg!!
```
