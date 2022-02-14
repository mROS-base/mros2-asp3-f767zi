#include "app.h"
#include "mros2.h"
#include "std_msgs/msg/float32.hpp"

#include "stm32f7xx_nucleo_144.h"

mros2::Publisher pub;

int main(int argc, char *argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  pub = node.create_publisher<std_msgs::msg::Float32>("to_linux", 10);
  MROS2_INFO("ready to pub/sub message");

  std_msgs::msg::Float32 msg;
  auto publish_count = 0;
    while (1) {
    msg.data = publish_count++/1.0;
    MROS2_INFO("publishing float msg!!");
    pub.publish(msg);
    osDelay(1000);
  }
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