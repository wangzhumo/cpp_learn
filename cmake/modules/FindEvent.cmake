if (EVENT_INCLUDE_DIR AND EVENT_LIBRARY)
    # Already in cache, be silent
    set(EVENT_FIND_QUIETLY TRUE)
endif (EVENT_INCLUDE_DIR AND EVENT_LIBRARY)

find_path(EVENT_INCLUDE_DIR event.h
        PATHS /usr/local/libevent
        PATH_SUFFIXES event2 include
        )

find_library(EVENT_LIBRARY
        NAMES event
        PATHS /usr/local/libevent/lib)

set(EVENT_LIBRARIES ${EVENT_LIBRARY} )

add_definitions(-DLIBNET_LIL_ENDIAN)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(EVENT
        DEFAULT_MSG
        EVENT_INCLUDE_DIR
        EVENT_LIBRARIES
        )

mark_as_advanced(EVENT_INCLUDE_DIR EVENT_LIBRARY)