### health型通信動作確認用アプリ

health型の通信の動作確認をするためのサンプルアプリです。
health型とは、string, uint16, float32型の組み合わせからなるメッセージ型です。
以下の手順で確認できます。

1.workspace/custom_msgsで、health_msgs/msg/Health.msgを作成し、そこに以下のようにROS2の.msgファイルと同様の形式でhealth型を定義する
  ```
  string name
  uint16 height
  float32 weight
  ```

2.health_msgs内にmsg_settings.jsonを作成し、以下のように書き込む
```
  {
    "includingMsgs": [  
		[
			"health_msgs/msg/Health.msg"
		]
	]
 }
```

3.workspaceディレクトリにて、`make gen-msg msg=health_msgs` によりhealth.hppを生成する

4.mros2-asp3-f767ziディレクトリにmros2_msgs/health_msgs/msg/health.hppが生成されていることを確認

5.echoreply_healthアプリ内で、生成したhealth.hppをincludeして使用する。

6.workspaceディレクトリにて、`make app=echoreply_health` によりアプリをビルド

7.Serial Console (picocomなど) を立ち上げて、初期化

8.hostのros2アプリからhealth型のmessageを送信

9.messageを受信、これを再びhostのros2アプリに向かって送信

10.host側で、publishしたメッセージとsubscribeしたメッセージが一致していることを確認