#include "app.h"
#include "mros2.h"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include "stm32f7xx_nucleo_144.h"

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");
  MROS2_INFO("app name: mturtle_teleop");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mturtle_teleop");
  mros2::Publisher pub = node.create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);  
  MROS2_INFO("ready to pub/sub message");

  geometry_msgs::msg::Vector3 linear;
  geometry_msgs::msg::Vector3 angular;
  geometry_msgs::msg::Twist twist;

  auto publish_count = 0;
  while (1)
  {
    linear.x = publish_count/10.0;
    linear.y = 0;
    linear.z = 0;  
    angular.x = 0;
    angular.y = 0;
    angular.z = publish_count/10.0;
    twist.linear = linear;
    twist.angular = angular;
    MROS2_INFO("publishing Twist msg!!");
    pub.publish(twist);
    publish_count++;
    osDelay(3000);
  }

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