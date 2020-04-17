project("circular_buffer_mastering_stm32" C)
cmake_minimum_required(VERSION 3.8)

set(TARGET_GROUP test CACHE STRING "Group to build")

add_subdirectory(ringbuffer)

if(TARGET_GROUP STREQUAL production)
    message("production build")
    add_subdirectory(main)
elseif(TARGET_GROUP STREQUAL test)
    include(CTest)
    add_subdirectory(main)
    set(UNITY_DIR ../../unity build/)
    add_subdirectory(test)
    add_subdirectory(${UNITY_DIR})
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()
