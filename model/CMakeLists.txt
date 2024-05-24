add_subdirectory(tests)

set(MODEL_HEADERS
        include/model/log_data_context.h
        include/model/observable.h

        src/file_reader.h)

set(MODEL_SRCS
        src/log_data_context.cpp
        src/file_reader.cpp)

add_library(model STATIC
        ${MODEL_HEADERS}
        ${MODEL_SRCS})

target_include_directories(model PUBLIC include)

target_link_libraries(model PRIVATE
        types
)