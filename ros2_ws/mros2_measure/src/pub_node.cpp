#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("measure_node"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("to_stm", 10);
       subscriber_ = this->create_subscription<std_msgs::msg::String>("to_linux", rclcpp::QoS(10).best_effort(), std::bind(&Subscriber::topic_callback, this, _1));
      timer_ = this->create_wall_timer(1000ms, std::bind(&MinimalPublisher::timer_callback, this));
    }
    bool isStarted = false;
    int cnt = 10;

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      if(!isStarted) {
        message.data = std::to_string(cnt--) + "messages to start";
      }
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
      if(cnt <= 0){isStarted = false;}
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
  };

  int main(int argc, char * argv[])
  {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
  }
