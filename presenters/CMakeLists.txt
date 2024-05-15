set(PRESENTER_HEADERS include/presenters/log_presenter.h)

set(PRESENTER_SRCS src/log_presenter.cpp)

add_library(presenters STATIC
        ${PRESENTER_HEADERS}
        ${PRESENTER_SRCS})

target_include_directories(presenters PUBLIC include)