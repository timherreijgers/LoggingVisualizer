set(PRESENTER_HEADERS include/log_presenter.h)

set(PRESENTER_SRCS include/log_presenter.h)

add_library(presenters STATIC
        ${PRESENTER_HEADERS}
        ${PRESENTER_SRCS})

target_include_directories(presenters PUBLIC include)