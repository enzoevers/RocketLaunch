#include "SerialCom.h"

//===============
// Constructor
//===============
SerialCom::SerialCom(const uint8_t rxPin, const uint8_t txPin, const long baud, const char startChar, const char stopChar)
  :
#ifdef USE_SOFTWARE_SERIAL
  m_mySerial(rxPin, txPin),
#endif
  m_startChar(startChar),
  m_stopChar(stopChar)
{
  // Validate that the baud rate is supported as listed here:
  // https://www.arduino.cc/en/Reference/SoftwareSerialBegin
  //
  // Otherwise default to the default of m_baud
  switch (baud)
  {
    case 300: {
        m_baud = baud;
        break;
      }
    case 600: {
        m_baud = baud;
        break;
      }
    case 1200: {
        m_baud = baud;
        break;
      }
    case 2400: {
        m_baud = baud;
        break;
      }
    case 4800: {
        m_baud = baud;
        break;
      }
    case 9600: {
        m_baud = baud;
        break;
      }
    case 14400: {
        m_baud = baud;
        break;
      }
    case 19200: {
        m_baud = baud;
        break;
      }
    case 28800: {
        m_baud = baud;
        break;
      }
    case 31250: {
        m_baud = baud;
        break;
      }
    case 38400: {
        m_baud = baud;
        break;
      }
    case 57600: {
        m_baud = baud;
        break;
      }
    case 115200: {
        m_baud = baud;
        break;
      }
    default: {
        break;  // Keep m_baud at its default value
      }
  };
}

//===============
// Public functions
//===============

void SerialCom::Open()
{
  m_mySerial.begin(m_baud);
}

bool SerialCom::Update()
{
  if (m_mySerial.available())
  {
    uint8_t receivedByte = m_mySerial.read();
    ParseByte(receivedByte);
  }

  return m_newMessasge;
}

size_t SerialCom::GetReceivedBuffer(uint8_t*& receiveBuffer)
{
  // When this function is called, the latest received message is returned,
  // meaning that there no longer is a new message available.
  m_newMessasge = false;

  receiveBuffer = m_processedReceiveBuffer;

  return m_processedReceiveBufferSize;
}

size_t SerialCom::SendBuffer(const uint8_t* sendBuffer, const size_t sendBufferSizeBytes)
{
  size_t sendCount = 0;

  sendCount += m_mySerial.write(m_startChar);
  sendCount += m_mySerial.write(sendBuffer, sendBufferSizeBytes);
  sendCount += m_mySerial.write(m_stopChar);

  return sendCount;
}


//===============
// Private functions
//===============

void SerialCom::ParseByte(const uint8_t receivedByte)
{
  switch (m_readingState)
  {
    case ReadState::WaitForStart:
      {
        if (receivedByte == m_startChar)
        {
          m_currentBufferIndex = 0;
          m_readingState = ReadState::ReadingMessage;
        }

        break;
      }
    case ReadState::ReadingMessage:
      {
        if (receivedByte == m_stopChar)
        {
          m_readingState = ReadState::MessageComplete;
        }
        else
        {
          m_receiveBufferProcessing[m_currentBufferIndex++] = receivedByte;

          // Some bytes were probably lost
          if (m_currentBufferIndex == RECEIVE_BUFFER_SIZE)
          {
            m_readingState = ReadState::WaitForStart;
          }
        }

        break;
      }
  };

  if (m_readingState == ReadState::MessageComplete)
  {
    // Copy the 'skretchpad' message to the processed message
    if (memcpy(m_processedReceiveBuffer, m_receiveBufferProcessing, m_currentBufferIndex) == nullptr)
    {
      m_processedReceiveBufferSize = 0;
      m_newMessasge = false;
    }
    else
    {
      m_processedReceiveBufferSize = m_currentBufferIndex;
      m_newMessasge = true;
    }

    m_readingState = ReadState::WaitForStart;
  }
}
