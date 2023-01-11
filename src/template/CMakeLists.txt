# Generic CMakeLists.txt for GLFW
cmake_minimum_required(VERSION 3.24)
project(1_1_hello_window)

set(CMAKE_CXX_STANDARD 17)

# Manually include our include directory so that we can find the appropriate header files
include_directories("../../../include/")

add_executable(${PROJECT_NAME}
        main.cpp glad.c)

# Tell CMake to link the current program and
target_link_libraries(${PROJECT_NAME}
        glfw)
