#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_custom_action_interface/action/counter.hpp"

using Counter = my_custom_action_interface::action::Counter;

class CounterServer : public rclcpp::Node
{
public:
    CounterServer() : Node("counter_server")
    {
        action_server_ = rclcpp_action::create_server<Counter>(
            this,
            "count",
            std::bind(&CounterServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&CounterServer::handle_cancel, this, std::placeholders::_1),
            std::bind(&CounterServer::handle_accepted, this, std::placeholders::_1)
        );
    }

private:
    rclcpp_action::Server<Counter>::SharedPtr action_server_;

    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID &,
        std::shared_ptr<const Counter::Goal> goal)
    {
        RCLCPP_INFO(this->get_logger(), "Goal received: %d", goal->target);
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<Counter>>)
    {
        RCLCPP_INFO(this->get_logger(), "Goal canceled");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<Counter>> goal_handle)
    {
        std::thread{std::bind(&CounterServer::execute, this, goal_handle)}.detach();
    }

    void execute(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<Counter>> goal_handle)
    {
        auto feedback = std::make_shared<Counter::Feedback>();
        auto result = std::make_shared<Counter::Result>();

        for (int i = 0; i <= goal_handle->get_goal()->target; i++)
        {
            if (goal_handle->is_canceling())
            {
                goal_handle->canceled(result);
                return;
            }

            feedback->current = i;
            goal_handle->publish_feedback(feedback);

            RCLCPP_INFO(this->get_logger(), "Progress: %d", i);
            rclcpp::sleep_for(std::chrono::milliseconds(500));
        }

        result->result = goal_handle->get_goal()->target;
        goal_handle->succeed(result);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CounterServer>());
    rclcpp::shutdown();
    return 0;
}