### string型通信動作確認用アプリ

string型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

1.workspaceディレクトリにて、`make app=echoreply_string` によりアプリをビルド

2.Serial Console (picocomなど) を立ち上げて、初期化

3.hostのros2アプリからstring型のmessageを送信

4.messageを受信、これを再びhostのros2アプリに向かって送信 (以下)

```
Subscribed msg : Hello, world! 1
Publishing msg : Hello, world! 1
Subscribed msg : Hello, world! 2
Publishing msg : Hello, world! 2
Subscribed msg : Hello, world! 3
Publishing msg : Hello, world! 3
Subscribed msg : Hello, world! 4
Publishing msg : Hello, world! 4
...
```
