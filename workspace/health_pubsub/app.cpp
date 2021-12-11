#include "app.h"
#include "mros2.h"
#include "health_msgs/msg/health.hpp"

#include "stm32f7xx_nucleo_144.h"

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(health_msgs::msg::Health *msg)
{
  if (msg->weight==63.5) {
   if (msg->name=="Hi"){
    MROS2_INFO("subscribed msg: { name: 'Hi', height: %u cm, weight: 63.5 kg }", msg->height);
    MROS2_INFO("publishing msg: { name: 'Hi', height: %u cm, weight: 63.5 kg }", msg->height);
   } else {
    MROS2_INFO("subscribed msg: { name: '%s', height: %u cm, weight: 63.5 kg }", msg->name.c_str(), msg->height);
    MROS2_INFO("publishing msg: { name: '%s', height: %u cm, weight: 63.5 kg }", msg->name.c_str(), msg->height);
   }
  } else {
       if (msg->name=="Hi"){
    MROS2_INFO("subscribed msg: { name: 'Hi', height: %u cm, weight: %f kg }", msg->height, msg->weight);
    MROS2_INFO("publishing msg: { name: 'Hi', height: %u cm, weight: %f kg }", msg->height, msg->weight);
   } else {
    MROS2_INFO("subscribed msg: { name: '%s', height: %u cm, weight: %f kg }", msg->name.c_str(), msg->height, msg->weight);
    MROS2_INFO("publishing msg: { name: '%s', height: %u cm, weight: %f kg }", msg->name.c_str(), msg->height, msg->weight);
   }
  }
  pub.publish(*msg);
}

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  pub = node.create_publisher<health_msgs::msg::Health>("to_linux", 10);
  sub = node.create_subscription("to_stm", 10, userCallback);
  health_msgs::msg::Health msg;

  MROS2_INFO("ready to pub/sub message");
  mros2::spin();
  BSP_LED_Toggle(LED3);
}

void main_task(void)
{
  main(0, NULL);
}

void
led_cyclic_handler(intptr_t exinf)
{
  BSP_LED_Toggle(LED2);
}