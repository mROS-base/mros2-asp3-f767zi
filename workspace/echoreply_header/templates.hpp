
#include "std_msgs/msg/header.hpp"


template mros2::Publisher mros2::Node::create_publisher<std_msgs::msg::Header>(std::string topic_name, int qos);
template void mros2::Publisher::publish(std_msgs::msg::Header &msg);



template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(std_msgs::msg::Header*));
template void mros2::Subscriber::callback_handler<std_msgs::msg::Header>(void *callee, const rtps::ReaderCacheChange &cacheChange);
