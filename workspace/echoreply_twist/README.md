### Twist型通信動作確認用アプリ

Twist型の通信の動作確認をするためのサンプルアプリです。
Twist型は、2つのVector3型からなるメッセージ型です。
Vector3型は、3つのfloat64型からなるメッセージ型です。
以下の手順で確認できます。

1.workspace/custom_msgsで、geometry_msgs/msg/Vector3.msgおよびTwist.msgを作成し、それぞれにおいて以下のようにVector3型およびTwist型を定義する。

  ```
  float64 x
  float64 y
  float64 z
  ```

  ```
  geometry_msgs/msg/Vector3 linear
  geometry_msgs/msg/Vector3 angular
  ```

2.geometry_msgs内にmsg_settings.jsonを作成し、以下のように書き込む。今回通信に用いるのはTwist型なので、Twist型定義ファイルの場所を書き込む。(Vector3型はTwist型に含まれるが、通信を行う型自体はVector3型でないので記載しなくて良い)
```
  {
      "pubsubMsgs": [
      "geometry_msgs/msg/Twist.msg"
    ]
  }
```

3.workspaceディレクトリにて、`make gen-msg msg=geometry_msgs` によtwist.hppを生成する。

4.mros2-asp3-f767ziディレクトリにmros2_msgs/geometry_msgs/msg/twist.hppが生成されていることを確認する。

5.echoreply_twistアプリ内で、生成したtwist.hppをincludeして使用する。

6.workspaceディレクトリにて、`make app=echoreply_twist` によりアプリをビルドする。

7.Serial Console (picocomなど) を立ち上げて、初期化する。

8.hostのros2アプリからTwist型のmessageを送信する。

9.messageを受信、これを再びhostのros2アプリに向かって送信する。（以下)

```
subscribed msg!!
publishing msg!!
subscribed msg!!
publishing msg!!
```