cmake_minimum_required(VERSION 3.8)
project(test_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

#node for testing write a node
add_executable(testnode_name src/mynode.cpp)
ament_target_dependencies(testnode_name rclcpp)
install(TARGETS testnode_name DESTINATION lib/${PROJECT_NAME})

#node for testing write a publisher
add_executable(publish_node src/publisher.cpp)
ament_target_dependencies(publish_node rclcpp std_msgs)
install(TARGETS publish_node DESTINATION lib/${PROJECT_NAME})

#node for testing write a subcription
add_executable(subscriber_node src/subcriber.cpp)
ament_target_dependencies(subscriber_node rclcpp std_msgs)
install(TARGETS subscriber_node DESTINATION lib/${PROJECT_NAME})

#for services
find_package(my_custom_service_interface REQUIRED)
add_executable(service_calculator_server src/service_server.cpp)
ament_target_dependencies(service_calculator_server rclcpp
                                                    my_custom_service_interface)
install(TARGETS service_calculator_server DESTINATION lib/${PROJECT_NAME})

#client-services
add_executable(service_calculator_client src/service_client.cpp)
ament_target_dependencies(service_calculator_client rclcpp
                                                    my_custom_service_interface)
install(TARGETS service_calculator_client DESTINATION lib/${PROJECT_NAME})

#for actions
find_package(rclcpp_action REQUIRED)
find_package(my_custom_action_interface REQUIRED)
add_executable(action_counter_server src/action_server.cpp)
ament_target_dependencies(action_counter_server rclcpp
                                                rclcpp_action
                                                my_custom_action_interface)
install(TARGETS action_counter_server DESTINATION lib/${PROJECT_NAME})

#client-action
# find_package(rclcpp_action REQUIRED)
add_executable(action_client_count src/action_client.cpp)
ament_target_dependencies(action_client_count rclcpp
                                              rclcpp_action
                                              my_custom_action_interface)
install(TARGETS action_client_count DESTINATION lib/${PROJECT_NAME})

ament_package()