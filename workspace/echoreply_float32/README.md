### float32型通信動作確認用アプリ

float32型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

1.workspaceディレクトリにて、`make app=float32_test` によりアプリをビルド

2.Serial Console (picocomなど) を立ち上げて、初期化

3.hostのros2アプリからfloat32型のmessageを送信

4.messageを受信、これを再びhostのros2アプリに向かって送信
(ただし、float型の表示上の不具合により、messageが5より大きく10より小さい値の時と、そうでない時で異なる表示がなされる)

```
msg <= 5 or 10 <= msg
msg <= 5 or 10 <= msg
msg <= 5 or 10 <= msg
...
msg <= 5 or 10 <= msg
5 < msg < 10
5 < msg < 10
5 < msg < 10
...

```
