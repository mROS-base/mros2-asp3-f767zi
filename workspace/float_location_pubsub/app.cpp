#include "app.h"
#include "mros2.h"
#include "float_location_msgs/msg/floatlocation.hpp"

#include "stm32f7xx_nucleo_144.h"

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(float_location_msgs::msg::FloatLocation *msg)
{
  MROS2_INFO("subscribed msg: { x: %f, y: %f, z: %f }", msg->x, msg->y, msg->z);
  MROS2_INFO("publishing msg: { x: %f, y: %f, z: %f }", msg->x, msg->y, msg->z);
  pub.publish(*msg);
}

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  pub = node.create_publisher<float_location_msgs::msg::FloatLocation>("to_linux", 10);
  sub = node.create_subscription<float_location_msgs::msg::FloatLocation>("to_stm", 10, userCallback);
  float_location_msgs::msg::FloatLocation msg;

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