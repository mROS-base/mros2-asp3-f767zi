#include "app.h"
#include "mros2.h"
#include "health_msgs/msg/health.hpp"

#include "stm32f7xx_nucleo_144.h"

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(health_msgs::msg::Health *msg)
{
  MROS2_INFO("subscribed msg: { name: %s, height: %d, weight: %f }", msg->name.c_str(), msg->height, msg->weight);
  MROS2_INFO("publishing msg: { name: %s, height: %d, weight: %f }", msg->name.c_str(), msg->height, msg->weight);
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
