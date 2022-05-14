cmake_minimum_required(VERSION 3.10)

# set the project name
project(A)

# Base dir
if(LIBA_INSTALL_CMAKEDIR)
    set(src_base "${CMAKE_CURRENT_SOURCE_DIR}/${LIBA_INSTALL_CMAKEDIR}")
else()
    set(src_base ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# Include project
set(SOURCE_FILES ${src_base}/libB.cpp)
include_directories(${src_base}/includes)

# Create libs
add_library(A SHARED ${SOURCE_FILES})
add_library(A_static STATIC ${SOURCE_FILES})

