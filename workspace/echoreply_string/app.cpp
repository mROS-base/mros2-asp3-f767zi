#include "app.h"
#include "cmsis_os.h"
#include "lwip.h"

#include "stm32f7xx_nucleo_144.h"
#include "mros2.h"
#include "std_msgs/msg/string.hpp"

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(std_msgs::msg::String *msg)
{
  CMSIS_IMPL_INFO("subscribed msg: '%s'", msg->data.c_str());
  CMSIS_IMPL_INFO("publishing msg: '%s'", msg->data.c_str());
  pub.publish(*msg);
}

void main_task(void)
{
  MX_LWIP_Init();
  mros2::init(NULL, NULL);
  mros2::Node node = mros2::Node::create_node();
  sub = node.create_subscription("to_stm", 1, userCallback);
  pub = node.create_publisher<std_msgs::msg::String>("to_linux", NULL);
  std_msgs::msg::String msg;
  mros2::spin();
}

void
led_cyclic_handler(intptr_t exinf)
{
  BSP_LED_Toggle(LED2);
}
