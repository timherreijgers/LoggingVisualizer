add_subdirectory(tests)

set(MODEL_HEADERS
        include/model/ilog_message_filter.h
        include/model/ilog_data_context.h
        include/model/ifiltered_log_message_view.h

        include/model/log_data_context_factory.h
        include/model/log_level_color_settings_entry.h
        include/model/observable.h
        include/model/observable_map.h
        include/model/observable_vector.h
        include/model/settings_manager.h

        src/file_reader.h
        src/filtered_log_message_view.h
        src/ifile_reader.h
        src/log_data_context.h
        src/log_message_filter.h
)

set(MODEL_SRCS
        src/file_reader.cpp
        src/filtered_log_message_view.cpp
        src/log_data_context.cpp
        src/log_data_context_factory.cpp
        src/log_message_filter.cpp
        src/settings_manager.cpp
)

add_library(model STATIC
        ${MODEL_HEADERS}
        ${MODEL_SRCS}
)

target_include_directories(model PUBLIC include)

target_link_libraries(model
    PUBLIC
        libfastsignals
    PRIVATE
        types
        yaml-cpp::yaml-cpp
        fmt::fmt
)