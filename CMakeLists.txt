cmake_minimum_required(VERSION 3.0.2)
project(pi4_gpio)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_service_files(FILES
  DigitalWrite.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(pi4_gpio src/pi4_gpio.cpp)
target_link_libraries(pi4_gpio ${catkin_LIBRARIES} -lwiringPi)

add_executable(pi4_gpio_srv_client src/pi4_gpio_srv_client.cpp)
target_link_libraries(pi4_gpio_srv_client ${catkin_LIBRARIES})
