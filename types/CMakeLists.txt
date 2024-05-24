set(TYPES_HEADERS
        include/exceptions/FileNotFoundException.h
        include/types/log_entry.h)

add_library(types STATIC ${TYPES_HEADERS})

target_include_directories(types PUBLIC include)

target_link_libraries(types PUBLIC fmt::fmt)