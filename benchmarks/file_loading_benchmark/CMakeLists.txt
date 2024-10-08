add_executable(FileLoadingBenchmark main.cpp)

target_link_libraries(FileLoadingBenchmark
    PRIVATE
        model
        benchmark::benchmark)

target_include_directories(FileLoadingBenchmark
    PRIVATE
        ${CMAKE_SOURCE_DIR}/model/src)