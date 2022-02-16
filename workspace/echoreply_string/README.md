### echoreply_string app

This is a sample application for string-type communication.
Please follow the steps below.

1.Execute `make app=echoreply_string` in workspace direcroty, then this app will be built.

2.Open serial console (ex. picocom) and initialize your micro computer board.

3.On the host device to communicate with, run mros2_echoback_string app in mros2-host-examples (https://github.com/mROS-base/mros2-host-examples) .

4.If you get logs below, which means success!!

```
Subscribed msg : Hello, world! 1
Publishing msg : Hello, world! 1
Subscribed msg : Hello, world! 2
Publishing msg : Hello, world! 2
Subscribed msg : Hello, world! 3
Publishing msg : Hello, world! 3
Subscribed msg : Hello, world! 4
Publishing msg : Hello, world! 4
...
```
