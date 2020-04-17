add_executable(test_ringbuffer_unity test_ringbuffer_unity.c)
target_link_libraries(test_ringbuffer_unity
    ringbuffer
    unity
)
add_test(test_ringbuffer test_ringbuffer_unity)
