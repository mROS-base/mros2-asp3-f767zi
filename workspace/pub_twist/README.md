### Twist型通信動作確認用アプリ

Twist型の通信の動作確認をするためのサンプルアプリです。
以下の手順で確認できます。

This is a sample application for Twist-type communication.
Please follow the steps below.

1.Twist型は基本型ではなく任意型なので、まずその定義ファイルを用意する。
  ただし、Twist型はVector3型という任意型を含むので、その定義ファイルも用意する。

  Since Twist-type is not built-in type, you need to prepare the Twist-type definition file.
  Note that Twist-type has Vector3-type, which is also user-defined type, in it, so you need to prepare the Vector3-type definition file.

  Vector3.msg
  ```
  float64 x
  float64 y
  float64 z
  ```

  Twist.msg
  ```
  geometry_msgs/msg/Vector3 linear
  geometry_msgs/msg/Vector3 angular
  ```
  
2.geometry_msgs/msgというディレクトリをcustom_msgsディレクトリ下に作成し、その下にこれらを配置する。

  Make geometry_msgs/msg directory under custom_msgs directory, then set these definition files.

3.geometry_msgsディレクトリ下にmsg_settings.jsonというファイルを作成する。
  以下のように、pubsubMsgsをkeyとするvalueに、通信を実際に行う型の定義ファイルのパスを全て、
  配列として記載する。ただし、今回は内部にVector3型を含む任意型であるTwist型による通信を行うが、
  その際Vector3型のパスは記載しなくて良い。

  Make msg_settings.json under geometry_msgs directory.
  Then set all paths to each definition files used in this app at pubsubMsgs' value like below.
  Note that Twist-type message is to be sent now and Twist-type has Vector3-type, but you don't have to include path to Vector3-type definition file.

  ```
  {
      "pubsubMsgs": [
      "geometry_msgs/msg/Twist.msg"
    ]
  }
  ```

  

4.workspaceディレクトリで、`make gen-msg msg=geometry_msgs`を実行する。
  するとルートディレクトリに、mros2_msgs/geometry_msgs/msg/vector3.hppおよびmros2_msgs/geometry_msgs/msg/twist.hppが生成される。

  Execute `make gen-msg msg=geometry_msgs` in workspace direcroty, then vector3.hpp and twist.hpp will be generated in {root}/mros2_msgs/geometry_msgs/msg directory.

5.workspaceディレクトリにて、`make app=pub_twist` によりアプリをビルドする。

  Execute `make app=pub_twist` in workspace direcroty, then this app will be built.
  
6.Serial Console (picocomなど) を立ち上げて、初期化する。

  Open serial console (ex. picocom) and initialize your micro computer board.

7.通信するホストデバイス上で、mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) のmros2_sub_twistアプリを起動する。

  On the host device to communicate with, run mros2_sub_twist app in mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) .

8.以下のようなログが確認できたら通信成功！

  If you get logs below, which means success!!

```
publishing Twist msg!!
publishing Twist msg!!
...

```