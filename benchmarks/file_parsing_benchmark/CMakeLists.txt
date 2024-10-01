add_executable(FileParsingBenchmark main.cpp)

target_link_libraries(FileParsingBenchmark
    PRIVATE
        model
        benchmark::benchmark)

target_include_directories(FileParsingBenchmark
    PRIVATE
        ${CMAKE_SOURCE_DIR}/model/src)