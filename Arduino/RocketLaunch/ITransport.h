#pragma once

#include <stdint.h>
#include <stddef.h>

#define RECEIVE_BUFFER_SIZE 32

class ITransport
{
  public:
    virtual ~ITransport() = default;

    virtual void Open() = 0;

    // Process incoming data
    //
    // Return: true is a complete message is received (e.g. m_stopChar is received)
    virtual bool Update() = 0;

    virtual size_t GetReceivedBuffer(uint8_t*& receiveBuffer) = 0;

    // This function prepends the start character and appends the stop character
    // to the sendBuffer.
    //
    // sendBufferSizeBytes is the size of the sendBuffer. So without the start and stop characters
    //
    // Return: Number of bytes written. On succes this is sendBufferSizeBytes + 2 (2 for the start and stop characters)
    virtual size_t SendBuffer(const uint8_t* sendBuffer, const size_t sendBufferSizeBytes) = 0;
};
