add_subdirectory(tests)

if (WIN32)
    set(PLATFORM_SOURCES_HEADERS
            src/platform/windows/memory_mapped_file.cpp
            src/platform/windows/memory_mapped_file.hpp
    )
elseif (APPLE)
    set(PLATFORM_SOURCES_HEADERS
            src/platform/unix/memory_mapped_file.cpp
            src/platform/unix/memory_mapped_file.hpp
    )
elseif(UNIX)
    set(PLATFORM_SOURCES_HEADERS
            src/platform/unix/memory_mapped_file.cpp
            src/platform/unix/memory_mapped_file.hpp
    )
else()
    set(PLATFORM_SOURCES_HEADERS)
endif (WIN32)

set(MODEL_HEADERS
        include/model/ilog_message_filter.hpp
        include/model/ilog_data_context.hpp
        include/model/ifiltered_log_message_view.hpp

        include/model/log_data_context_factory.hpp
        include/model/log_level_color_settings_entry.hpp
        include/model/settings_manager.hpp
        include/model/signal.hpp

        src/platform/memory_mapped_file.hpp

        src/generic_file_reader.hpp
        src/filtered_log_message_view.hpp
        src/ifile_reader.hpp
        src/log_data_context.hpp
        src/log_message_filter.hpp
        src/memory_mapped_file_parser.hpp
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