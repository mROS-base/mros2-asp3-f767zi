# sub_pose

This is a sample application to subscribe `Pose` (`geometry_msgs::msg::Pose`) message.
Please follow the steps below.

1.Since `Pose` type is not built-in type, you need to prepare the `Pose` type definition file. Note that `Pose` type has `Point` type and `Quaternion` type in it, which are not built-in type, so you need to prepare the `Point` type and `Quaternion` type definition file.

  `Point.msg`
  ```
  float64 x
  float64 y
  float64 z
  ```

  `Quaternion.msg`
  ```
  float64 x
  float64 y
  float64 z
  float64 w
  ```

  `Pose.msg`
  ```
  geometry_msgs/msg/Point position
  geometry_msgs/msg/Quaternion orientation
  ```
  
2.Make `geometry_msgs/msg` directory under `custom_msgs` directory, then set these definition files.

3.Make `msg_settings.json` under `geometry_msgs` directory.
  Then set all paths to each definition files you use in this app at `pubsubMsgs`'s value shown as below.
  Note that `Pose` message is to be published and `Pose` type has `Point` type and `Quaternion` type, but you don't have to include path to ``Point` and `Quaternion` definition file.

  ```
  {
      "pubsubMsgs": [
      "geometry_msgs/msg/Pose.msg"
    ]
  }
  ```
  

4.Execute `make gen-msg msg=geometry_msgs` in `workspace` direcroty, then `point.hpp`, `quaternion.hpp` and `pose.hpp` will be generated in `{root}/mros2_msgs/geometry_msgs/msg` directory.

5.Execute `make app=sub_pose` in `workspace` direcroty, then this app will be built.
  
6.Open serial console (ex. picocom) and initialize your micro computer board.

7.On the host device to communicate with, run mros2_pub_pose app (https://github.com/mROS-base/mros2-host-examples) .

8.If you get logs below, which means success!!

```
subscribed Pose msg!!
subscribed Pose msg!!
...

```