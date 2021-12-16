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

## echoreply_uint16

- Description:
  - The mROS 2 node on the embedded board subscribes `uint16` (`std_msgs::msg::UInt16`) message from `/to_stm` topic.
  - And then publishes this `uint16` message as it is to `/to_linux` as the reply.
- Host operation:
  - `$ ros2 launch mros2_echoback_uint16 launch.py`
  - or, at two terminals:
    - `$ ros2 run mros2_echoback_uint16 pub_node`
    - `$ ros2 run mros2_echoback_uint16 sub_node`

## echoreply_float32

- Description:
  - The mROS 2 node on the embedded board subscribes `float32` (`std_msgs::msg::Float32`) message from `/to_stm` topic.
  - And then publishes this `float32` message as it is to `/to_linux` as the reply.
    - Note that this application just print whether the value of message is between 5.0 and 10.0 or not, since TOPPERS/ASP3 kernel cannot print float value.
- Host operation:
  - `$ ros2 launch mros2_echoback_float32 launch.py`
  - or, at two terminals:
    - `$ ros2 run mros2_echoback_float32 pub_node`
    - `$ ros2 run mros2_echoback_float32 sub_node`

## pub_string

- Description:
  - The mROS 2 node on the embedded board says hello to `/to_linux` as the publication message of `string`.
- Host operation:
  - `$ ros2 run mros2_echoback_string pub_node`

## sub_string

- Description:
  - The mROS 2 node on the embedded board just subscribes `string` message from `/to_stm` topic.
- Host operation:
  - `$ ros2 run mros2_echoback_string sub_node`
