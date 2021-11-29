#include "app.h"
#include "mros2.h"
#include "std_msgs/msg/string.hpp"

#include "stm32f7xx_nucleo_144.h"

#include <sstream>
#include <istream>

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(std_msgs::msg::String *msg)
{
  MROS2_INFO("subscribed msg: '%s'", msg->data.c_str());

  /* convert string to each types */
  std::vector<std::string> splittedMsg;
  std::string s = msg->data;
  std::stringstream ss{s};
  std::string buf;
  while (std::getline(ss, buf, ','))
  {
    splittedMsg.push_back(buf);
  }

  std::string name;
  std::int8_t height;
  std::float weight;

  splittedMsg[0] >> name;
  splittedMsg[1] >> height;
  splittedMsg[2] >> weight;

  /* reconvert each types to string */


  MROS2_INFO("publishing msg: '%s'", msg->data.c_str());
  pub.publish(*msg);
}

int main(int argc, char *argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  pub = node.create_publisher<std_msgs::msg::String>("to_linux", 10);
  sub = node.create_subscription("to_stm", 10, userCallback);
  std_msgs::msg::String msg;

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
