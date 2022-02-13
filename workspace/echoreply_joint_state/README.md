### JointState型通信動作確認用アプリ

JointState型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

1.workspace/custom_msgsで、sensor_msgs/msg/JointState.msgを作成し、JointState型を定義する。

  ```
  header header
  string[] name
  float64[] position
  float64[] velocity
  float64[] effort
  ```

2.sensor_msgs内にmsg_settings.jsonを作成し、以下のように書き込む。今回通信に用いるのはJointState型なので、JointState型定義ファイルの場所を書き込む。
```
  {
      "pubsubMsgs": [
      "sensor_msgs/msg/JointState.msg"
    ]
  }
```

3.workspaceディレクトリにて、`make gen-msg msg=sensor_msgs` によjoint_state.hppを生成する。

4.mros2-asp3-f767ziディレクトリにmros2_msgs/sensor_msgs/msg/joint_state.hppが生成されていることを確認する。

5.echoreply_joint_stateアプリ内で、生成したjoint_state.hppをincludeして使用する。

6.workspaceディレクトリにて、`make app=echoreply_joint_state` によりアプリをビルドする。

7.Serial Console (picocomなど) を立ち上げて、初期化する。

8.hostのros2アプリからJointState型のmessageを送信する。

9.messageを受信、これを再びhostのros2アプリに向かって送信する。（以下)

```
subscribed msg!!
publishing msg!!
subscribed msg!!
publishing msg!!
```