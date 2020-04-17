//ringbuffer
#include "ringbuffer.h"

//std
#include <stdio.h>


int main(void)
{
    RingBuffer buf;
    RingBuffer_Init(&buf);
    printf("RingBuffer initialized with %d elements of free space\n", RingBuffer_GetFreeSpace(&buf));
    return 0;
}
