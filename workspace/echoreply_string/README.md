### string型通信動作確認用アプリ

string型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。
This is a sample application for string-type communication.
Please follow the steps below.

1.workspaceディレクトリにて、`make app=echoreply_string` によりアプリをビルドする。
  Execute `make app=echoreply_string` in workspace direcroty, then this app will be built.

2.Serial Console (picocomなど) を立ち上げて、初期化する。
  Open serial console (ex. picocom) and initialize your micro computer board.

3.通信するホストデバイス上で、mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) のmros2_echoback_stringアプリを起動する。
  On the host device to communicate with, run mros2_echoback_string app in mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) .

4.以下のようなログが確認できたら通信成功！
  If you get logs below, which means success!!

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
