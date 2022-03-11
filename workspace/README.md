# Example applications for mros2-asp3-f767zi

This repository contains example applications for mros2-asp3-f767zi (mROS 2 with TOPPERS/ASP3 kernel).

## Selection of the application to build

You can select the application to be built with `make` option.

```
$ make app=echoreply_string
# or
$ make app=pub_float32
```

## List of applications (directories)

- [echoreply_string](echoreply_string/)
- [pub_float32](pub_float32/)
- [sub_uint16](sub_uint16/)
- [pub_twist](pub_twist/)
- [sub_pose](sub_pose/)
- [custom_msgs/](custom_msgs/): definition and header files for custom MsgTypes (see [detail](../README.md#generating-header-files-for-custom-msgtypes))

## Corresponding examples on the host

We also provide the implemenation of ROS 2 nodes on the host, that communicate to the embedded device. 
Please also check [mROS-base/mros2-host-examples](https://github.com/mROS-base/mros2-host-examples) repository for more details about corresponding example ROS 2 packages on the host.

## Files for the application

On this platform, the mros2 application consists of the following files:

- app.cpp: 
  - main source of the application
  - note that the file name must be this in order to generate the templates of pub/sub functions in the build step.
- app.h: 
  - header file of the application
  - some definitions for the configuration of TOPPERS/ASP3 kernel and its tasks
- templates.hpp:
  - the templates of pub/sub functions
  - this file will be automatically generated/modified during the build step, so you do not have to care about this file
- Makefile.inc: the definication of make for mros2 application
- app.cfg: system configuration file for TOPPERS/ASP3 kernel
- app.cdl: description of TECS components for TOPPERS/ASP3 kernel
- task_impl.[c,h]: the definition of the wrapper for CMSIS layer
- config/: the configuration of the wrapper for CMSIS layer

You may warry these many files about the settings. 
However, roughly speaking, just you need to do is to copy the existing directory and edit app.cpp to create a new application.
