add_subdirectory(tests)

if (WIN32)
    set(PLATFORM_SOURCES_HEADERS
            src/platform/windows/memory_mapped_file.cpp
            src/platform/windows/memory_mapped_file.h
    )
elseif (APPLE)
    set(PLATFORM_SOURCES_HEADERS
            src/platform/unix/memory_mapped_file.cpp
            src/platform/unix/memory_mapped_file.h
    )
elseif(UNIX)
    set(PLATFORM_SOURCES_HEADERS
            src/platform/unix/memory_mapped_file.cpp
            src/platform/unix/memory_mapped_file.h
    )
else()
    set(PLATFORM_SOURCES_HEADERS)
endif (WIN32)

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

        src/platform/memory_mapped_file.h

        src/generic_file_reader.h
        src/filtered_log_message_view.h
        src/ifile_reader.h
        src/log_data_context.h
        src/log_message_filter.h
        src/memory_mapped_file_parser.h
)

set(MODEL_SRCS
        src/generic_file_reader.cpp
        src/filtered_log_message_view.cpp
        src/log_data_context.cpp
        src/log_data_context_factory.cpp
        src/log_message_filter.cpp
        src/settings_manager.cpp
        src/memory_mapped_file_parser.cpp
)

add_library(model STATIC
        ${MODEL_HEADERS}
        ${MODEL_SRCS}
        ${PLATFORM_SOURCES_HEADERS}
)

target_include_directories(model PUBLIC include PRIVATE src)

target_link_libraries(model
    PUBLIC
        libfastsignals
        types
    PRIVATE
        yaml-cpp::yaml-cpp
        fmt::fmt
)

if (WIN32 OR APPLE OR UNIX)
    target_compile_definitions(model PRIVATE MEMORY_MAPPED_FILE_AVAILABLE=1)
else()
    target_compile_definitions(model PRIVATE MEMORY_MAPPED_FILE_AVAILABLE=0)
endif (WIN32 OR APPLE OR UNIX)