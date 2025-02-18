add_executable(PresenterTests
        log_presenter_test.cpp
        menu_bar_presenter_test.cpp
        settings_log_level_presenter_test.cpp
        toolbar_presenter_test.cpp)

target_link_libraries(PresenterTests PRIVATE
        presenters
        mocks
        gtest
        gtest_main)

target_include_directories(PresenterTests PRIVATE ../src)

add_test(NAME PresenterTests COMMAND PresenterTests)