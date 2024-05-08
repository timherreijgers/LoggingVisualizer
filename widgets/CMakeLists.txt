set(WIDGET_HEADERS
        include/widgets/log_widget.h)

set(WIDGET_SOURCES
        src/log_widget.cpp)

set(WIDGET_UI
        src/log_widget.ui)

add_library(widgets STATIC
        ${WIDGET_HEADERS}
        ${WIDGET_SOURCES}
        ${WIDGET_UI})

target_include_directories(widgets PUBLIC include)

target_link_libraries(widgets PRIVATE Qt6::Widgets)