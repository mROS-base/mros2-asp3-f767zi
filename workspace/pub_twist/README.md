# pub_twist

This is a sample application to publish `Twist` (`geometry_msgs::msg::Twist`) message.
Please follow the steps below.

1.Since `Twist` type is not built-in type, you need to prepare the `Twist` type definition file. Note that `Twist` typw has `Vector3` (`geometry_msgs::msg::Vector3`) type in it, which is not built-in type, so you need to prepare the `Vector3` type definition file as well.

  `Vector3.msg`
  ```
  float64 x
  float64 y
  float64 z
  ```

  `Twist.msg`
  ```
  geometry_msgs/msg/Vector3 linear
  geometry_msgs/msg/Vector3 angular
  ```
  
2.Make `geometry_msgs/msg` directory under `custom_msgs` directory, then set these definition files.

3.Make `msg_settings.json` under `geometry_msgs` directory.
  Then set all paths to each definition files you use in this app at `pubsubMsgs`'s value shown as below.
  Note that `Twist` message is to be published and `Twist` type has `Vector3` type, but you don't have to include path to `Vector3` definition file.

  ```
  {
      "pubsubMsgs": [
      "geometry_msgs/msg/Twist.msg"
    ]
  }
  ```

4.Execute `make gen-msg msg=geometry_msgs` in `workspace` direcroty, then `vector3.hpp` and `twist.hpp` will be generated in `{root}/mros2_msgs/geometry_msgs/msg` directory.

5.Execute `make app=pub_twist` in `workspace` direcroty, then this app will be built.
  
6.Open serial console (ex. picocom) and initialize your micro computer board.

7.On the host device to communicate with, run `mros2_sub_twist` app (https://github.com/mROS-base/mros2-host-examples) .

8.If you get logs below, which means success!!

```
publishing Twist msg!!
publishing Twist msg!!
...

```