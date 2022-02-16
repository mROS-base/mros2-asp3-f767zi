# pub_float32

This is a sample application to publish `float32` (`std_msgs::msg::Float32`) message.
Please follow the steps below.

1.Execute `make app=pub_float32` in `workspace` direcroty, then this app will be built.

2.Open serial console (ex. picocom) and initialize your micro computer board.

3.On the host device to communicate with, run `mros2_sub_float32` app (https://github.com/mROS-base/mros2-host-examples) .

4.If you get logs below, which means success!!
```
publishing float msg!!
publishing float msg!!
...

```
