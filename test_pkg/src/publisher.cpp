/* this is code minimal publisher on ROS model
library of languafe should be placed on top, make sure all sys initial work well
*/

// for timer control, latency, frequency of timer
#include <chrono>
// functional, connect all callback function. via :bind() and :placeholders
#include <functional>
// lib for memory management, with share_ptr and make_shared
#include <memory>
// standard lib of c language for string context, processing
#include <string>


//standard ros library
#include "rclcpp/rclcpp.hpp"
//lib for communication via string type message
#include "std_msgs/msg/string.hpp"

//class inherit public method on rclcpp class with Node
//parent class is rclcpp::Node
class MinimalPublisher : public rclcpp::Node {
    rclcpp::TimerBase::SharedPtr publ_timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publ;
    size_t this_event_counter;

    public:
        //reset to 0 with counter, this create to check how many times that callback is called
        MinimalPublisher() : Node("minimal_publisher"), this_event_counter(0) {
            publ = this->create_publisher<std_msgs::msg::String>("publisher_node", 10);

            // publ_timer = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&MinimalPublisher::timer_callback_fcn, this));
            publ_timer = this->create_wall_timer(std::chrono::milliseconds(500), [this] () {
                this->timer_callback_fcn();
            });
        }
    private:
        void timer_callback_fcn() {
            auto message_publ = std_msgs::msg::String();

            // trong trường hợp mà muốn ghép hai string chổ này ta có hai cách:
            // cách 1: tạo hai cái string theo std_msgs rồi ghép lại
            // cách 2: viết std::string("Hello...")  + "đoạn string mà ta muốn thay"
            message_publ.data = "Hello, this is msg from publisher, ros2, with:" + std::to_string(this_event_counter++);

            //get logger sử lý string ở dạng printf, nên là cần phải chuyển string trên c++ sang c string type bằng c_str()
            RCLCPP_INFO(this->get_logger(), "publising: %s", message_publ.data.c_str());
            publ->publish(message_publ);
        }
};

int main (int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}
