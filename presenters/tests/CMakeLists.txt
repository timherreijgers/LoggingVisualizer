add_executable(PresenterTests
        empty_test.cpp)

target_link_libraries(PresenterTests PRIVATE
        presenters
        gtest
        gtest_main)

target_include_directories(PresenterTests PRIVATE ../src)

add_test(NAME PresenterTests COMMAND PresenterTests)