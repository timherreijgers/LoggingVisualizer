add_subdirectory(tests)

set(PRESENTER_HEADERS
        include/presenters/base_presenter.hpp
        include/presenters/log_presenter.hpp
        include/presenters/menu_bar_presenter.hpp
        include/presenters/settings_log_level_presenter.hpp
        include/presenters/toolbar_presenter.hpp

        src/item_models/log_item_model.hpp
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

target_link_libraries(presenters
    PUBLIC
        types
        widgets
        model
    PRIVATE
        Qt6::Widgets)