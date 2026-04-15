#include "rclcpp/rclcpp.hpp"
#include "my_custom_interfaces/srv/calculator.hpp"

class CalculatorServer : public rclcpp::Node
{
    rclcpp::Service<my_custom_interfaces::srv::Calculator>::SharedPtr service_;
    public:
        CalculatorServer() : Node("calculator_server")
        {
            //https://docs.ros2.org/foxy/api/rclcpp/classrclcpp_1_1Node.html
            //rclcpp::Service< ServiceT >::SharedPtr 	create_service (const std::string &service_name, CallbackT &&callback
            service_ = this->create_service<my_custom_interfaces::srv::Calculator>("calculator",
                [this] (const std::shared_ptr<my_custom_interfaces::srv::Calculator::Request> req,
                        std::shared_ptr<my_custom_interfaces::srv::Calculator::Response> res) {
                            this->handle_request(req, res);
                        }
                    );
        }

    private:
        void handle_request(const std::shared_ptr<my_custom_interfaces::srv::Calculator::Request> req,
                            std::shared_ptr<my_custom_interfaces::srv::Calculator::Response> res)
        {
            if (req->operation == "add")
            {
                res->result = req->a + req->b;
                res->success = true;
            }
            else if (req->operation == "sub")
            {
                res->result = req->a - req->b;
                res->success = true;
            }
            else
            {
                res->success = false;
                res->message = "Unknown operation";
                return;
            }

            res->message = "OK";
        }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CalculatorServer>());
    rclcpp::shutdown();
    return 0;
}