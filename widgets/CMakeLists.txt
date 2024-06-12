set(WIDGET_HEADERS
        include/widgets/log_widget.h
        include/widgets/menubar.h

        include/windows/main_window.h
        include/windows/settings_window.h
        include/windows/window_manager.h)

set(WIDGET_SOURCES
        src/log_widget.cpp
        src/menubar.cpp

        src/windows/main_window.cpp
        src/windows/settings_window.cpp
        src/windows/window_manager.cpp)

set(WIDGET_UI
        src/log_widget.ui
        src/menubar.ui

        src/windows/main_window.ui
        src/windows/settings_window.ui
)

add_library(widgets STATIC
        ${WIDGET_HEADERS}
        ${WIDGET_SOURCES}
        ${WIDGET_UI})

target_include_directories(widgets PUBLIC include)

target_link_libraries(widgets PRIVATE
        types
        Qt6::Widgets)