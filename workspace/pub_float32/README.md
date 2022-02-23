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
publishing float msg!!
publishing float msg!!
publishing float msg!!
<cont.>
```

Note that this app only prints about publications since printing float32 value on STM32 is quiet hard.

### terminal console on the host

```
$ ros2 launch mros2_sub_float32 sub.launch.py
<snip.>
[sub_node-1] [INFO] [1645586016.473060439] [sub_mros2]: Subscribed msg: '3.0000'
[sub_node-1] [INFO] [1645586017.482224733] [sub_mros2]: Subscribed msg: '4.0000'
[sub_node-1] [INFO] [1645586018.491512349] [sub_mros2]: Subscribed msg: '5.0000'
[sub_node-1] [INFO] [1645586019.500728573] [sub_mros2]: Subscribed msg: '6.0000'
<cont.>
```
