#include "app.h"
#include "mros2.h"
#include "std_msgs/msg/float32.hpp"

#include "stm32f7xx_nucleo_144.h"

int main(int argc, char *argv[])
{
  MROS2_INFO("mROS 2 application is started");
  MROS2_INFO("app name: pub_float32");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  mros2::Publisher pub = node.create_publisher<std_msgs::msg::Float32>("to_linux", 10);
  osDelay(100);
  MROS2_INFO("ready to pub/sub message");

  std_msgs::msg::Float32 msg;
  auto publish_count = -0.5;
  while (1)
  {
    msg.data = publish_count;
    MROS2_INFO("publishing float msg!!");
    pub.publish(msg);

    if (0.0 >= msg.data)
      MROS2_INFO("msg <= 0.0");
    else if (0.0 < msg.data && msg.data < 0.5)
      MROS2_INFO("0.0 < msg < 0.5");
    else if (0.5 < msg.data && msg.data < 1.0)
      MROS2_INFO("0.5 < msg < 1.0");
    else
      MROS2_INFO("msg >= 1.0");

    publish_count = publish_count + 0.1;
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