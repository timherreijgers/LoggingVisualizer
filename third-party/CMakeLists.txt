set(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF)

add_subdirectory(fast_signals)
add_subdirectory(fmt)
add_subdirectory(googletest)
add_subdirectory(yaml-cpp)