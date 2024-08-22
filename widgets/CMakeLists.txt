set(WIDGET_HEADERS
        include/item_models/log_level_highlight_model.h

        include/widgets/log_level_widget.h
        include/widgets/log_widget.h
        include/widgets/menubar.h
        include/widgets/toolbar.h

        include/windows/main_window.h
        include/windows/settings_window.h
        include/windows/window_manager.h)

set(WIDGET_SOURCES
        src/item_models/log_item_model.cpp
        src/item_models/log_item_model.h
        src/item_models/log_level_highlight_model.cpp

        src/windows/main_window.cpp
        src/windows/settings_window.cpp
        src/windows/window_manager.cpp

        src/widgets/log_level_widget.cpp
        src/widgets/log_widget.cpp
        src/widgets/menubar.cpp
        src/widgets/toolbar.cpp)

set(WIDGET_UI
        src/widgets/log_widget.ui
        src/widgets/menubar.ui
        src/widgets/toolbar.ui

        src/windows/main_window.ui
        src/windows/settings_window.ui
)

add_library(widgets STATIC
        ${WIDGET_HEADERS}
        ${WIDGET_SOURCES}
        ${WIDGET_UI})

target_include_directories(widgets PUBLIC include PRIVATE src)

target_link_libraries(widgets PRIVATE
        types
        fmt::fmt
        Qt6::Widgets)