
#include "nav_msgs/msg/odometry.hpp"


template mros2::Publisher mros2::Node::create_publisher<nav_msgs::msg::Odometry>(std::string topic_name, int qos);
template void mros2::Publisher::publish(nav_msgs::msg::Odometry &msg);



template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(nav_msgs::msg::Odometry*));
template void mros2::Subscriber::callback_handler<nav_msgs::msg::Odometry>(void *callee, const rtps::ReaderCacheChange &cacheChange);
