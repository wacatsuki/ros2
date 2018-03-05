cmake_minimum_required(VERSION 3.5)

project(testpackagecpp)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rmw_implementation REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

#include_directories(${rclcpp_INCLUDE_DIRS}
#		    ${rmw_implementation_INCLUDE_DIRS}
#		    ${std_msgs_INCLUDE_DIRS}
#		    ${geometry_msgs_INCLUDE_DIRS})

add_executable(message_sender_node message_sender.cpp)
ament_target_dependencies(message_sender_node geometry_msgs rclcpp rmw_implementation std_msgs)


#target_link_libraries(message_sender
#		    ${rclcpp_LIBRARIES}
#		    ${rmw_LIBRARIES}
#                   ${rmw_implementation_LIBRARIES}
#		    ${std_msgs_LIBRARIES}
#		    ${geometry_msgs_LIBRARIES})


install(TARGETS message_sender_node DESTINATION lib/${PROJECT_NAME})

ament_package()


