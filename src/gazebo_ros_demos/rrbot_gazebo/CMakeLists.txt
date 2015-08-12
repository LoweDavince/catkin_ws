cmake_minimum_required(VERSION 2.8.3)
project(rrbot_gazebo)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf
  turtlesim
)

catkin_package()

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY worlds
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})



add_executable(template src/template.cpp)
target_link_libraries(template ${catkin_LIBRARIES})
#add_dependencies(template beginner_tutorials_generate_messages_cpp)
