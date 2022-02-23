# sub_pose

This is a sample application to subscribe `Pose` message.

The mROS 2 node on the embedded board subscribes `Pose` (`geometry_msgs::msg::Pose`) message from `cmd_vel` topic.

## Generate header files for Twist

Create `Pose.msg`, `Point.msg` and `Quartenion.msg` in `workspace/custom_msgs/geometry_msgs/msg/`.

```
$ pwd
<snip.>/mros2-asp3-f767zi/workspace
$ cat custom_msgs/geometry_msgs/msg/Pose.msg
geometry_msgs/msg/Point position
geometry_msgs/msg/Quaternion orientation
$ cat custom_msgs/geometry_msgs/msg/Point.msg
float64 x
float64 y
float64 z
$ cat custom_msgs/geometry_msgs/msg/Quaternion.msg
float64 x
float64 y
float64 z
float64 w
```

Edit `msg_settings.json` file under `workspace/custom_msgs/geometry_msgs/` directory as the follow.

```
$ cat workspace/custom_msgs/geometry_msgs/msg_settings.json
{
    "pubsubMsgs": [
        "geometry_msgs/msg/Pose.msg"
    ]
}
```

Do `make gen-msg msg=geometry_msgs` in `workspace/`.

```
$ make gen-msg msg=geometry_msgs
msg file for geometry_msgs generated in custom_msgs/geometry_msgs
```

See detail in [<repo_root>/README.md#generating-header-files-for-custom-msgtypes](../README.md#generating-header-files-for-custom-msgtypes)).

## Build and Run for embedded devices

Make sure to set `app=sub_pose` as `make` option.

```
$ pwd
<snip.>/mros2-asp3-f767zi/workspace
$ make app=sub_pose
<snip.>
configuration check passed
make[2]: Leaving directory '/home/takase/ros/mROS2/github/mros2-asp3-f767zi/workspace/build'
make[1]: Leaving directory '/home/takase/ros/mROS2/github/mros2-asp3-f767zi/workspace/build'
Build complete successfully
Copying binary to the board...

### The above message is appeared if the board is already connected to host PC.
### If not, please connect the board and copy the binary manually.
$ cp asp.bin /media/$USER/NODE_F767ZI/
```

## Host operation for native ROS 2

```
$ ros2 launch mros2_pub_pose pub.launch.py
### or:
$ ros2 run mros2_pub_pose pub_node
```

## Expected output

### serial console for the baord with mros2

```
$ picocom -b 115200 /dev/ttyACM0
<snip.>
subscribed Pose msg!!
subscribed Pose msg!!
subscribed Pose msg!!
subscribed Pose msg!!
<cont.>
```

Note that this app only prints about subscriptions since printing float32 value on STM32 is quiet hard.

### terminal console on the host

```
$ ros2 launch mros2_pub_pose pub.launch.py
<snip.>
[pub_node-1] [INFO] [1645587255.175263265] [pub_pose]: Publishing msg: { position: {x: 0.000000, y: 0.000000, z: 0.000000 }, orientation: {x: 0.000000, y: 0.000000, z: 0.000000, w: 0.000000 } }
[pub_node-1] [INFO] [1645587256.175270664] [pub_pose]: Publishing msg: { position: {x: 1.000000, y: 1.000000, z: 1.000000 }, orientation: {x: 1.000000, y: 1.000000, z: 1.000000, w: 1.000000 } }
[pub_node-1] [INFO] [1645587257.175274484] [pub_pose]: Publishing msg: { position: {x: 2.000000, y: 2.000000, z: 2.000000 }, orientation: {x: 2.000000, y: 2.000000, z: 2.000000, w: 2.000000 } }
[pub_node-1] [INFO] [1645587258.175291449] [pub_pose]: Publishing msg: { position: {x: 3.000000, y: 3.000000, z: 3.000000 }, orientation: {x: 3.000000, y: 3.000000, z: 3.000000, w: 3.000000 } }
<cont.>
```
