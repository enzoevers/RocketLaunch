#pragma once

#include <stdint.h>
#include <stddef.h>

#define RECEIVE_BUFFER_SIZE 16

class ITransport
{
  public:
    virtual ~ITransport() = default;

    virtual void open() = 0;

    // Process incoming data
    //
    // Return: true is a complete message is received (e.g. m_stopChar is received)
    virtual bool update() = 0;

    virtual size_t getReceivedBuffer(uint8_t*& receiveBuffer) = 0;

    // This function prepends the start character and appends the stop character
    // to the sendBuffer.
    //
    // sendBufferSizeBytes is the size of the sendBuffer. So without the start and stop characters
    //
    // Return: Number of bytes written. On succes this is sendBufferSizeBytes + 2 (2 for the start and stop characters)
    virtual size_t sendBuffer(const uint8_t* sendBuffer, const size_t sendBufferSizeBytes) = 0;
};
