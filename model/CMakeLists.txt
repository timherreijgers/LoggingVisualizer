add_subdirectory(tests)

set(MODEL_HEADERS
        include/model/log_data_context.h
        include/model/log_level_color_settings.h
        include/model/observable.h
        include/model/observable_map.h
        include/model/settings_manager.h

        src/file_reader.h
)

set(MODEL_SRCS
        src/log_data_context.cpp
        src/file_reader.cpp
        src/settings_manager.cpp
)

add_library(model STATIC
        ${MODEL_HEADERS}
        ${MODEL_SRCS}
)

target_include_directories(model PUBLIC include)

target_link_libraries(model PRIVATE
        types
)