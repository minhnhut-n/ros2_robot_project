#include <iostream>
#include <string>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


class SubcriberNode : public rclcpp::Node {

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subcriber_;
    public:
        SubcriberNode() : Node("subcriber_node") {
            subcriber_ = this->create_subscription<std_msgs::msg::String>("publisher_node", 10, 
                [this] (const std_msgs::msg::String::SharedPtr msg) {this->event_callback_fcn(msg);});
        }

    private:
        void event_callback_fcn(const std_msgs::msg::String::SharedPtr msg) {
            RCLCPP_INFO(this->get_logger(), "This is message we are receiving: %s", msg->data.c_str());
        }
};


int main (int argc, char* argv[]) {
    
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubcriberNode>());
    rclcpp::shutdown();
    return 0;
}