cmake_minimum_required(VERSION 3.20)

project(LoggingVisualizer VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    message(STATUS "ccache found, using ccache")
    set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
endif()

include(cmake/util_functions.cmake)

setup_cpm()
download_dependencies()
setup_global_compile_options()

enable_testing()

option(BUILD_CODE_COVERAGE "Enable gcc code coverage" OFF)
if (${BUILD_CODE_COVERAGE})
    add_compile_options(-fprofile-arcs -ftest-coverage)
endif()

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(application)
add_subdirectory(benchmarks)
add_subdirectory(model)
add_subdirectory(presenters)
add_subdirectory(types)
add_subdirectory(widgets)