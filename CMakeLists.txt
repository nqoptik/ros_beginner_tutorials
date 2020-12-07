cmake_minimum_required(VERSION 3.5)

project(ros_beginner_tutorials)

## Compile as C++14, supported in ROS Kinetic and newer
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Compile with the highest warning level
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
# find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs)
find_package(
    catkin REQUIRED
    COMPONENTS actionlib
               actionlib_msgs
               geometry_msgs
               interactive_markers
               message_generation
               pcl_conversions
               pcl_ros
               roscpp
               rospy
               sensor_msgs
               std_msgs
               tf
               turtlesim
               urdf
               visualization_msgs)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )
add_message_files(FILES Num.msg)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )
add_service_files(FILES AddTwoInts.srv)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )
add_action_files(FILES Fibonacci.action Averaging.action)

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )
generate_messages(DEPENDENCIES actionlib_msgs geometry_msgs sensor_msgs
                  std_msgs)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
# catkin_package(
#     #  INCLUDE_DIRS include
#     #  LIBRARIES ros_beginner_tutorials
#     #  CATKIN_DEPENDS roscpp rospy std_msgs
#     #  DEPENDS system_lib
# )
catkin_package(
    CATKIN_DEPENDS
    actionlib_msgs
    geometry_msgs
    interactive_markers
    message_runtime
    pcl_conversions
    pcl_ros
    roscpp
    rospy
    sensor_msgs
    std_msgs
    tf
    turtlesim
    urdf
    visualization_msgs)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(# include
#                     ${catkin_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/ros_beginner_tutorials.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/ros_beginner_tutorials_node.cpp)
add_executable(add_two_ints_client src/add_two_ints_client.cpp)

add_executable(add_two_ints_server src/add_two_ints_server.cpp)

add_executable(averaging_client src/averaging_client.cpp)

add_executable(averaging_server src/averaging_server.cpp)

add_executable(basic_controls src/basic_controls.cpp)

add_executable(basic_shapes src/basic_shapes.cpp)

add_executable(fibonacci_callback_client src/fibonacci_callback_client.cpp)

add_executable(fibonacci_class_client src/fibonacci_class_client.cpp)

add_executable(fibonacci_client src/fibonacci_client.cpp)

add_executable(fibonacci_server src/fibonacci_server.cpp)

add_executable(frame_tf_broadcaster src/frame_tf_broadcaster.cpp)

add_executable(listener src/listener.cpp)

add_executable(parser src/parser.cpp)

add_executable(pcl_example src/pcl_example.cpp)

add_executable(points_and_lines src/points_and_lines.cpp)

add_executable(simple_marker src/simple_marker.cpp)

add_executable(state_publisher src/state_publisher.cpp)

add_executable(talker src/talker.cpp)

add_executable(tf_broadcaster src/tf_broadcaster.cpp)

add_executable(tf_listener src/tf_listener.cpp)

add_executable(turtle_tf_broadcaster src/turtle_tf_broadcaster.cpp)

add_executable(turtle_tf_listener src/turtle_tf_listener.cpp)

add_executable(turtle_tf_listener_debug src/turtle_tf_listener_debug.cpp)

add_executable(turtle_tf_message_filter src/turtle_tf_message_filter.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(add_two_ints_client ros_beginner_tutorials_gencpp)

add_dependencies(add_two_ints_server ros_beginner_tutorials_gencpp)

add_dependencies(averaging_client ${ros_beginner_tutorials_EXPORTED_TARGETS})

add_dependencies(averaging_server ${ros_beginner_tutorials_EXPORTED_TARGETS})

add_dependencies(fibonacci_callback_client
                 ${ros_beginner_tutorials_EXPORTED_TARGETS})

add_dependencies(fibonacci_class_client
                 ${ros_beginner_tutorials_EXPORTED_TARGETS})

add_dependencies(fibonacci_client ${ros_beginner_tutorials_EXPORTED_TARGETS})

add_dependencies(fibonacci_server ${ros_beginner_tutorials_EXPORTED_TARGETS})

add_dependencies(listener ros_beginner_tutorials_generate_messages_cpp)

add_dependencies(talker ros_beginner_tutorials_generate_messages_cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})

target_link_libraries(add_two_ints_server ${catkin_LIBRARIES})

target_link_libraries(averaging_client ${catkin_LIBRARIES})

target_link_libraries(averaging_server ${catkin_LIBRARIES})

target_link_libraries(basic_controls ${catkin_LIBRARIES})

target_link_libraries(basic_shapes ${catkin_LIBRARIES})

target_link_libraries(fibonacci_callback_client ${catkin_LIBRARIES})

target_link_libraries(fibonacci_class_client ${catkin_LIBRARIES})

target_link_libraries(fibonacci_client ${catkin_LIBRARIES})

target_link_libraries(fibonacci_server ${catkin_LIBRARIES})

target_link_libraries(frame_tf_broadcaster ${catkin_LIBRARIES})

target_link_libraries(listener ${catkin_LIBRARIES})

target_link_libraries(parser ${catkin_LIBRARIES})

target_link_libraries(pcl_example ${catkin_LIBRARIES})

target_link_libraries(points_and_lines ${catkin_LIBRARIES})

target_link_libraries(simple_marker ${catkin_LIBRARIES})

target_link_libraries(state_publisher ${catkin_LIBRARIES})

target_link_libraries(talker ${catkin_LIBRARIES})

target_link_libraries(tf_broadcaster ${catkin_LIBRARIES})

target_link_libraries(tf_listener ${catkin_LIBRARIES})

target_link_libraries(turtle_tf_broadcaster ${catkin_LIBRARIES})

target_link_libraries(turtle_tf_listener ${catkin_LIBRARIES})

target_link_libraries(turtle_tf_listener_debug ${catkin_LIBRARIES})

target_link_libraries(turtle_tf_message_filter ${catkin_LIBRARIES})

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )
catkin_install_python(
    PROGRAMS
    scripts/add_two_ints_client.py
    scripts/add_two_ints_server.py
    scripts/dynamic_tf_broadcaster.py
    scripts/fibonacci_client.py
    scripts/fibonacci_server.py
    scripts/fixed_tf_broadcaster.py
    scripts/gen_numbers.py
    scripts/listener.py
    scripts/talker.py
    scripts/turtle_tf_broadcaster.py
    scripts/turtle_tf_listener.py
    scripts/turtle_tf_message_broadcaster.py
    DESTINATION
    ${CATKIN_PACKAGE_BIN_DESTINATION})

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )
install(
    TARGETS add_two_ints_client
            add_two_ints_server
            averaging_client
            averaging_server
            basic_controls
            basic_shapes
            fibonacci_callback_client
            fibonacci_class_client
            fibonacci_client
            fibonacci_server
            frame_tf_broadcaster
            listener
            parser
            pcl_example
            points_and_lines
            simple_marker
            state_publisher
            talker
            tf_broadcaster
            tf_listener
            turtle_tf_broadcaster
            turtle_tf_listener
            turtle_tf_listener_debug
            turtle_tf_message_filter
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )
install(
    FILES launch/display.launch
          launch/start_debug_demo.launch
          launch/start_tf_demo.launch
          launch/start_tf_demo_py.launch
          launch/talk_and_listen.launch
          launch/turtle_tf_sensor.launch
          launch/turtlemimic.launch
          launch/urdf_display.launch
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_ros_beginner_tutorials.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
