set(WIDGET_HEADERS
        include/widgets/item_models/abstract_item_model.hpp
        include/widgets/item_models/log_level_highlight_model.hpp

        include/widgets/log_level_widget.hpp
        include/widgets/log_widget.hpp
        include/widgets/menubar.hpp
        include/widgets/toolbar.hpp

        include/windows/main_window.hpp
        include/windows/settings_window.hpp
        include/windows/window_manager.hpp

        src/item_models/log_item_model.hpp)

set(WIDGET_SOURCES
        src/item_models/log_item_model.cpp
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