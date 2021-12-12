### string型購読動作確認用アプリ

string型の購読の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

1.workspaceディレクトリにて、`make app=sub_string` によりアプリをビルド

2.Serial Console (picocomなど) を立ち上げて、初期化

3.hostのros2アプリからstring型のmessageを送信 

4.messageを受信し、表示(以下)

```
Hello from mROS 2!! 1
Hello from mROS 2!! 2
Hello from mROS 2!! 3
...
```
