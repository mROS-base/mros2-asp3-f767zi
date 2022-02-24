#include "app.h"
#include "mros2.h"
#include "geometry_msgs/msg/twist.hpp"

#include "stm32f7xx_nucleo_144.h"

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(geometry_msgs::msg::Twist *msg)
{
  /*
  MROS2_INFO("Subscribed msg : %d", msg->data);
  MROS2_INFO("Publishing msg : %d", msg->data);
  */
  pub.publish(*msg);
}

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  pub = node.create_publisher<geometry_msgs::msg::Twist>("to_linux", 10);
  sub = node.create_subscription<geometry_msgs::msg::Twist>("to_stm", 10, userCallback);
  geometry_msgs::msg::Twist msg;

  MROS2_INFO("ready to pub/sub evaluation");

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
