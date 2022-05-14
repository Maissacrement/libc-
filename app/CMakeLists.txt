cmake_minimum_required(VERSION 3.10)

# set the project name
project(Helloworld)

set(LIBA_INSTALL_CMAKEDIR "src/libA" CACHE STRING "Installation directory for cmake config files")
set(LIBB_INSTALL_CMAKEDIR "src/libB" CACHE STRING "Installation directory for cmake config files")
set(LIBC_INSTALL_CMAKEDIR "src/libC" CACHE STRING "Installation directory for cmake config files")

# add the executable
include(${LIBA_INSTALL_CMAKEDIR}/CMakeLists.txt)
include(${LIBB_INSTALL_CMAKEDIR}/CMakeLists.txt)
include(${LIBC_INSTALL_CMAKEDIR}/CMakeLists.txt)
set_target_properties(A A_static B B_static C C_static PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../libs)

add_executable(Helloworld src/main.cpp)
target_link_libraries(Helloworld A)
target_link_libraries(Helloworld B)
target_link_libraries(Helloworld C)