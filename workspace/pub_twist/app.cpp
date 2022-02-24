#include "app.h"
#include "mros2.h"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include "stm32f7xx_nucleo_144.h"

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("pub_twist");
  mros2::Publisher pub = node.create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);  
  MROS2_INFO("ready to pub/sub message");

  geometry_msgs::msg::Vector3 linear;
  geometry_msgs::msg::Vector3 angular;
  geometry_msgs::msg::Twist twist;

  auto publish_count = 0;
  while (1)
  {
    linear.x = publish_count/1.0;
    linear.y = publish_count/1.0;
    linear.z = publish_count/1.0;  
    angular.x = publish_count/1.0;
    angular.y = publish_count/1.0;
    angular.z = publish_count/1.0;
    twist.linear = linear;
    twist.angular = angular;
    MROS2_INFO("publishing Twist msg!!");
    pub.publish(twist);
    publish_count++;
    osDelay(1000);
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