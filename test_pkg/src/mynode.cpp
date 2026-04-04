#include "rclcpp/rclcpp.hpp"
using namespace std;

#define TIMER_TIMEOUT 1000 //1s

class MytestNode : public rclcpp::Node {
    // coding convention style
    public:
        //build construction
        MytestNode(): Node("node_name") {
            //init logger in rcl package
            RCLCPP_INFO(this->get_logger(), "construction of node is inited");

            //use a timer for timer callback trigger
            timer_ = this->create_wall_timer(
                chrono::milliseconds(TIMER_TIMEOUT),
                //"this" is point to current object
                // bind(), pass the args into dest function
                bind(&MytestNode::timer_callback, this)
            );
        };

    private:
        void timer_callback() {
            RCLCPP_INFO(this->get_logger(), "hi!, timer callback is called");
        };
        rclcpp::TimerBase::SharedPtr timer_;
}; //finish class with comma

int main (int argc, char* argv[]) {
    // use class
    rclcpp::init(argc, argv);
    // call construction and run node
    /* make_share <-> make_shared pointer, this fcn call\
    constructer and pass arg to it, then a smart pointer will be returned. */
    rclcpp::spin(make_shared<MytestNode>());

    rclcpp::shutdown();
    return 0;
}