# sub_uint16

This is a sample application to subscribe `uint16` (`std_msgs::msg::Uint16`) message.
Please follow the steps below.

1.Execute `make app=sub_uint16` in `workspace` direcroty, then this app will be built.

2.Open serial console (ex. picocom) and initialize your micro computer board.

3.On the host device to communicate with, run `mros2_pub_uint16` app (https://github.com/mROS-base/mros2-host-examples) .

4.If you get logs below, which means success!!

```
Subscribed msg : 1
Publishing msg : 1
Subscribed msg : 2
Publishing msg : 2
Subscribed msg : 3
Publishing msg : 3
Subscribed msg : 4
Publishing msg : 4
...
```
