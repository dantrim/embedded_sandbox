include_directories(inc)
set(HEADER_FILES
    ringbuffer.h
)
set(SOURCE_FILES
    ringbuffer.c
)
add_library(ringbuffer STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(ringbuffer PUBLIC ${CMAKE_CURRENT_LIST_DIR})
