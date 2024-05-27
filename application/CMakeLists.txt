add_executable(LoggingVisualizer
        main.cpp)

target_link_libraries(LoggingVisualizer PRIVATE
        widgets
        presenters
        model
        types
        Qt6::Widgets
)