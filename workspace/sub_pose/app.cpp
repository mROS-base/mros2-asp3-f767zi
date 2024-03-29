#include "app.h"
#include "mros2.h"
#include "geometry_msgs/msg/pose.hpp"

#include "stm32f7xx_nucleo_144.h"

void userCallback(geometry_msgs::msg::Pose *msg)
{
  MROS2_INFO("subscribed Pose msg!!");
}

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");
  MROS2_INFO("app name: sub_pose");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("sub_pose");
  mros2::Subscriber sub = node.create_subscription<geometry_msgs::msg::Pose>("cmd_vel", 10, userCallback);
  osDelay(100);
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