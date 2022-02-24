
#include "sensor_msgs/msg/joint_state.hpp"


template mros2::Publisher mros2::Node::create_publisher<sensor_msgs::msg::JointState>(std::string topic_name, int qos);
template void mros2::Publisher::publish(sensor_msgs::msg::JointState &msg);



template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(sensor_msgs::msg::JointState*));
template void mros2::Subscriber::callback_handler<sensor_msgs::msg::JointState>(void *callee, const rtps::ReaderCacheChange &cacheChange);
