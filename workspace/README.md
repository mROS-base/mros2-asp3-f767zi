# Example applications for mros2-asp3-f767zi

This repository contains example applications for mros2-asp3-f767zi (mROS 2 with TOPPERS/ASP3 kernel).

We also provide the implemenation of ROS 2 nodes on the host, that communicate to the embedded device. 
Please also check [mROS-base/mros2-host-examples](https://github.com/mROS-base/mros2-host-examples) repository for more details.

## echoreply_string

- Description:
  - The mROS 2 node on the embedded board subscribes `string` (`std_msgs::msg::String`) message from `/to_stm` topic.
  - And then publishes this `string` message as it is to `/to_linux` as the reply.
- Host operation:
  - `$ ros2 launch mros2_echoback_string launch.py`
  - or, at two terminals:
    - `$ ros2 run mros2_echoback_string pub_node`
    - `$ ros2 run mros2_echoback_string sub_node`

## sub_uint16

- Description:
  - The mROS 2 node on the embedded board subscribes `uint16` (`std_msgs::msg::UInt16`) message from `/to_stm` topic.
  - `$ ros2 launch mros2_pub_uint16 launch.py`
  - or, at two terminals:
    - `$ ros2 run mros2_pub_uint16 pub_node`

## pub_float32

- Description:
  - The mROS 2 node on the embedded board publishes `float32` (`std_msgs::msg::Float32`) message to `/to_linux` topic.
- Host operation:
  - `$ ros2 launch mros2_sub_float32 launch.py`
  - or, at two terminals:
    - `$ ros2 run mros2_sub_float32 sub_node`

## sub_pose

- Description:
  - The mROS 2 node on the embedded board subscribes `Pose` (`geometry_msgs::msg::Pose`) message from `cmd_vel` topic.
  - `$ ros2 launch mros2_pub_pose launch.py`
  - or, at two terminals:
    - `$ ros2 run mros2_pub_pose pub_node`

## pub_twist

- Description:
  - The mROS 2 node on the embedded board publishes `Twist` (`geometry_msgs::msg::Twist`) message to `cmd_vel` topic.
- Host operation:
  - `$ ros2 launch mros2_sub_twist launch.py`
  - or, at two terminals:
    - `$ ros2 run mros2_sub_twist sub_node`
