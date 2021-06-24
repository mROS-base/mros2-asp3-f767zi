# asp-stm32f767

## mROS2 echo-back app

The sample application for mROS 2.
It recieves `std_msgs::msg::String` type message from the host PC, via `to_stm` topic, and sends back the same message to the PC via `to_linux` topic.

### environment
* ROS 2 Dashing
* Ubuntu 18.04
* STM32F767ZI board

### How to use
#### Setup for PC
1. Copy the `ros2_ws` folder to the source folder of your ROS 2 workspace  
   (e.g. `~/ros2_ws/src`)
1. `colcon build` to build the applications.
2. Check that `ros2 run mros2_echoback pub_node` starts the publisher node, and `ros2 run mros2_echoback sub_node` starts the subscriber node.
3. `sudo ufw disalbe` to disable the firewall.

#### Setup for STM32
1. Open STM32CubeIDE and create new project for STM32F767ZI board and delete all the files in it.
1. Import all the folders and files except `ros2_ws` folder to the STM project
2. Press `build` button to build the project
3. Press `debug` button or `run` button to flash the binary to the STM board
4. Check the serial output (115200 baud) to make sure that the program is working properly.

#### Execute the echoback test
1. Power on the STM32 board and wait until it outputs `mROS2 init complete` message
2. Open terminal on PC, and `ros2 run mros2_echoback pub_node` to start the publisher node on the PC.
3. Check the serial output. If it works, the STM outputs the messages it recieves from the publisher node.
4. Open another terminal, and `ros2 run mros2_echoback sub_node` to start the subscriber node on the PC.
5. Check the output of the subscriber node. If it works, the node outputs the messages it recieves from the STM.
