#ifndef RING_BUFFER_H
#define RING_BUFFER_H

//std
#include <stdint.h>
#include <stdbool.h>

//defines
#define RING_BUFFER_LEN 1024 // must be power of 2

typedef struct
{
    uint8_t buf[RING_BUFFER_LEN];
#if RING_BUFFER_LEN < 255
    uint8_t head, tail;
#else
    uint16_t head, tail;
#endif
} RingBuffer;

typedef enum
{
    RING_BUFFER_OK = 0x0
    ,RING_BUFFER_FULL
    ,RING_BUFFER_INSUFFICIENT_SPACE
} RingBuffer_Status;

uint16_t RingBuffer_GetDataLength(RingBuffer* buf);
uint16_t RingBuffer_GetFreeSpace(RingBuffer* buf);
void RingBuffer_Init(RingBuffer* buf);
void RingBuffer_Clear(RingBuffer* buf);
bool RingBuffer_IsFull(RingBuffer* buf);
uint16_t RingBuffer_Read(RingBuffer* buf, uint8_t* data, uint16_t len);
uint8_t RingBuffer_Write(RingBuffer* buf, uint8_t* data, uint16_t len);

#endif // RING_BUFFER_H
