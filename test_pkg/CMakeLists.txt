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
add_executable(publisher_ex src/publisher.cpp)
ament_target_dependencies(publisher_ex rclcpp std_msgs)
install(TARGETS publisher_ex DESTINATION lib/${PROJECT_NAME})

ament_package()
