cmake_minimum_required(VERSION 3.10)
project(MAIN)

# Base dir
if(CLIENT_INSTALL_CMAKEDIR)
    set(src_base "${CMAKE_CURRENT_SOURCE_DIR}/${CLIENT_INSTALL_CMAKEDIR}")
else()
    set(src_base ${CMAKE_CURRENT_SOURCE_DIR})
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
execute_process (
    COMMAND bash -c "conan install ${src_base}"
    OUTPUT_VARIABLE test
)
message(${test})

add_definitions("-std=c++11")

# Include project
set(SOURCE_FILES ${src_base}/main.cpp)
include_directories(${src_base}/includes)

message(${CMAKE_BINARY_DIR})
include(${src_base}/conanbuildinfo.cmake)
conan_basic_setup()


add_library(curlpattern SHARED ${src_base}/curlpattern.cpp)
set_property(TARGET curlpattern
    APPEND
    PROPERTY
        LINK_LIBRARIES ${CONAN_LIBS}
)

add_executable(main ${SOURCE_FILES})
target_link_libraries(main curlpattern)