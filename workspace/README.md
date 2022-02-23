# Example applications for mros2-asp3-f767zi

This repository contains example applications for mros2-asp3-f767zi (mROS 2 with TOPPERS/ASP3 kernel).

## Selecting the application

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
