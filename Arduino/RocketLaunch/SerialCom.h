#pragma once

#include "ITransport.h"

// When programming the Arduino, pin 0 and 1 may need to be disconnected.
#include <HardwareSerial.h>

class SerialCom : public ITransport
{
  public:
    SerialCom(const long baud, const char startChar, const char stopChar);

    //---------------
    // ITransport
    void open() override;
    bool update() override;
    size_t getReceivedBuffer(uint8_t*& receiveBuffer) override;
    size_t sendBuffer(const uint8_t* sendBuffer, const size_t sendBufferSizeBytes) override;
    //---------------

  private:
    void parseByte(const uint8_t receivedByte);

    HardwareSerial& m_mySerial = Serial;

    long m_baud = 115200;

    const char m_startChar = '#';
    const char m_stopChar = '%';

    enum class ReadState
    {
      WaitForStart,
      ReadingMessage,
      MessageComplete
    };

    ReadState m_readingState = ReadState::WaitForStart;
    bool m_newMessasge = false;

    size_t m_currentBufferIndex = 0;
    uint8_t m_receiveBufferProcessing[RECEIVE_BUFFER_SIZE] = {};
    uint8_t m_processedReceiveBuffer[RECEIVE_BUFFER_SIZE] = {};
    size_t m_processedReceiveBufferSize = 0;
};
