set(MOCKS_HEADERS
        include/mocks/model/mock_filtered_log_message_view.hpp
        include/mocks/model/mock_log_data_context.hpp
        include/mocks/widgets/mock_log_widget.hpp
        include/mocks/windows/mock_window_manager.hpp
)

add_library(mocks STATIC
        ${MOCKS_HEADERS})

target_include_directories(mocks PUBLIC include)

target_link_libraries(mocks
        PUBLIC
        types
        widgets
        model
        presenters
        gtest
        gmock)