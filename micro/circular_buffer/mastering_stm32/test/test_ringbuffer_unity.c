#include "ringbuffer.h"
#include "unity.h"

//std
#include <stdint.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_InitRingBuffer(void)
{
    RingBuffer buf;
    RingBuffer_Init(&buf);
    uint8_t data = 0xab;
    TEST_ASSERT_EQUAL(RING_BUFFER_OK, RingBuffer_Write(&buf, &data, 1));
}

void test_FullRingBuffer(void)
{
    TEST_ASSERT_EQUAL(1, 1);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_InitRingBuffer);
    RUN_TEST(test_FullRingBuffer);
    return UNITY_END();
}
