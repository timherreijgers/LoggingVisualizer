cmake_minimum_required(VERSION 3.20)

project(LoggingVisualizer VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W3 /WX)
else ()
    add_compile_options(-Werror -Wextra -Wall -Wpedantic)
endif ()

enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(third-party)

add_subdirectory(application)
add_subdirectory(model)
add_subdirectory(presenters)
add_subdirectory(types)
add_subdirectory(widgets)