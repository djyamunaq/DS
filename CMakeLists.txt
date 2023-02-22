cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ds)

option(BUILD_TESTS "Build tests." OFF)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/" ${CMAKE_MODULE_PATH})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(PCL 1.7.2 REQUIRED)

# ADD DSSDK
set(DEPTHSENSE_INCLUDE_DIR "/opt/softkinetic/DepthSenseSDK/include")
set(DEPTHSENSE_LIBRARIES "/opt/softkinetic/DepthSenseSDK/lib/libDepthSense.so")
set(DEPTHSENSE_PLUGINS_LIBRARIES "/opt/softkinetic/DepthSenseSDK/lib/libDepthSensePlugins.so")
set(DEPTHSENSE_TURBOJPEG_LIBRARIES "/opt/softkinetic/DepthSenseSDK/lib/libturbojpeg.so")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
  include
  ${PCL_INCLUDE_DIRS}
  ${DEPTHSENSE_INCLUDE_DIR}
)

link_directories(
  ${PCL_LIBRARY_DIRS}
  ${DEPTHSENSE_LIBRARIES}
)

add_definitions(
  ${PCL_DEFINITIONS}
)

# add_library(depth_sense
#   src/depth_sense/depth_sense_device_manager.cpp
#   src/depth_sense/depth_sense_grabber_impl.cpp
#   src/depth_sense_grabber.cpp
#   src/io_exception.cpp
# )
# target_include_directories(depth_sense PUBLIC 
#   ${PCL_INCLUDE_DIRS} 
#   ${DEPTHSENSE_INCLUDE_DIR} 
#   /home/dyxcvi/Documents/INTERNSHIP/ds/include/
# )
# target_link_libraries(depth_sense
#   depth_sense
#   ${PCL_LIBRARIES}
#   ${DEPTHSENSE_LIBRARIES}
# )

add_executable(depth_sense_viewer
  src/depth_sense_viewer.cpp
)
target_include_directories(depth_sense_viewer PUBLIC 
  /home/dyxcvi/Documents/INTERNSHIP/ds/include/
  ${PCL_INCLUDE_DIRS} 
  ${DEPTHSENSE_INCLUDE_DIR} 
)
target_link_libraries(depth_sense_viewer
  # depth_sense
  ${PCL_LIBRARIES}
  ${DEPTHSENSE_LIBRARIES}
)

# add_executable(multi_grabber
#   src/multi_grabber.cpp
# )
# target_link_libraries(multi_grabber
#   depth_sense
#   ${PCL_LIBRARIES}
#   DEPTHSENSE_LIBRARIES
# )

if (BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

 