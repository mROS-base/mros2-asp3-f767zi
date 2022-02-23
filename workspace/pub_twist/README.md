# pub_twist

This is a sample application to publish `Twist` message.

The mROS 2 node on the embedded board publishes `Twist` (`geometry_msgs::msg::Twist`) message to `cmd_vel` topic.

## Generate header files for Twist

See detail in [<repo_root>/README.md#generating-header-files-for-custom-msgtypes](../README.md#generating-header-files-for-custom-msgtypes)).

## Build and Run for embedded devices

Make sure to set `app=pub_twist` as `make` option.

```
$ pwd
<snip.>/mros2-asp3-f767zi/workspace
$ make app=pub_twist
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
$ ros2 launch mros2_sub_twist sub.launch.py
### or:
$ ros2 run mros2_sub_twist sub_node
```

## Expected output

### serial console for the baord with mros2

```
$ picocom -b 115200 /dev/ttyACM0
<snip.>
publishing Twist msg!!
publishing Twist msg!!
publishing Twist msg!!
publishing Twist msg!!
<cont.>
```

Note that this app only prints about publications since printing float32 value on STM32 is quiet hard.

### terminal console on the host

```
$ ros2 launch mros2_sub_twist sub.launch.py
<snip.>
[sub_node-1] [INFO] [1645586976.508508456] [sub_twist]: Subscribed msg: { linear: { x: 1.000000, y: 1.000000, z: 1.000000 }, angular: { x: 1.000000, y: 1.000000, z: 1.000000 } }
[sub_node-1] [INFO] [1645586977.517233571] [sub_twist]: Subscribed msg: { linear: { x: 2.000000, y: 2.000000, z: 2.000000 }, angular: { x: 2.000000, y: 2.000000, z: 2.000000 } }
[sub_node-1] [INFO] [1645586978.526933276] [sub_twist]: Subscribed msg: { linear: { x: 3.000000, y: 3.000000, z: 3.000000 }, angular: { x: 3.000000, y: 3.000000, z: 3.000000 } }
[sub_node-1] [INFO] [1645586979.535760548] [sub_twist]: Subscribed msg: { linear: { x: 4.000000, y: 4.000000, z: 4.000000 }, angular: { x: 4.000000, y: 4.000000, z: 4.000000 } }
<cont.>
```
