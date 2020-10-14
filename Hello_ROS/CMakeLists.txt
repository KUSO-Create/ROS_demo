cmake_minimum_required(VERSION 2.8.3)
project(Hello_ROS)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
INCLUDE_DIRS include
LIBRARIES ${PROJECT_NAME}
CATKIN_DEPENDS roscpp rospy std_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS}) 

add_executable(talker src/talker.cpp) 
target_link_libraries(talker ${catkin_LIBRARIES}) 
add_dependencies(talker ${PROJECT_NAME}_generate_messages_cpp) 

add_executable(listener src/listener.cpp) 
target_link_libraries(listener ${catkin_LIBRARIES}) 
add_dependencies(talker ${PROJECT_NAME}_generate_messages_cpp)
