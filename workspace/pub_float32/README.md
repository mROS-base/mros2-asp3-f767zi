# pub_float32

This is a sample application to publish `float32` message.

The mROS 2 node on the embedded board publishes `float32` (`std_msgs::msg::Float32`) message to `/to_linux` topic.

## Build and Run for embedded devices

Make sure to set `app=pub_float32` as `make` option.

```
$ pwd
<snip.>/mros2-asp3-f767zi/workspace
$ make app=pub_float32
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
$ ros2 launch mros2_sub_float32 sub.launch.py
### or:
$ ros2 run mros2_sub_float32 sub_node
```

## Expected output

### serial console for the baord with mros2

```
$ picocom -b 115200 /dev/ttyACM0
<snip.>
publishing float msg!!
msg <= 0.0
publishing float msg!!
msg <= 0.0
publishing float msg!!
0.0 < msg < 0.5
publishing float msg!!
0.0 < msg < 0.5
<cont.>
```

Note that this app only prints about publications since printing float32 value on STM32 is quiet hard.

### terminal console on the host

```
$ ros2 launch mros2_sub_float32 sub.launch.py
<snip.>
[sub_node-1] [INFO] [1645679842.497824017] [sub_mros2]: Subscribed msg: '-0.1000'
[sub_node-1] [INFO] [1645679843.507012242] [sub_mros2]: Subscribed msg: '-0.0000'
[sub_node-1] [INFO] [1645679844.516442044] [sub_mros2]: Subscribed msg: '0.1000'
[sub_node-1] [INFO] [1645679845.525575190] [sub_mros2]: Subscribed msg: '0.2000'
<cont.>
```
