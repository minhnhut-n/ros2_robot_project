#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to my_custom_interfaces__srv__Calculator_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Calculator_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: i64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub b: i64,

    /// "add", "sub", "mul", "div"
    pub operation: std::string::String,

}



impl Default for Calculator_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Calculator_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Calculator_Request {
  type RmwMsg = super::srv::rmw::Calculator_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        a: msg.a,
        b: msg.b,
        operation: msg.operation.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      a: msg.a,
      b: msg.b,
        operation: msg.operation.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      a: msg.a,
      b: msg.b,
      operation: msg.operation.to_string(),
    }
  }
}


// Corresponds to my_custom_interfaces__srv__Calculator_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Calculator_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for Calculator_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Calculator_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Calculator_Response {
  type RmwMsg = super::srv::rmw::Calculator_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result,
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      result: msg.result,
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: msg.result,
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}






#[link(name = "my_custom_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__my_custom_interfaces__srv__Calculator() -> *const std::ffi::c_void;
}

// Corresponds to my_custom_interfaces__srv__Calculator
#[allow(missing_docs, non_camel_case_types)]
pub struct Calculator;

impl rosidl_runtime_rs::Service for Calculator {
    type Request = Calculator_Request;
    type Response = Calculator_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__my_custom_interfaces__srv__Calculator() }
    }
}


