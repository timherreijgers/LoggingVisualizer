cmake_minimum_required(VERSION 3.20)

project(LoggingVisualizer VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Werror -Wextra -Wall -Wpedantic)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

add_executable(LoggingVisualizer main.cpp
        main_window.ui
        main_window.h
        main_window.cpp)

target_link_libraries(LoggingVisualizer PRIVATE Qt6::Core)
target_link_libraries(LoggingVisualizer PRIVATE Qt6::Gui)
target_link_libraries(LoggingVisualizer PRIVATE Qt6::Widgets)

#set_property(TARGET LoggingVisualizer PROPERTY AUTOMOC ON)