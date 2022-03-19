# mturtle_teleop

This is a sample application along with [turtlesim](https://github.com/mROS-base/ros_tutorials/tree/mros2/foxy-devel/turtlesim) (mros2 version).

The mROS 2 node on the embedded board publishes `Twist` (`geometry_msgs::msg::Twist`) message to `/turtle1/cmd_vel` topic, according to the input from keyboard via serial console.

## Generate header files for Twist

See detail in [<repo_root>/README.md#generating-header-files-for-custom-msgtypes](../README.md#generating-header-files-for-custom-msgtypes).

## Build and Run for embedded devices

Make sure to set `app=mturtle_teleop` as `make` option.

```
$ pwd
<snip.>/mros2-asp3-f767zi/workspace
$ make app=mturtle_teleop
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

Since the current version of does not support the QoS control, the original version of `turtlesim` could not work well with this application. So please use the following repository (that is customized for mros2) to clone repository and build package.

```
$ cd <your_ros2_ws>/src
$ git clone -b mros2/foxy-devel https://github.com/mROS-base/ros_tutorials
$ cd ..
$ colcon build --packages-select turtlesim
$ source install/local_setup.bash
```

## Expected output

### serial console for the baord with mros2

```
$ picocom -b 115200 /dev/ttyACM0
<snip.>
ready to pub/sub message
keymap to move arround:
------------------
   u    i    o
   j    k    l
   m    ,    .
------------------
q/z : increase/decrease max speeds by 10 percent
w/x : increase/decrease only linear speed by 10 percent
e/c : increase/decrease only angular speed by 10 percent
currently: speed 0.5000 / turn 1.0000

[MROS2LIB] Initilizing Domain complete
[MROS2LIB] publisher matched with remote subscriber
publishing Twist msg by 'u' command
publishing Twist msg by 'u' command
publishing Twist msg by 'u' command
<cont.>
```

### terminal console on the host

```
$ ros2 run turtlesim turtlesim_node
<snip.>
[INFO] [1647589190.956007464] [turtlesim]: Starting turtlesim with node name /turtlesim
[INFO] [1647589190.957948401] [turtlesim]: Spawning turtle [turtle1] at x=[5.544445], y=[5.544445], theta=[0.000000]
[INFO] [1647589195.831260526] [turtlesim]: subscribed Twist msg from mros2
[INFO] [1647589196.422450459] [turtlesim]: subscribed Twist msg from mros2
[INFO] [1647589196.934933835] [turtlesim]: subscribed Twist msg from mros2
<cont.>
```
