cmake_minimum_required(VERSION 3.10)

## PROJECT NAME & VERSION
project(learn_cpp VERSION 1.0.1 LANGUAGES C CXX)

# 设置编译选项
# 允许c++11标准、O3优化、多线程。match选项可避免一些cpu上的问题
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread" )

#设置编译器
SET(CMAKE_CXX_COMPILER "g++")

# Add "Modules"
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Add flag
set(CMAKE_BUILD_TYPE Debug)
#set( CMAKE_BUILD_TYPE Release )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

# Add all binary files
aux_source_directory(src SRC_DIR)
aux_source_directory(src/advance SRC_ADVANCE)
#aux_source_directory(src/sort SRC_SORT)
#aux_source_directory(src/helper SRC_HELPER)
#aux_source_directory(src/sample SRC_SAMPLE)
#aux_source_directory(src/tcp SRC_TCP_DIR)

# Set all source
# ${SRC_MEDIA_SOUP} ${SRC_SORT} ${SRC_HELPER} ${SRC_SAMPLE} ${SRC_TCP_DIR}
set(ALL_SOURCE ${SRC_DIR} ${SRC_ADVANCE})
add_executable(learn_cpp ${ALL_SOURCE})

# Find xxx include directories and link libraries.
find_package(Event REQUIRED)
# find_package(SDL2 REQUIRED)
# find_package(FFMPEG COMPONENTS avcodec avformat avutil swscale swresample avfilter)

# Include module pkg-config for CMake.
INCLUDE(FindPkgConfig)

# Include dir
set(INCLUDES  includes/advance/  ${EVENT_INCLUDE_DIR})
include_directories(${INCLUDES})


# Link dirs
set(LIBRARIES ${EVENT_LIBRARIES})
target_link_libraries(learn_cpp  ${LIBRARIES})