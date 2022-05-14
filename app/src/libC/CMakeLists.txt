cmake_minimum_required(VERSION 3.10)

# set the project name
project(C)

# Base dir
if(LIBC_INSTALL_CMAKEDIR)
    set(src_base "${CMAKE_CURRENT_SOURCE_DIR}/${LIBC_INSTALL_CMAKEDIR}")
else()
    set(src_base ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# Include project
set(SOURCE_FILES ${src_base}/libC.cpp)
include_directories(${src_base}/includes)

# Create libs
add_library(C SHARED ${SOURCE_FILES})
add_library(C_static STATIC ${SOURCE_FILES})