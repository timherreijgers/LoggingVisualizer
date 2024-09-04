add_executable(LoggingVisualizer
        main.cpp

        resources/resoures.qrc
)

target_link_libraries(LoggingVisualizer PRIVATE
        widgets
        presenters
        model
        types
        Qt6::Widgets
)