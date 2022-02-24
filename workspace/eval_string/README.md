# eval_string

This is an application for the evaluation of pub/sub `string` message.

The mROS 2 node on the embedded board subscribes `string` (`std_msgs::msg::String`) message from `/to_stm` topic.
And then publishes this `string` message as it is to `/to_linux` as the reply.
