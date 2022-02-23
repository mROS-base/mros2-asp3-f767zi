# sub_uint16

This is a sample application to subscribe `uint16` message.

The mROS 2 node on the embedded board subscribes `uint16` (`std_msgs::msg::UInt16`) message from `/to_stm` topic.

## Build and Run for embedded devices

Make sure to set `app=sub_uint16` as `make` option.

```
$ pwd
<snip.>/mros2-asp3-f767zi/workspace
$ make app=sub_uint16
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
$ ros2 launch mros2_pub_uint16 pub.launch.py
### or:
$ ros2 run mros2_pub_uint16 pub_node
```

## Expected output

### serial console for the baord with mros2

```
$ picocom -b 115200 /dev/ttyACM0
<snip.>
subscribed msg: '0'
subscribed msg: '1'
subscribed msg: '2'
subscribed msg: '3'
<cont.>
```

### terminal console on the host

```
$ ros2 launch mros2_pub_uint16 pub.launch.py
<snip.>
[pub_node-1] [INFO] [1645586366.041203916] [pub_mros2]: Publishing msg: '0'
[pub_node-1] [INFO] [1645586367.041239322] [pub_mros2]: Publishing msg: '1'
[pub_node-1] [INFO] [1645586368.041342645] [pub_mros2]: Publishing msg: '2'
[pub_node-1] [INFO] [1645586369.041329532] [pub_mros2]: Publishing msg: '3'
<cont.>
```
