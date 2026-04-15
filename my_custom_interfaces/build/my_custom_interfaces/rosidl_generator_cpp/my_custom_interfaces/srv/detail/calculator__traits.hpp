// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_custom_interfaces:srv/Calculator.idl
// generated code does not contain a copyright notice

#ifndef MY_CUSTOM_INTERFACES__SRV__DETAIL__CALCULATOR__TRAITS_HPP_
#define MY_CUSTOM_INTERFACES__SRV__DETAIL__CALCULATOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_custom_interfaces/srv/detail/calculator__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Calculator_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << ", ";
  }

  // member: operation
  {
    out << "operation: ";
    rosidl_generator_traits::value_to_yaml(msg.operation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Calculator_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }

  // member: operation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "operation: ";
    rosidl_generator_traits::value_to_yaml(msg.operation, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Calculator_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_custom_interfaces::srv::Calculator_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_custom_interfaces::srv::Calculator_Request & msg)
{
  return my_custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_custom_interfaces::srv::Calculator_Request>()
{
  return "my_custom_interfaces::srv::Calculator_Request";
}

template<>
inline const char * name<my_custom_interfaces::srv::Calculator_Request>()
{
  return "my_custom_interfaces/srv/Calculator_Request";
}

template<>
struct has_fixed_size<my_custom_interfaces::srv::Calculator_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_custom_interfaces::srv::Calculator_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_custom_interfaces::srv::Calculator_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Calculator_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Calculator_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Calculator_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_custom_interfaces::srv::Calculator_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_custom_interfaces::srv::Calculator_Response & msg)
{
  return my_custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_custom_interfaces::srv::Calculator_Response>()
{
  return "my_custom_interfaces::srv::Calculator_Response";
}

template<>
inline const char * name<my_custom_interfaces::srv::Calculator_Response>()
{
  return "my_custom_interfaces/srv/Calculator_Response";
}

template<>
struct has_fixed_size<my_custom_interfaces::srv::Calculator_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_custom_interfaces::srv::Calculator_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_custom_interfaces::srv::Calculator_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_custom_interfaces::srv::Calculator>()
{
  return "my_custom_interfaces::srv::Calculator";
}

template<>
inline const char * name<my_custom_interfaces::srv::Calculator>()
{
  return "my_custom_interfaces/srv/Calculator";
}

template<>
struct has_fixed_size<my_custom_interfaces::srv::Calculator>
  : std::integral_constant<
    bool,
    has_fixed_size<my_custom_interfaces::srv::Calculator_Request>::value &&
    has_fixed_size<my_custom_interfaces::srv::Calculator_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_custom_interfaces::srv::Calculator>
  : std::integral_constant<
    bool,
    has_bounded_size<my_custom_interfaces::srv::Calculator_Request>::value &&
    has_bounded_size<my_custom_interfaces::srv::Calculator_Response>::value
  >
{
};

template<>
struct is_service<my_custom_interfaces::srv::Calculator>
  : std::true_type
{
};

template<>
struct is_service_request<my_custom_interfaces::srv::Calculator_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_custom_interfaces::srv::Calculator_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_CUSTOM_INTERFACES__SRV__DETAIL__CALCULATOR__TRAITS_HPP_
