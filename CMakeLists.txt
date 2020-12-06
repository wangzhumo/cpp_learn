cmake_minimum_required(VERSION 3.10)

## PROJECT NAME & VERSION
project(learn_cpp VERSION 1.0.1 LANGUAGES C CXX)

# 设置编译选项
# 允许c++11标准、O3优化、多线程。match选项可避免一些cpu上的问题
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread")

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
aux_source_directory(src/basic SRC_BASIC)
aux_source_directory(src/algorithm/sorts SRC_ALGORITHM_SORT)
aux_source_directory(src/algorithm/heap SRC_ALGORITHM_HEAP)
aux_source_directory(src/algorithm/search SRC_ALGORITHM_SEARCH)
aux_source_directory(src/leetcode SRC_ALGORITHM_LEETCODE)


# Set all source
set(ALL_SOURCE ${SRC_DIR} ${SRC_ADVANCE} ${SRC_BASIC}
        ${SRC_ALGORITHM_SORT} ${SRC_ALGORITHM_HEAP}
        ${SRC_ALGORITHM_SEARCH} ${SRC_ALGORITHM_LEETCODE})
add_executable(learn_cpp ${ALL_SOURCE})

# Find xxx include directories and link libraries.
# find_package(Event REQUIRED)
# find_package(SDL2 REQUIRED)
# find_package(FFMPEG COMPONENTS avcodec avformat avutil swscale swresample avfilter)

# Include module pkg-config for CMake.
# INCLUDE(FindPkgConfig)

# Include dir
# ${EVENT_INCLUDE_DIR}
set(INCLUDES includes/advance/ includes/basic/ includes/sorts/ includes/heap/ includes/search/)
set(LEETCODE includes/leetcode/)
include_directories(${INCLUDES} ${LEETCODE})


# Link dirs
set(LIBRARIES ${EVENT_LIBRARIES})
target_link_libraries(learn_cpp ${LIBRARIES})