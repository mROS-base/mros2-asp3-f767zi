#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <chrono>

#define TEST_NUM 10

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

    bool isStarted = false;
    bool isFinished = false;
    int cnt = 5;
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
    unsigned long result_array[TEST_NUM];

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("measure_node"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("to_stm", 10);
      subscriber_ = this->create_subscription<std_msgs::msg::String>("to_linux", rclcpp::QoS(10).best_effort(), std::bind(&MinimalPublisher::topic_callback, this, _1));
      timer_ = this->create_wall_timer(1000ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      if(!isStarted) {
        message.data = std::to_string(cnt--) + " messages to start";
      } else {
        message.data = std::to_string(cnt);
      }
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      start_time = std::chrono::high_resolution_clock::now();
      publisher_->publish(message);
      if(cnt <= 0){isStarted = true;}
    }
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        end_time = std::chrono::high_resolution_clock::now();
        if(isStarted && (cnt <= TEST_NUM)){
          result_array[cnt] = (unsigned long)std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
          cnt ++;
        } else if(isStarted && !isFinished){
          for(int i=0; i<TEST_NUM;i++){
             RCLCPP_INFO(this->get_logger(), "%d : %lu [us]", i, result_array[i]);;
          }
          isFinished = true;
          rclcpp::shutdown();
        }
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
    size_t count_;
  };

  int main(int argc, char * argv[])
  {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
  }
