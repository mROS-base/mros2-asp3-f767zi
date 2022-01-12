
#include "mix_msgs/msg/mix.hpp"


template mros2::Publisher mros2::Node::create_publisher<mix_msgs::msg::Mix>(std::string topic_name, int qos);
template void mros2::Publisher::publish(mix_msgs::msg::Mix &msg);



template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(mix_msgs::msg::Mix*));
template void mros2::Subscriber::callback_handler<mix_msgs::msg::Mix>(void *callee, const rtps::ReaderCacheChange &cacheChange);
