set(MODEL_HEADERS include/model/log_entry.h)

set(MODEL_SRCS include/model/log_entry.h)

add_library(model STATIC
        ${MODEL_HEADERS}
        ${MODEL_SRCS})

target_include_directories(model PUBLIC include)