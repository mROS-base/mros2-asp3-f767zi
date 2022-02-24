# eval_string

This is an application for the evaluation of pub/sub `u_int16` message.

The mROS 2 node on the embedded board subscribes `u_int16` (`std_msgs::msg::UInt16`) message from `/to_stm` topic.
And then publishes this `u_int16` message as it is to `/to_linux` as the reply.
