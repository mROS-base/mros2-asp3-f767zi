# mros2-asp3-f767zi

mROS 2 (formly `mros2`) realizes a agent-less and lightweight runtime environment compatible with ROS 2 for embedded devices.
mROS 2 mainly offers pub/sub APIs compatible with [rclcpp](https://docs.ros2.org/dashing/api/rclcpp/index.html) for embedded devices. 

mROS 2 consists of communication library for pub/sub APIs, RTPS protocol, UDP/IP stack, and real-time kernel.
This repository provides the reference implementation of mROS 2 that can be operated on the embedded board. 
Please also check [mros2 repository](https://github.com/mROS-base/mros2) for more details and another implementations.

## Supported environment

- Embedded device
  - Board: [STM32 NUCLEO-F767ZI](https://www.st.com/en/evaluation-tools/nucleo-f767zi.html)
  - Kernel: [TOPPERS/ASP3](https://www.toppers.jp/en/project.html)
- Host environment
  - [ROS 2 Foxy Fitzroy](https://docs.ros.org/en/foxy/index.html) on Ubuntu 20.04 LTS
  - [ROS 2 Dashing Diademata](https://docs.ros.org/en/dashing/index.html) on Ubuntu 18.04 LTS

## Envorinmental setup

1. Install [ROS 2 Foxy Fitzroy](https://docs.ros.org/en/foxy/installation.html) on the host with Ubuntu 20.04 LTS.
    - You can also use Docker as the host environment instead. Please check "Tips 1" section.
1. Install arm-none-eabi v7.3.1.
    - There are two ways to install the appropriate version.
      1. Download and unzip the prebuilt archive of GNU Arm Embedded Toolchain from [official Arm website](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads). Please select **"GNU Arm Embedded Toolchain: 7-2018-q2-update June 27, 2018"** and "Linux 64-bit" as the archive.  
      Then, unzip the downloaded archive to any location (`/usr/local/` is recommended) and set _<unzipped_dir>/bin_ to `$PATH`.
      1. Install [STM32CubeIDE v1.5.0](https://www.st.com/en/development-tools/stm32cubeide.html#overview&secondary=st-get-software). It contains v7.3.1 cross-compiler.
      If you did not change the default location to be installed, `$PATH` to be set will be _/opt/st/stm32cubeide_1.5.0/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.7-2018-q2-update.linux64_1.5.0.202011040924/tools_
    - Currently, we confirmed issue that v6.3.1 (which will be installed via `apt`) cannot be operated successfully. See also [#36](https://github.com/mROS-base/mros2-asp3-f767zi/issues/36).
1. Connet the board and the host with LAN cable and micro-USB cable (CN1 connector on the board, opposite side of LAN connector). Please set the IP address and Netmask of the host to `192.168.11.3` and `255.255.255.0`, respectively.
    - You can also connect the network with the board through the router when you can set the IP and Netmask as the above.
    - The IP address of the board will be assigned to `192.168.11.2`. If you want to change the IP settings, you need to modify [src/config/lwip.c](https://github.com/mROS-base/mros2-asp3-f767zi/blob/main/src/config/lwip.c#L69-L80) and [embeddedRTPS/include/rtps/config.h](https://github.com/mROS-base/embeddedRTPS/blob/mros2/include/rtps/config.h#L37) as you want.

## Quickstart

This section explains how to build and execute mROS 2 with TOPPERS/ASP3 kernel, using `echoback_reply` application as an example.

This example only uses a built-in-type (`string` a.k.a `std_msgs::msg::String`), so you can skip the generation of header files for custom msg types. Please see [Generating header files for custom MsgTypes](#generating-header-files-for-custom-msgtypes) for more detail.

### Build for mROS 2 app

First of all, clone this repository. Note that **--recursive** is mandatory.

```
$ git clone --recursive https://github.com/mROS-base/mros2-asp3-f767zi
```

Move to workspace and operate `make` with the target app name (please see [workspace/](https://github.com/mROS-base/mros2-asp3-f767zi/tree/main/workspace) for another examples).

```
$ cd mros2-asp3-f767zi
$ cd workspace
$ make clean
$ make app=echoreply_string
```

Once build process can be completed, you can find `asp.bin` and `asp.elf` as the binary. Please copy the binary to the board for the deployment.

```
$ ls asp*
asp.bin  asp.elf

$ cp asp.bin /media/$USER/NODE_F767ZI/
```

### Build for the host nodes

We also provide the implemenation of ROS 2 nodes that communicate to the embedded device. (You can also use Docker as the host environment instead. Please check "Tips 1" section).

Clone the repository and build in _<your_ros2_ws>_.

```
$ cd <your_ros2_ws>/src
$ git clone https://github.com/mROS-base/mros2-host-examples

$ cd <your_ros2_ws>
$ colcon build --packages-select mros2_echoback_string
$ source install/local_setup.bash
```

### Run the example

1. Connect the serial port of the board with `picocom`, and then push RESET button. Please wait a while until the message "`mROS2 init complete`" is confirmed. It means that the initiation process for mROS 2 has completed successfully.
```
$ picocom -b 115200 /dev/ttyACM0
(skip)
Terminal ready

TOPPERS/ASP3 Kernel Release 3.5.0 for NUCLEO(STM32F767ZI:ARM Cortex-M7) (Aug 19 2021, 12:33:55)
Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
                            Toyohashi Univ. of Technology, JAPAN
Copyright (C) 2004-2019 by Embedded and Real-Time Systems Laboratory
            Graduate School of Information Science, Nagoya Univ., JAPAN

System logging task is started.
mROS 2 application is started
mROS 2 initialization is completed
[MROS2LIB] create_node
[MROS2LIB] start creating participant
[MROS2LIB] mros2_init task start
[MROS2LIB] Initilizing lwIP complete
[MROS2LIB] successfully created participant
[MROS2LIB] create_publisher complete.
[MROS2LIB] create_subscription complete. data memory address=0x2001d628
ready to pub/sub message
[MROS2LIB] Initilizing Domain complete
```
 
2. Launch ROS 2 nodes on the host on another terminal.
```
$ cd <your_ros2_ws>
$ source install/local_setup.bash
$ ros2 launch mros2_echoback_string pubsub.launch.py
[INFO] [launch]: Default logging verbosity is set to INFO
[INFO] [pub_node-1]: process started with pid [21232]
[INFO] [sub_node-2]: process started with pid [21233]
[pub_node-1] [INFO] [pub_mros2]: Publishing msg: 'Hello, world! 0'
[sub_node-2] [INFO] [mros2_sub]: Subscribed msg: 'Hello, world! 0'
[pub_node-1] [INFO] [pub_mros2]: Publishing msg: 'Hello, world! 1'
[sub_node-2] [INFO] [mros2_sub]: Subscribed msg: 'Hello, world! 1'
[pub_node-1] [INFO] [pub_mros2]: Publishing msg: 'Hello, world! 2'
[sub_node-2] [INFO] [mros2_sub]: Subscribed msg: 'Hello, world! 2'
[pub_node-1] [INFO] [pub_mros2]: Publishing msg: 'Hello, world! 3'
[sub_node-2] [INFO] [mros2_sub]: Subscribed msg: 'Hello, world! 3'
<cont.>
```

3. Now, you can confirm the message of the board (on `picocom` terminal) :tada:
```
<continue from 1.>
[MROS2LIB] publisher matched with remote subscriber
[MROS2LIB] subscriber matched with remote publisher
subscriber matched with remote publisher
publisher matched with remote subscriber
subscribed msg: 'Hello, world! 0'
publishing msg: 'Hello, world! 0'
subscribed msg: 'Hello, world! 1'
publishing msg: 'Hello, world! 1'
subscribed msg: 'Hello, world! 2'
publishing msg: 'Hello, world! 2'
subscribed msg: 'Hello, world! 3'
publishing msg: 'Hello, world! 3'
<cont.>
```

NOTE: due to the current implementation, the order of operation is very important.
We need to start up the mROS 2 node at first, and then operate ROS 2 nodes on the host.

## Example applications

Please see [workspace/](workspace/) for example applications.

## Generating header files for custom MsgTypes

You can use almost any [built-in-types in ROS 2](https://docs.ros.org/en/rolling/Concepts/About-ROS-Interfaces.html#field-types) on the embedded device.

In additon, you can define a customized message type (e.g., `Twist.msg`) in the same way as in ROS 2, and use its header file for your application. This section describes how to generate header files for your own MsgTypes (`geometry_msgs::msg::Twist` as an example).

### Prepare .msg files

`.msg` files are simple text files that describe the fields of a ROS message (see [About ROS 2 interface](https://docs.ros.org/en/rolling/Concepts/About-ROS-Interfaces.html)). In mros2, they are used to generate header files for messages in embedded applications.

Prepare `Twist.msg` file and make sure it is in `workspace/custom_msgs/geometry_msgs/msg/`.

```
$ cat workspace/custom_msgs/geometry_msgs/msg/Twist.msg
geometry_msgs/msg/Vector3 linear
geometry_msgs/msg/Vector3 angular
```

In this example, `Twist` has a nested structure with `Vector3` as a child element. So you also need to prepare its file.

```
$ cat workspace/custom_msgs/geometry_msgs/msg/Vector3.msg
float64 x
float64 y
float64 z
```

### Prepare msg_settings.json files

Next, create or edit `msg_settings.json` file under `workspace/custom_msgs/geometry_msgs/` directory. In general, you need to set all paths to `pubsubMsgs`'s value about each .msg files which you want to use. Note that you do not need to add additional paths in this example since `Vector3` will be located in the same hierarchy as `Twist`.

```
$ cat workspace/custom_msgs/geometry_msgs/msg_settings.json
{
    "pubsubMsgs": [
        "geometry_msgs/msg/Twist.msg"
    ]
}
```

### Generate header files

To generate header files for `Twist` and `Vector3`, do `make gen-msg msg=geometry_msgs` in `workspace/`.

```
$ cd workspace
$ make gen-msg msg=geometry_msgs
msg file for geometry_msgs generated in custom_msgs/geometry_msgs
```

Make sure header files for custom MsgType are generated in `../mros2_msgs/`

```
$ ls -R ../mros2_msgs/
../mros2_msgs/:
geometry_msgs

../mros2_msgs/geometry_msgs:
msg

../mros2_msgs/geometry_msgs/msg:
twist.hpp  vector3.hpp
```

You can now use them in your applicaton like this.

```
#include "mros2.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/twist.hpp"

int main(int argc, char * argv[])
{
<snip.>
  pub = node.create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
<snip.>
```

## Configure the network

There are two files for network configulation.

- [src/startup/include/lwipots.h](https://github.com/mROS-base/mros2-asp3-f767zi/blob/main/src/startup/include/lwipopts.h) for lwIP
- [src/config/rtps/config.h](https://github.com/mROS-base/mros2-asp3-f767zi/blob/main/src/config/rtps/config.h) for embeddedRTPS

Currently, we are unable to communicate large size of messages probably due to these configurations. We should seek the appropreate configurations or how to fit them to the demand of applications.

Please let us know about this if you have any opinions or awesome knowledges! #60 

## Tips 1: Execute host nodes with Docker environment

If you do not want to prepare ROS 2 environment on your PC, using Docker is a good alternative to check the operation of mros2 just in 5 minutes. Type the command below.

```
docker run --rm -it --net=host ros:foxy /bin/bash \
  -c "source /opt/ros/foxy/setup.bash &&
  cd &&
  git clone https://github.com/mROS-base/mros2-host-examples &&
  cd mros2-host-examples &&
  colcon build --packages-select mros2_echoback_string &&
  source install/setup.bash &&
  ros2 launch mros2_echoback_string launch_pubsub.py"
```

## Tips 2: Developing with VS Code

We offer a comfortable development environment with Visual Studio Code (VS Code). 
Building, flashing and debugging the application can be done with simple operations in one window.

### Required environment

- [Visual Studio Code](https://code.visualstudio.com/download)
- VS Code Extensions
  - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)
- OpenOCD ( `$ sudo apt install openocd` )

### Operations

- Build project for mros2 application
  - Just type `Ctrl+Shift+B` or _[Terminal] -> [Run Build Task...]_
  - The binary will be copied to the board at the final step when the board is connected to the host.
  - You can change the target application name by editing `"app=echoreply_string"` in `.vscode/tasks.json`.
- Clean project
  - _[Terminal] -> [Run Task...]_ and then select _Clean project_
- Flashing program (ELF-format) to the board
  - _[Terminal] -> [Run Task...]_ and then select _Flash program_
- Debugging
  - Just type `F5` or _[Run] -> [Start Debugging]_
  - You need to rebuild project manually before debugging when you edit code.

## Submodules and Licenses

The source code of this repository itself is published under [Apache License 2.0](https://github.com/mROS-base/mros2/blob/main/LICENSE).

Please note that this repository contains the following stacks as the submodules, and also check their Licenses.

- [mros2](https://github.com/mROS-base/mros2): the pub/sub APIs compatible with ROS 2 Rclcpp
  - [embeddedRTPS](https://github.com/mROS-base/embeddedRTPS): RTPS communication layer (including lwIP and Micro-CDR)
- [asp3-f767zi](https://github.com/mROS-base/asp3-f767zi): TOPPERS/ASP3 kernel for STM32 NUCLEO-F767ZI
- [cmsis-asp3](https://github.com/mROS-base/cmsis-asp3): interface layer between CMSIS OS API and TOPPERS kernel
- [STM32CubeF7](https://github.com/mROS-base/STM32CubeF7): STM32Cube MCU package for the STM32F7 series
