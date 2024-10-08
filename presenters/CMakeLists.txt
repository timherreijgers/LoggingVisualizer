set(PRESENTER_HEADERS
        include/presenters/base_presenter.h
        include/presenters/log_presenter.h
        include/presenters/menu_bar_presenter.h
        include/presenters/settings_log_level_presenter.h
        include/presenters/toolbar_presenter.h

        src/item_models/log_item_model.h
)

set(PRESENTER_SRCS
        src/item_models/log_item_model.cpp

        src/base_presenter.cpp
        src/log_presenter.cpp
        src/menu_bar_presenter.cpp
        src/settings_log_level_presenter.cpp
        src/toolbar_presenter.cpp
)

add_library(presenters STATIC
        ${PRESENTER_HEADERS}
        ${PRESENTER_SRCS})

target_include_directories(presenters PUBLIC include PRIVATE src)

target_link_libraries(presenters PRIVATE
        widgets
        model
        types
        Qt6::Widgets)