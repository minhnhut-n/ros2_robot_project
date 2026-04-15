// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_custom_interfaces:srv/Calculator.idl
// generated code does not contain a copyright notice

#ifndef MY_CUSTOM_INTERFACES__SRV__DETAIL__CALCULATOR__BUILDER_HPP_
#define MY_CUSTOM_INTERFACES__SRV__DETAIL__CALCULATOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_custom_interfaces/srv/detail/calculator__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_Calculator_Request_operation
{
public:
  explicit Init_Calculator_Request_operation(::my_custom_interfaces::srv::Calculator_Request & msg)
  : msg_(msg)
  {}
  ::my_custom_interfaces::srv::Calculator_Request operation(::my_custom_interfaces::srv::Calculator_Request::_operation_type arg)
  {
    msg_.operation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_custom_interfaces::srv::Calculator_Request msg_;
};

class Init_Calculator_Request_b
{
public:
  explicit Init_Calculator_Request_b(::my_custom_interfaces::srv::Calculator_Request & msg)
  : msg_(msg)
  {}
  Init_Calculator_Request_operation b(::my_custom_interfaces::srv::Calculator_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_Calculator_Request_operation(msg_);
  }

private:
  ::my_custom_interfaces::srv::Calculator_Request msg_;
};

class Init_Calculator_Request_a
{
public:
  Init_Calculator_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Calculator_Request_b a(::my_custom_interfaces::srv::Calculator_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_Calculator_Request_b(msg_);
  }

private:
  ::my_custom_interfaces::srv::Calculator_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_custom_interfaces::srv::Calculator_Request>()
{
  return my_custom_interfaces::srv::builder::Init_Calculator_Request_a();
}

}  // namespace my_custom_interfaces


namespace my_custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_Calculator_Response_message
{
public:
  explicit Init_Calculator_Response_message(::my_custom_interfaces::srv::Calculator_Response & msg)
  : msg_(msg)
  {}
  ::my_custom_interfaces::srv::Calculator_Response message(::my_custom_interfaces::srv::Calculator_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_custom_interfaces::srv::Calculator_Response msg_;
};

class Init_Calculator_Response_success
{
public:
  explicit Init_Calculator_Response_success(::my_custom_interfaces::srv::Calculator_Response & msg)
  : msg_(msg)
  {}
  Init_Calculator_Response_message success(::my_custom_interfaces::srv::Calculator_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Calculator_Response_message(msg_);
  }

private:
  ::my_custom_interfaces::srv::Calculator_Response msg_;
};

class Init_Calculator_Response_result
{
public:
  Init_Calculator_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Calculator_Response_success result(::my_custom_interfaces::srv::Calculator_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_Calculator_Response_success(msg_);
  }

private:
  ::my_custom_interfaces::srv::Calculator_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_custom_interfaces::srv::Calculator_Response>()
{
  return my_custom_interfaces::srv::builder::Init_Calculator_Response_result();
}

}  // namespace my_custom_interfaces

#endif  // MY_CUSTOM_INTERFACES__SRV__DETAIL__CALCULATOR__BUILDER_HPP_
