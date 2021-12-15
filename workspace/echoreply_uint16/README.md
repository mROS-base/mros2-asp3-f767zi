### int16型通信動作確認用アプリ

int16型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

1.workspaceディレクトリにて、`make app=int16_test` によりアプリをビルド

2.Serial Console (picocomなど) を立ち上げて、初期化

3.hostのros2アプリからint16型のmessageを送信

4.messageを受信、これを再びhostのros2アプリに向かって送信 (以下)

```
Subscribed msg : 1
Publishing msg : 1
Subscribed msg : 2
Publishing msg : 2
Subscribed msg : 3
Publishing msg : 3
Subscribed msg : 4
Publishing msg : 4
...
```
