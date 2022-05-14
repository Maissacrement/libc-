cmake_minimum_required(VERSION 3.10)

# set the project name
project(B)

# Base dir
if(LIBB_INSTALL_CMAKEDIR)
    set(src_base "${CMAKE_CURRENT_SOURCE_DIR}/${LIBB_INSTALL_CMAKEDIR}")
else()
    set(src_base ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# Include project
set(SOURCE_FILES ${src_base}/libB.cpp)
include_directories(${src_base}/includes)

# Create libs
add_library(B SHARED ${SOURCE_FILES})
add_library(B_static STATIC ${SOURCE_FILES})