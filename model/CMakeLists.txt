set(MODEL_HEADERS
        include/model/log_entry.h
        include/model/log_source.h)

set(MODEL_SRCS
        src/log_source.cpp)

add_library(model STATIC
        ${MODEL_HEADERS}
        ${MODEL_SRCS})

target_include_directories(model PUBLIC include)