#include "MicroBitCommunication.h"

#include <Arduino.h>

//===============
// Constructor
//===============
MicroBitCommunication::MicroBitCommunication(ITransport& communication, const uint8_t communicatioArduinoRxEnablePin, const uint8_t communicatioMicrobitRxSendEnablePin,
                                              void (*targetHitCallback)(const uint8_t player, const uint8_t points))
  : m_communication(communication),
    m_communicatioArduinoRxEnablePin(communicatioArduinoRxEnablePin),
    m_communicatioMicrobitRxSendEnablePin(communicatioMicrobitRxSendEnablePin),
    m_targetHitCallback(targetHitCallback)
{

}

//===============
// Public functions
//===============

void MicroBitCommunication::start()
{
  pinMode(m_communicatioArduinoRxEnablePin, OUTPUT);
  pinMode(m_communicatioMicrobitRxSendEnablePin, INPUT);
  enableCommunication();
}

void MicroBitCommunication::enableCommunication()
{
  digitalWrite(m_communicatioArduinoRxEnablePin, HIGH);
}

void MicroBitCommunication::disableCommunication()
{
  digitalWrite(m_communicatioArduinoRxEnablePin, LOW);
}


void MicroBitCommunication::update()
{
  if (m_communication.update())
  {
    uint8_t* receiveBufferPtr;
    size_t bufferSize = m_communication.getReceivedBuffer(receiveBufferPtr);
    if (receiveBufferPtr != nullptr)
    {
      if (parseReceiveBuffer(receiveBufferPtr, bufferSize))
      {
        callCallback();
      }
    }
  }
}

void MicroBitCommunication::giveNumPlayers(const uint8_t numPlayers)
{
  const uint8_t numPlayersBuf[] = {static_cast<uint8_t>(SendSubject::PlayerCount), m_valueSeparator, numPlayers};
  while(digitalRead(m_communicatioMicrobitRxSendEnablePin) == LOW){};
  m_communication.sendBuffer(numPlayersBuf, sizeof(numPlayersBuf) / sizeof(numPlayersBuf[0]));
}

void MicroBitCommunication::sendStart()
{
  const uint8_t buf[] = {static_cast<uint8_t>(SendSubject::Start)};
  while(digitalRead(m_communicatioMicrobitRxSendEnablePin) == LOW){};
  m_communication.sendBuffer(buf, sizeof(buf) / sizeof(buf[0]));
}

void MicroBitCommunication::sendQuit()
{
  const uint8_t buf[] = {static_cast<uint8_t>(SendSubject::Quit)};
  while(digitalRead(m_communicatioMicrobitRxSendEnablePin) == LOW){};
  m_communication.sendBuffer(buf, sizeof(buf) / sizeof(buf[0]));
}

//===============
// Private functions
//===============

void MicroBitCommunication::callCallback()
{
  switch (m_receivedSubject)
  {
    case ReceiveSubject::Hit:
      {
        m_targetHitCallback(m_receivedValues[0], m_receivedValues[1]);
        break;
      }
    default:
      {
        break;
      }
  };
}

bool MicroBitCommunication::parseReceiveBuffer(const uint8_t* buffer, size_t bufferSize)
{
  uint8_t numValues = 0;
  uint8_t numValuesFound = 0;

  // This assumes that the subject is sent as the enum value is the form
  // of the actual number (e.g. the first enum value, which is 0, is sent as 0x00)

  uint8_t subjectInt = buffer[0];
  if (subjectInt == 0 || subjectInt > static_cast<uint8_t>(ReceiveSubject::SubjectCount))
  {
    return false;
  }

  m_receivedSubject = static_cast<ReceiveSubject>(subjectInt);

  switch (m_receivedSubject)
  {
    case ReceiveSubject::Hit:
      {
        numValues = 2;
        break;
      }
    default:
      {
        break;
      }
  };

  // This assumes that all values are of type uint8_t
  // i starts at 1 since buffer[0] is the subject
  for (int i = 1; i < bufferSize && numValuesFound < numValues; i++)
  {
    uint8_t receivedByte = buffer[i];
    if (receivedByte == m_valueSeparator)
    {
      i++;
      m_receivedValues[numValuesFound] = buffer[i];
      numValuesFound++;
    }
  }

  bool success = false;
  if (numValuesFound == numValues)
  {
    m_numReceivedValues = numValues;
    success = true;
  }

  return success;
}
