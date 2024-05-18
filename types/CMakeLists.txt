set(TYPES_HEADERS include/types/log_entry.h)

add_library(types STATIC ${TYPES_HEADERS})

target_include_directories(types PUBLIC include)