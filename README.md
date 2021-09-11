# mros2-asp3-f767zi

mROS 2 (formly `mros2`) is a agent-less and lightweight runtime environment ROS 2 for embedded devices.
mROS 2 mainly offers pub/sub APIs compatible with [rclcpp](https://docs.ros2.org/dashing/api/rclcpp/index.html) for embedded devices. 

This repository contains the reference implementation of mROS 2 that can be operated on the embedded board. Please also check [mros2 repository](https://github.com/mROS-base/mros2) for more details and another implementations.

## Supported environment

- Embedded device
  - Board: [STM32 NUCLEO-F767ZI](https://www.st.com/en/evaluation-tools/nucleo-f767zi.html)
  - Kernel: [TOPPERS/ASP3](https://www.toppers.jp/en/project.html)
- Host environment
  - Ubuntu 18.04 LTS
  - [ROS 2 Dashing Diademata](https://docs.ros.org/en/dashing/index.html)

## Envorinmental setup

1. Install [ROS 2 Dashing Diademata](https://docs.ros.org/en/dashing/installation.html) on the host with Ubuntu 18.04 LTS.
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

## Usage

### Build for mROS 2 app

First of all, clone this repository. Note that **--recursive** is mandatory.

```
$ git clone --recursive https://github.com/mROS-base/mros2-asp3-f767zi
```

Move to workspace and operate `make` with the target app name.

```
$ cd mros2-asp3-f767zi
$ cd workspace
$ make clean
$ make app=echoreply_string
```

Once build process can be completed, you can find `asp.bin` and `asp.elf` as the binary. Please copy the binary to the board for the deployment.

```
$ ls
asp.bin  asp.elf  build  echoreply_string  Makefile

$ cp asp.bin /media/$USER/NODE_F767ZI/
```

### Build for the host nodes

We also provide the implemenation of ROS 2 nodes that communicate to the embedded device. Clone the repository and build in _<your_ros2_ws>_.

```
$ cd <your_ros2_ws>/src
$ git clone https://github.com/mROS-base/mros2-host-examples

$ cd <your_ros2_ws>
$ colcon build
$ source install/local_setup.bash
```

## Run the example

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
create_node
start creating participant
mROS2 init start
successfully created participant
create subscription complete. data memory address=0x2001aae8
mROS2 init complete
```
  
2. Launch ROS 2 nodes on the host on another terminal.
```
$ cd <your_ros2_ws>
$ source install/local_setup.bash
$ ros2 launch mros2_echoback launch_pubsub.py 
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

## Example application

- echoback_reply
  - The mROS 2 node on the embedded board subscribes `std_msgs::msg::String` message from `/to_stm` topic, and then publishes this message to `/to_linux` as the reply.
  - This app runs with [mros2-host-examples/mros2_echoback](https://github.com/mROS-base/mros2-host-examples/tree/main/mros2_echoback) package on the host.

## Tips: Developing with VS Code

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

## Submodules and Licenses

The source code of this repository itself is published under [Apache License 2.0](https://github.com/mROS-base/mros2/blob/main/LICENSE).  
Please note that this repository contains the following stacks as the submodules, and also check their Licenses.

- [mros2](https://github.com/mROS-base/mros2): the pub/sub APIs compatible with ROS 2 Rclcpp
  - [embeddedRTPS](https://github.com/mROS-base/embeddedRTPS): RTPS communication layer (including lwIP and Micro-CDR)
- [asp3-f767zi](https://github.com/mROS-base/asp3-f767zi): TOPPERS/ASP3 kernel for STM32 NUCLEO-F767ZI
- [cmsis-asp3](https://github.com/mROS-base/cmsis-asp3): interface layer between CMSIS OS API and TOPPERS kernel
- [STM32CubeF7](https://github.com/mROS-base/STM32CubeF7): STM32Cube MCU package for the STM32F7 series
