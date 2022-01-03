#include "../../mros2_msgs/nav_msgs/msg/odometry.hpp"
#include "../../mros2_msgs/geometry_msgs/msg/twist.hpp"
#include "../../mros2_msgs/mix_msgs/msg/mix.hpp"
#include "../../mros2_msgs/health_msgs/msg/health.hpp"
#include "../../mros2_msgs/sensor_msgs/msg/joint_state.hpp"

template mros2::Publisher mros2::Node::create_publisher<nav_msgs::msg::Odometry>(std::string topic_name, int qos);
template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(nav_msgs::msg::Odometry*));
template void mros2::Publisher::publish(nav_msgs::msg::Odometry &msg);
template void mros2::Subscriber::callback_handler<nav_msgs::msg::Odometry>(void *callee, const rtps::ReaderCacheChange &cacheChange);

template mros2::Publisher mros2::Node::create_publisher<geometry_msgs::msg::Twist>(std::string topic_name, int qos);
template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(geometry_msgs::msg::Twist*));
template void mros2::Publisher::publish(geometry_msgs::msg::Twist &msg);
template void mros2::Subscriber::callback_handler<geometry_msgs::msg::Twist>(void *callee, const rtps::ReaderCacheChange &cacheChange);

template mros2::Publisher mros2::Node::create_publisher<mix_msgs::msg::Mix>(std::string topic_name, int qos);
template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(mix_msgs::msg::Mix*));
template void mros2::Publisher::publish(mix_msgs::msg::Mix &msg);
template void mros2::Subscriber::callback_handler<mix_msgs::msg::Mix>(void *callee, const rtps::ReaderCacheChange &cacheChange);

template mros2::Publisher mros2::Node::create_publisher<health_msgs::msg::Health>(std::string topic_name, int qos);
template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(health_msgs::msg::Health*));
template void mros2::Publisher::publish(health_msgs::msg::Health &msg);
template void mros2::Subscriber::callback_handler<health_msgs::msg::Health>(void *callee, const rtps::ReaderCacheChange &cacheChange);

template mros2::Publisher mros2::Node::create_publisher<sensor_msgs::msg::JointState>(std::string topic_name, int qos);
template mros2::Subscriber mros2::Node::create_subscription(std::string topic_name, int qos, void (*fp)(sensor_msgs::msg::JointState*));
template void mros2::Publisher::publish(sensor_msgs::msg::JointState &msg);
template void mros2::Subscriber::callback_handler<sensor_msgs::msg::JointState>(void *callee, const rtps::ReaderCacheChange &cacheChange);