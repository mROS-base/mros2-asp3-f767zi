#include "app.h"
#include "mros2.h"
#include "std_msgs/msg/string.hpp"
#include <string>

#include "stm32f7xx_nucleo_144.h"

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(std_msgs::msg::String *msg)
{
  MROS2_INFO("subscribed msg!");
  
  std::string sub_str1 = msg->data.substr(0,8);
  std::string sub_str2 = msg->data.substr(8,8);
  std::string sub_str3 = msg->data.substr(16,8);
  std::string sub_str4 = msg->data.substr(24,8);
  std::string sub_str5 = msg->data.substr(32,8);
  std::string sub_str6 = msg->data.substr(40,8);

  double linear_x = 0.000000; // std::stod(sub_str1);
  double linear_y = 0.000002; // std::stod(sub_str2);
  double linear_z = 0.000004; // std::stod(sub_str3);
  double angluar_x = 0.000006; // std::stod(sub_str4);
  double angluar_y = 0.000008; // std::stod(sub_str5);
  double angluar_z = 0.000010; // std::stod(sub_str6);
  
  auto reconverted_message = std_msgs::msg::String();

  std::string pub_str1 = "0.000000"; // std::to_string(linear_x);
  std::string pub_str2 = "0.000002"; // std::to_string(linear_y);
  std::string pub_str3 = "0.000004"; // std::to_string(linear_z);
  std::string pub_str4 = "0.000006"; // std::to_string(angular_x);
  std::string pub_str5 = "0.000008"; // std::to_string(angular_y);
  std::string pub_str6 = "0.000010"; // std::to_string(angular_z);

  std::string pub_str = "0.0000000.0000020.0000040.0000060.0000080.000010"; // pub_str1 + pub_str2 + pub_str3 + pub_str4 + pub_str5 + pub_str6;
  reconverted_message.data = pub_str;
  MROS2_INFO("publishing msg!");
  pub.publish(reconverted_message);
}

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  pub = node.create_publisher<std_msgs::msg::String>("to_linux", 10);
  sub = node.create_subscription<std_msgs::msg::String>("to_stm", 10, userCallback);
  std_msgs::msg::String msg;

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