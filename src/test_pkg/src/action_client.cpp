#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_custom_action_interface/action/counter.hpp"

using actionPath = my_custom_action_interface::action::Counter;

class ClientAction : public rclcpp::Node {
    public:
        ClientAction() : Node("action_client") {
            actionClient = rclcpp_action::create_client<actionPath>(this, "count");
            this->send_req();
        }

    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp_action::Client<actionPath>::SharedPtr actionClient;

        void send_req() {
            // auto goal_msg = std::make_shared<actionPath::Goal>();
            auto goa
            l_msg = actionPath::Goal();
            goal_msg.target = 10;
            RCLCPP_INFO(this->get_logger(), "Set goal: %d", goal_msg.target);

            // một datastruct https://docs.ros2.org/latest/api/rclcpp_action/
            auto send_goal_options = rclcpp_action::Client<actionPath>::SendGoalOptions();

            //feedback callback
            send_goal_options.feedback_callback = [&](auto goal_handle, const auto fb) {
                RCLCPP_INFO(this->get_logger(), "current status: %d\n", fb->current);
            };
            //result callback
            send_goal_options.result_callback = [&](const auto& rlt) {
                RCLCPP_INFO(this->get_logger(), "final status: %d\n", rlt.result->result);
                rclcpp::shutdown();
            };

            // https://docs.ros2.org/latest/api/rclcpp_action/classrclcpp__action_1_1Client.html
            this->actionClient->async_send_goal(goal_msg, send_goal_options);
        }
};


int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ClientAction>());
    rclcpp::shutdown();
    return 0;
}