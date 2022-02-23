# echoreply_string

This is a sample application to publish and subscribe `string` message.

The mROS 2 node on the embedded board subscribes `string` (`std_msgs::msg::String`) message from `/to_stm` topic.
And then publishes this `string` message as it is to `/to_linux` as the reply.

## Build and Run for embedded devices

Make sure to set `app=echoreply_string` as `make` option.

```
$ pwd
<snip.>/mros2-asp3-f767zi/workspace
$ make app=echoreply_string
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
$ ros2 launch mros2_echoback_string pubsub.launch.py
### or, at two terminals:
### terminal A
$ ros2 run mros2_echoback_string sub_node
### terminal B
$ ros2 run mros2_echoback_string pub_node
```

## Expected output

### serial console for the baord with mros2

```
$ picocom -b 115200 /dev/ttyACM0
<snip.>
Subscribed msg : Hello, world! 0
Publishing msg : Hello, world! 0
Subscribed msg : Hello, world! 1
Publishing msg : Hello, world! 1
Subscribed msg : Hello, world! 2
Publishing msg : Hello, world! 2
Subscribed msg : Hello, world! 3
Publishing msg : Hello, world! 3
<cont.>
```

### terminal console on the host

```
$ ros2 launch mros2_echoback_string pubsub.launch.py
<snip.>
[pub_node-1] [INFO] [1645585644.001564405] [pub_mros2]: Publishing msg: 'Hello, world! 0'
[sub_node-2] [INFO] [1645585644.002840991] [mros2_sub]: Subscribed msg: 'Hello, world! 0'
[pub_node-1] [INFO] [1645585645.001545502] [pub_mros2]: Publishing msg: 'Hello, world! 1'
[sub_node-2] [INFO] [1645585645.002778974] [mros2_sub]: Subscribed msg: 'Hello, world! 1'
[pub_node-1] [INFO] [1645585646.001554828] [pub_mros2]: Publishing msg: 'Hello, world! 2'
[sub_node-2] [INFO] [1645585646.002939830] [mros2_sub]: Subscribed msg: 'Hello, world! 2'
[pub_node-1] [INFO] [1645585647.001583001] [pub_mros2]: Publishing msg: 'Hello, world! 3'
[sub_node-2] [INFO] [1645585647.002903072] [mros2_sub]: Subscribed msg: 'Hello, world! 3'
<cont.>
```
