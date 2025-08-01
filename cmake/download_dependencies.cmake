function(download_dependencies)
    SET(CPM_SOURCE_CACHE ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
    set(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTING OFF)
    set(BENCHMARK_ENABLE_TESTING OFF)

    CPMAddPackage("gh:timherreijgers/FastSignals#ea71756889c576dcae5e08b34850e0a000ebf663")
endfunction()