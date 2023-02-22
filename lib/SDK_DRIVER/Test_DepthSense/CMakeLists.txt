project(Test_DepthSense)
cmake_minimum_required(VERSION 2.8)
#aux_source_directory(. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})


cmake_minimum_required(VERSION 2.8)
enable_language(CXX)
set(CMAKE_VERBOSE_MAKEFILE ON)

#if ("${CMAKE_BUILD_TYPE}" STREQUAL "debug")
#  set (CONFIG_EXT "d") #Extension corresponding to the configuration debug
#endif ("${CMAKE_BUILD_TYPE}" STREQUAL "debug")


# ----------------------------------------------------------------
# --- Customizable Part ------------------------------------------
# ----------------------------------------------------------------

set(CMAKE_INSTALL_PREFIX "/home/dyxcvi/Documents/INTERNSHIP/ds/lib/SDK_DRIVER/Test_DepthSense")

set(DEPTHSENSE_INCLUDE_DIR "/home/dyxcvi/Documents/INTERNSHIP/ds/lib/SDK_DRIVER/DepthSenseSDK/include")
set(DEPTHSENSE_LIBRARIES "/home/dyxcvi/Documents/INTERNSHIP/ds/lib/SDK_DRIVER/DepthSenseSDK/lib/libDepthSense.so.1.9.0")
set(DEPTHSENSE_PLUGINS_LIBRARIES "/home/dyxcvi/Documents/INTERNSHIP/ds/lib/SDK_DRIVER/DepthSenseSDK/lib/libDepthSensePlugins.so.1.9.0")
set(DEPTHSENSE_TURBOJPEG_LIBRARIES "/home/dyxcvi/Documents/INTERNSHIP/ds/lib/SDK_DRIVER/DepthSenseSDK/lib/libturbojpeg.so")

#set(GLUT_ROOT "C:/libraries/glut-3.7.6-bin")
#set(GLUT_INCLUDE_DIR "C:/libraries/glut-3.7.6-bin")
#set(GLUT_LIBRARIES "C:/libraries/glut-3.7.6-bin/glut32.lib")

# ----------------------------------------------------------------
# --- Project declaration ----------------------------------------
# ----------------------------------------------------------------

# Project declaration
set(PROJECT_ROOT Test_DepthSense)
set(PROJECT_NAME ${PROJECT_ROOT})
set(PROJECT_CONTACT arnaud.meline@gmail.com)
set(PROJECT_DESCRIPTION "Test_DepthSense")

set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "0")
set(PROJECT_VERSION_PATCH "0")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

set(PROJECT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_SRC_DIR "${PROJECT_ROOT_DIR}/src")
set(PROJECT_INCLUDE_DIR "${PROJECT_ROOT_DIR}/include")
set(PROJECT_NAME_BASE ${PROJECT_NAME})
set(PROJECT_NAME_EXE ${PROJECT_NAME_BASE})
set(PROJECT_NAME_VEXE ${PROJECT_NAME_BASE}-${PROJECT_VERSION})

project(${PROJECT_NAME})

# ----------------------------------------------------------------
# --- Modules ----------------------------------------------------
# ----------------------------------------------------------------

include(FindOpenGL)

#include(FindBoost)

# ----------------------------------------------------------------
# --- Source Files List ------------------------------------------
# ----------------------------------------------------------------

set(${PROJECT_NAME}_HEADERS

# ${PROJECT_INCLUDE_DIR}/Blabla.h

)

set(${PROJECT_NAME}_SRC

${PROJECT_SRC_DIR}/main.cpp
# ${PROJECT_SRC_DIR}/blabla.cpp

)



# ----------------------------------------------------------------
# --- Executable -------------------------------------------------
# ----------------------------------------------------------------

# set(CFLAGS -D_SCL_SECURE_NO_WARNINGS)
# add_definitions(${CFLAGS})

# include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${PROJECT_INCLUDE_DIR})
include_directories(${DEPTHSENSE_INCLUDE_DIR} ${PROJECT_INCLUDE_DIR} )

add_executable(${PROJECT_NAME_EXE} ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HEADERS})

# link_directories()

# target_link_libraries(${PROJECT_NAME_EXE} ${GLUT_LIBRARIES})
target_link_libraries(${PROJECT_NAME_EXE} ${DEPTHSENSE_LIBRARIES} ${DEPTHSENSE_PLUGINS_LIBRARIES} ${DEPTHSENSE_TURBOJPEG_LIBRARIES} )

#target_link_libraries(${PROJECT_NAME_EXE} ${DEPTHSENSE_LIBRARIES} )



install(TARGETS ${PROJECT_NAME_EXE} RUNTIME DESTINATION bin)










