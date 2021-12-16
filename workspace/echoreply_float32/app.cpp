#include "app.h"
#include "mros2.h"
#include "std_msgs/msg/float32.hpp"

#include "stm32f7xx_nucleo_144.h"

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(std_msgs::msg::Float32 *msg)
{
  if (5.0 < msg->data && msg->data < 10.0) {
    MROS2_INFO("5.0 < msg < 10.0");
  } else {
    MROS2_INFO("msg <= 5.0 or 10.0 <= msg");
  }
  /* TODO: make MROS2_INFO support float type
  MROS2_INFO("subscribed msg: %f", msg->data);
  MROS2_INFO("publishing msg: %f", msg->data);
  */
  pub.publish(*msg);
}

int main(int argc, char *argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  pub = node.create_publisher<std_msgs::msg::Float32>("to_linux", 10);
  sub = node.create_subscription<std_msgs::msg::Float32>("to_stm", 10, userCallback);
  std_msgs::msg::Float32 msg;

  MROS2_INFO("ready to pub/sub message");
  mros2::spin();
  BSP_LED_Toggle(LED3);
}

void main_task(void)
{
  main(0, NULL);
}

void led_cyclic_handler(intptr_t exinf)
{
  BSP_LED_Toggle(LED2);
}