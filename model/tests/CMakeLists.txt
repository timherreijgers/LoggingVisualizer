add_executable(ModelTest
        mocks/mock_file_reader.h

        filtered_log_message_view_test.cpp
        log_data_context_test.cpp
        log_message_filter_test.cpp
        memory_mapped_file_parser_test.cpp)

target_link_libraries(ModelTest PRIVATE
        model
        gtest
        gtest_main
        gmock)

target_include_directories(ModelTest PRIVATE ../src)

add_test(NAME ModelTest COMMAND ModelTest)