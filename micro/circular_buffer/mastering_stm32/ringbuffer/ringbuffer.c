//std
#include <string.h>

//ringbuffer
#include "ringbuffer.h"

void RingBuffer_Init(RingBuffer* buf)
{
    buf->head = buf->tail = 0;
    memset(buf->buf, 0, RING_BUFFER_LEN);
}

void RingBuffer_Clear(RingBuffer* buf)
{
    uint8_t tmp;
    while(RingBuffer_GetDataLength(buf)>0)
    {
        RingBuffer_Read(buf, &tmp, 1);
    }
}

bool RingBuffer_IsFull(RingBuffer* buf)
{
    return RingBuffer_GetFreeSpace(buf) == 0;
}

uint16_t RingBuffer_Read(RingBuffer* buf, uint8_t* data, uint16_t len)
{
    uint16_t counter = 0;
    while(buf->tail != buf->head && counter < len)
    {
        data[counter++] = buf->buf[buf->tail];
        buf->tail = (buf->tail + 1) % RING_BUFFER_LEN;
    }
    return counter;
}

uint8_t RingBuffer_Write(RingBuffer* buf, uint8_t* data, uint16_t len)
{
    uint16_t counter = 0;
    uint16_t free_space = RingBuffer_GetFreeSpace(buf);

    // buffer is full, do not write
    if(free_space == 0)
    {
        return RING_BUFFER_FULL;
    }
    else if(free_space < len)
    {
        return RING_BUFFER_INSUFFICIENT_SPACE;
    }

    while(counter < len)
    {
        buf->buf[buf->head] = data[counter++];
        buf->head = (buf->head + 1) % RING_BUFFER_LEN;
    }
    return RING_BUFFER_OK;
}

uint16_t RingBuffer_GetFreeSpace(RingBuffer* buf)
{
    if(buf->tail == buf->head)
    {
        return RING_BUFFER_LEN - 1;
    }

    if(buf->head > buf->tail)
    {
        return RING_BUFFER_LEN - ((buf->head - buf->tail) + 1);
    }
    else
    {
        return (buf->tail - buf->head) - 1;
    }
}

uint16_t RingBuffer_GetDataLength(RingBuffer* buf)
{
    return RING_BUFFER_LEN - (RingBuffer_GetFreeSpace(buf) + 1);
}
