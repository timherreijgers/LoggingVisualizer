add_executable(ModelTest
        mocks/mock_file_reader.hpp

        settings/settings_manager_group_log_level_test.cpp
        settings/settings_manager_test.cpp
        settings/settings_tree_test.cpp

        filtered_log_message_view_test.cpp
        log_data_context_test.cpp
        log_message_filter_test.cpp
        memory_mapped_file_parser_test.cpp
        model_gtest_printers.cpp
        model_gtest_printers.hpp)

target_link_libraries(ModelTest PRIVATE
        model
        gtest
        gtest_main
        gmock)

target_include_directories(ModelTest PRIVATE ../src .)

add_test(NAME ModelTest COMMAND ModelTest)