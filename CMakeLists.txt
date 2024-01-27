cmake_minimum_required(VERSION 3.20)

project(LoggingVisualizer VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Werror -Wextra -Wall -Wpedantic)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(LoggingVisualizer main.cpp)

target_link_libraries(LoggingVisualizer PRIVATE Qt6::Core)