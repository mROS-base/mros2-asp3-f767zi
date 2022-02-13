### Odometry型通信動作確認用アプリ

Odometry型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

1.workspace/custom_msgsで、nav_msgs/msg/Odometry.msgを作成し、Odometry型を定義する。なお、Odometry型は多くの任意型(PoseWithCovariance, TwistWithCovariance, ...) を含むので、それらの定義も各ファイルで行う。

  ```
  header header
  string child_frame_id
  geometry_msgs/msg/PoseWithCovariance pose
  geometry_msgs/msg/TwistWithCovariance twist
  ```

2.nav_msgs内にmsg_settings.jsonを作成し、以下のように書き込む。今回通信に用いるのはOdometry型なので、Odometry型定義ファイルの場所を書き込む。
  ```
  {
      "pubsubMsgs": [
      "nav_msgs/msg/Odometry.msg"
    ]
  }
  ```

3.workspaceディレクトリにて、`make gen-msg msg=nav_msgs` によodometry.hppを生成する。

4.mros2-asp3-f767ziディレクトリにmros2_msgs/nav_msgs/msg/odometry.hppが生成されていることを確認する。

5.echoreply_odometryアプリ内で、生成したodometry.hppをincludeして使用する。

6.workspaceディレクトリにて、`make app=echoreply_odometry` によりアプリをビルドする。

7.Serial Console (picocomなど) を立ち上げて、初期化する。

8.hostのros2アプリからOdometry型のmessageを送信する。

9.messageを受信、これを再びhostのros2アプリに向かって送信する。（以下)

  ```
  subscribed msg!!
  publishing msg!!
  subscribed msg!!
  publishing msg!!
  ```