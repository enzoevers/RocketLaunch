#pragma once

#include "ITransport.h"

//#define USE_SOFTWARE_SERIAL

#ifdef USE_SOFTWARE_SERIAL

// Software serial is half-duplex.
// This means not loopback-test can be performed
#include <SoftwareSerial.h>

#else

// When programming the Arduino, pin 0 and 1 may need to be disconnected.
#include <HardwareSerial.h>

#endif

enum class ReadState
{
  WaitForStart,
  ReadingMessage,
  MessageComplete
};

class SerialCom : public ITransport
{
  public:
    SerialCom(const uint8_t rxPin, const uint8_t txPin, const long baud, const char startChar, const char stopChar);

    //---------------
    // ITransport
    void Open() override;
    bool Update() override;
    size_t GetReceivedBuffer(uint8_t*& receiveBuffer) override;
    size_t SendBuffer(const uint8_t* sendBuffer, const size_t sendBufferSizeBytes) override;
    //---------------

  private:
    void ParseByte(const uint8_t receivedByte);

#ifdef USE_SOFTWARE_SERIAL
    SoftwareSerial m_mySerial;
#else
    HardwareSerial& m_mySerial = Serial;
#endif

    long m_baud = 115200;

    const char m_startChar = '#';
    const char m_stopChar = '%';

    ReadState m_readingState = ReadState::WaitForStart;
    bool m_newMessasge = false;

    size_t m_currentBufferIndex = 0;
    uint8_t m_receiveBufferProcessing[RECEIVE_BUFFER_SIZE] = {};
    uint8_t m_processedReceiveBuffer[RECEIVE_BUFFER_SIZE] = {};
    size_t m_processedReceiveBufferSize = 0;
};
