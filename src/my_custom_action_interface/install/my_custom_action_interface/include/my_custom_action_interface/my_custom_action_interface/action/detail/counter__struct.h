// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_custom_action_interface:action/Counter.idl
// generated code does not contain a copyright notice

#ifndef MY_CUSTOM_ACTION_INTERFACE__ACTION__DETAIL__COUNTER__STRUCT_H_
#define MY_CUSTOM_ACTION_INTERFACE__ACTION__DETAIL__COUNTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Counter in the package my_custom_action_interface.
typedef struct my_custom_action_interface__action__Counter_Goal
{
  int32_t target;
} my_custom_action_interface__action__Counter_Goal;

// Struct for a sequence of my_custom_action_interface__action__Counter_Goal.
typedef struct my_custom_action_interface__action__Counter_Goal__Sequence
{
  my_custom_action_interface__action__Counter_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_action_interface__action__Counter_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Counter in the package my_custom_action_interface.
typedef struct my_custom_action_interface__action__Counter_Result
{
  int32_t result;
} my_custom_action_interface__action__Counter_Result;

// Struct for a sequence of my_custom_action_interface__action__Counter_Result.
typedef struct my_custom_action_interface__action__Counter_Result__Sequence
{
  my_custom_action_interface__action__Counter_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_action_interface__action__Counter_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Counter in the package my_custom_action_interface.
typedef struct my_custom_action_interface__action__Counter_Feedback
{
  int32_t current;
} my_custom_action_interface__action__Counter_Feedback;

// Struct for a sequence of my_custom_action_interface__action__Counter_Feedback.
typedef struct my_custom_action_interface__action__Counter_Feedback__Sequence
{
  my_custom_action_interface__action__Counter_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_action_interface__action__Counter_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "my_custom_action_interface/action/detail/counter__struct.h"

/// Struct defined in action/Counter in the package my_custom_action_interface.
typedef struct my_custom_action_interface__action__Counter_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  my_custom_action_interface__action__Counter_Goal goal;
} my_custom_action_interface__action__Counter_SendGoal_Request;

// Struct for a sequence of my_custom_action_interface__action__Counter_SendGoal_Request.
typedef struct my_custom_action_interface__action__Counter_SendGoal_Request__Sequence
{
  my_custom_action_interface__action__Counter_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_action_interface__action__Counter_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Counter in the package my_custom_action_interface.
typedef struct my_custom_action_interface__action__Counter_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} my_custom_action_interface__action__Counter_SendGoal_Response;

// Struct for a sequence of my_custom_action_interface__action__Counter_SendGoal_Response.
typedef struct my_custom_action_interface__action__Counter_SendGoal_Response__Sequence
{
  my_custom_action_interface__action__Counter_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_action_interface__action__Counter_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Counter in the package my_custom_action_interface.
typedef struct my_custom_action_interface__action__Counter_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} my_custom_action_interface__action__Counter_GetResult_Request;

// Struct for a sequence of my_custom_action_interface__action__Counter_GetResult_Request.
typedef struct my_custom_action_interface__action__Counter_GetResult_Request__Sequence
{
  my_custom_action_interface__action__Counter_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_action_interface__action__Counter_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "my_custom_action_interface/action/detail/counter__struct.h"

/// Struct defined in action/Counter in the package my_custom_action_interface.
typedef struct my_custom_action_interface__action__Counter_GetResult_Response
{
  int8_t status;
  my_custom_action_interface__action__Counter_Result result;
} my_custom_action_interface__action__Counter_GetResult_Response;

// Struct for a sequence of my_custom_action_interface__action__Counter_GetResult_Response.
typedef struct my_custom_action_interface__action__Counter_GetResult_Response__Sequence
{
  my_custom_action_interface__action__Counter_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_action_interface__action__Counter_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "my_custom_action_interface/action/detail/counter__struct.h"

/// Struct defined in action/Counter in the package my_custom_action_interface.
typedef struct my_custom_action_interface__action__Counter_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  my_custom_action_interface__action__Counter_Feedback feedback;
} my_custom_action_interface__action__Counter_FeedbackMessage;

// Struct for a sequence of my_custom_action_interface__action__Counter_FeedbackMessage.
typedef struct my_custom_action_interface__action__Counter_FeedbackMessage__Sequence
{
  my_custom_action_interface__action__Counter_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_custom_action_interface__action__Counter_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_CUSTOM_ACTION_INTERFACE__ACTION__DETAIL__COUNTER__STRUCT_H_
