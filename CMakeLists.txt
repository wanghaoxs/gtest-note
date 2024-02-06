#-----------------------------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project(gtest_tool LANGUAGES CXX VERSION 1.0.0)

# host information.
message("=============================================================")
cmake_host_system_information(RESULT HOSTNAME QUERY HOSTNAME)
message("hostname: ${HOSTNAME}")
message("rootpath: ${PROJECT_SOURCE_DIR}")
message("=============================================================")

# c++ settings.
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-std=c++17 -pthread -fopenmp")

# enable debug.
set(CMAKE_BUILD_TYPE Debug)
# used for add_library.
add_definitions(-fPIC)
# Convert relative paths to absolute for subdirectory `target_sources`
if(POLICY CMP0076)
    cmake_policy(SET CMP0076 NEW)
endif()

#-----------------------------------------------------------------------------------------------------------------------
# 3pp.

set(CUDA_INCLUDE "/usr/local/corex/include")

find_library(CUDA_LIBRARY cuda /usr/local/corex/lib64 NO_DEFAULT_PATH)
find_library(CUDART_LIBRARY cudart /usr/local/corex/lib64 NO_DEFAULT_PATH)

find_library(DL_LIBRARY dl)


message("==================================")
message("CUDA_INCLUDE=${CUDA_INCLUDE}")
message("==================================")
message("CUDA_LIBRARY=${CUDA_LIBRARY}")
message("CUDART_LIBRARY=${CUDART_LIBRARY}")
message("==================================")
message("DL_LIBRARY=${DL_LIBRARY}")
message("==================================")

#-----------------------------------------------------------------------------------------------------------------------
# set target.
add_executable(runTests)
target_include_directories(runTests PUBLIC
        gtest
        gtest/include
        include
        ${CUDA_INCLUDE}
        )
file(GLOB_RECURSE TEST_SRCS src/*.cpp)
target_sources(runTests PUBLIC
        gtest/src/gtest_main.cc
        gtest/src/gtest-all.cc
        ${TEST_SRCS}
        )
target_link_libraries(runTests PUBLIC
        ${CUDA_LIBRARY}
        ${CUDART_LIBRARY}
        ${DL_LIBRARY}
        )
