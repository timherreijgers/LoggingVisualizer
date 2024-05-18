add_executable(LoggingVisualizer
        main.cpp
        main_window.cpp
        main_window.h
        main_window.ui)

target_link_libraries(LoggingVisualizer PRIVATE
        widgets
        presenters
        model
        types
        Qt6::Widgets
)