add_executable(model_test
    observable_test.cpp)

target_link_libraries(model_test PRIVATE
        model
        gtest
        gtest_main
        gmock)

add_test(NAME ModelTest COMMAND model_test)