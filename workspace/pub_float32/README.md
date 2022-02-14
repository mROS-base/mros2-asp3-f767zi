### float32型通信動作確認用アプリ

float32型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。
This is a sample application for float32-type communication.
Please follow the steps below.

1.workspaceディレクトリにて、`make app=pub_float32` によりアプリをビルドする。
  Execute `make app=pub_float32` in workspace direcroty, then this app will be built.

2.Serial Console (picocomなど) を立ち上げて、初期化
  Open serial console (ex. picocom) and initialize your micro computer board.

3.通信するホストデバイス上で、mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) のmros2_sub_float32アプリを起動する。
  On the host device to communicate with, run mros2_sub_float32 app in mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) .

4.以下のようなログが確認できたら通信成功！
  If you get logs below, which means success!!
```
publishing float msg!!
publishing float msg!!
...

```
