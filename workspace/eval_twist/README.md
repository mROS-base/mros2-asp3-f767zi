# eval_string

This is an application for the evaluation of pub/sub `Twist` message.

The mROS 2 node on the embedded board subscribes `Twist` (`geometry_msgs::msg::Twisit`) message from `/to_stm` topic.
And then publishes this `Twist` message as it is to `/to_linux` as the reply.
