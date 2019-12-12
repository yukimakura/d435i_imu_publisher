cmake_minimum_required(VERSION 2.8.3)
project(d435i_imu_publisher)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES d435i_imu_publisher
  CATKIN_DEPENDS  roscpp sensor_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_executable(d435i_imu_publisher_node src/d435i_imu_publisher_node.cpp src/d435i_imu_publisher.cpp)
target_link_libraries(d435i_imu_publisher_node
  ${catkin_LIBRARIES}
)
