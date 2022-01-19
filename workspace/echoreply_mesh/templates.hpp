
#include "shape_msgs/msg/mesh.hpp"


template mros2::Publisher mros2::Node::create_publisher<shape_msgs::msg::Mesh>(std::string topic_name, int qos);
template void mros2::Publisher::publish(shape_msgs::msg::Mesh &msg);



template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(shape_msgs::msg::Mesh*));
template void mros2::Subscriber::callback_handler<shape_msgs::msg::Mesh>(void *callee, const rtps::ReaderCacheChange &cacheChange);
