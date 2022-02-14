### Pose型通信動作確認用アプリ

Pose型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

This is a sample application for Pose-type communication.
Please follow the steps below.

1.Pose型は基本型ではなく任意型なので、まずその定義ファイルを用意する。
  ただし、Pose型はPoint型,Quaternion型という任意型を含むので、その定義ファイルも用意する。

  Since Pose-type is not built-in type, you need to prepare the Pose-type definition file.
  Note that Pose-type has Point-type and Quaternion-type, which are also user-defined type, in it, so you need to prepare the Point-type and Quaternion-type definition file.

  Point.msg
  ```
  float64 x
  float64 y
  float64 z
  ```

  Quaternion.msg
  ```
  float64 x
  float64 y
  float64 z
  float64 w
  ```

  Pose.msg
  ```
  geometry_msgs/msg/Point position
  geometry_msgs/msg/Quaternion orientation
  ```
  
2.geometry_msgs/msgというディレクトリをcustom_msgsディレクトリ下に作成し、その下にこれらを配置する。

  Make geometry_msgs/msg directory under custom_msgs directory, then set these definition files.

3.geometry_msgsディレクトリ下にmsg_settings.jsonというファイルを作成する。
  以下のように、pubsubMsgsをkeyとするvalueに、通信を実際に行う型の定義ファイルのパスを全て、
  配列として記載する。ただし、今回は内部にPoint型,Quaternion型を含む任意型であるPose型による通信を行うが、
  その際Point型,Quaternion型のパスは記載しなくて良い。

  Make msg_settings.json under geometry_msgs directory.
  Then set all paths to each definition files used in this app at pubsubMsgs' value like below.
  Note that Pose-type message is to be sent now and Pose-type has Point-type and Quaternion-type, but you don't have to include path to Point-type and Quaternion-type definition file.

  ```
  {
      "pubsubMsgs": [
      "geometry_msgs/msg/Pose.msg"
    ]
  }
  ```
  

4.workspaceディレクトリで、`make gen-msg msg=geometry_msgs`を実行する。
  するとルートディレクトリに、mros2_msgs/geometry_msgs/msg/point.hpp, mros2_msgs/geometry_msgs/msg/quaternion.hpp およびmros2_msgs/geometry_msgs/msg/pose.hppが生成される。

  Execute `make gen-msg msg=geometry_msgs` in workspace direcroty, then point.hpp, quaternion.hpp and pose.hpp will be generated in {root}/mros2_msgs/geometry_msgs/msg directory.

5.workspaceディレクトリにて、`make app=sub_pose` によりアプリをビルドする。

  Execute `make app=sub_pose` in workspace direcroty, then this app will be built.
  
6.Serial Console (picocomなど) を立ち上げて、初期化する。

  Open serial console (ex. picocom) and initialize your micro computer board.

7.通信するホストデバイス上で、mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) のmros2_pub_poseアプリを起動する。

  On the host device to communicate with, run mros2_pub_pose app in mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) .

8.以下のようなログが確認できたら通信成功！

  If you get logs below, which means success!!

```
subscribed Pose msg!!
subscribed Pose msg!!
...

```