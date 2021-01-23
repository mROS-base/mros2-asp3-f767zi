#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class Subscriber : public rclcpp::Node
{
    public:
    Subscriber() : Node("measre_test_node")
    {
        subscriber_ = this->create_subscription<std_msgs::msg::String>("to_stm", rclcpp::QoS(10).best_effort(), std::bind(&Subscriber::topic_callback, this, _1));
        publisher_ = this->create_publisher<std_msgs::msg::String>("to_linux", 10);
    }

    private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "Subscribing: '%s'", msg->data.c_str());
        publisher_->publish(*msg);
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};


int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();
    return 0;
}