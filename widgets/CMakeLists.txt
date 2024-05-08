set(WIDGET_HEADERS
        include/log_widget.h
        include/main_window.h)

set(WIDGET_SOURCES
        src/log_widget.cpp
        src/main_window.cpp)

set(WIDGET_UI
        src/log_widget.ui
        src/main_window.ui)

add_library(widgets STATIC
        ${WIDGET_HEADERS}
        ${WIDGET_SOURCES}
        ${WIDGET_UI})

target_include_directories(widgets PUBLIC include)

target_link_libraries(widgets PRIVATE Qt6::Widgets)