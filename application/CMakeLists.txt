add_executable(LoggingVisualizer main.cpp)

target_link_libraries(LoggingVisualizer PRIVATE
        Qt6::Widgets
        widgets)