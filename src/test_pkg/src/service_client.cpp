#include "rclcpp/rclcpp.hpp"
#include "my_custom_service_interface/srv/calculator.hpp"

using Calculator = my_custom_service_interface::srv::Calculator;

class CalculatorClient : public rclcpp::Node
{
public:
    CalculatorClient() : Node("calculator_client")
    {
        client_ = this->create_client<Calculator>("/Calculator");

        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&CalculatorClient::call_service, this)
        );

        RCLCPP_INFO(this->get_logger(), "Calculator client started");
    }

private:
    rclcpp::Client<Calculator>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr timer_;

    void call_service()
    {
        if (!rclcpp::ok()) return;

        if (!client_->wait_for_service(std::chrono::seconds(1))) {
            if (!rclcpp::ok()) return;
            RCLCPP_WARN(this->get_logger(), "Waiting for /Calculator service...");
            return;
        }

        auto request = std::make_shared<Calculator::Request>();

        // 🔥 test values
        request->a = 10;
        request->b = 5;
        request->operation = "add";   // "add", "sub", "mul", "div"

        RCLCPP_INFO(this->get_logger(),
            "Sending request: %ld %s %ld",
            request->a,
            request->operation.c_str(),
            request->b
        );

        client_->async_send_request(
            request,
            std::bind(&CalculatorClient::response_callback, this, std::placeholders::_1)
        );

        timer_->cancel(); // chỉ gọi 1 lần
    }

    void response_callback(rclcpp::Client<Calculator>::SharedFuture future)
    {
        if (!rclcpp::ok()) return;

        try {
            auto response = future.get();

            if (response->success) {
                RCLCPP_INFO(this->get_logger(),
                    "Result: %.2f", response->result);
            } else {
                RCLCPP_ERROR(this->get_logger(),
                    "Failed: %s", response->message.c_str());
            }

        } catch (const std::exception &e) {
            RCLCPP_ERROR(this->get_logger(),
                "Service call exception: %s", e.what());
        }

        rclcpp::shutdown();
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CalculatorClient>());
    rclcpp::shutdown();
    return 0;
}