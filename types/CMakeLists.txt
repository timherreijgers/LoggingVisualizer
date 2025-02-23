set(TYPES_HEADERS
        include/exceptions/FileNotFoundException.hpp

        include/types/color.hpp
        include/types/highlight_color_pair.hpp
        include/types/log_entry.hpp)

add_library(types STATIC ${TYPES_HEADERS})

target_include_directories(types PUBLIC include)

target_link_libraries(types PUBLIC fmt::fmt)