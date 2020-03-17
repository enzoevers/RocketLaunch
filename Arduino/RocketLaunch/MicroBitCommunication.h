#pragma once

#include "ITransport.h"

// The serial reader sees a 0 as a string null terminator and stops reading the data
// So the lowest subject ID is 1
enum class SendSubject
{
  PlayerCount = 1,
  GameMode = 2,
  Start = 3,
  Quit = 4,
  SubjectCount = 4
};

enum class ReceiveSubject
{
  Hit = 1,
  SubjectCount = 1
};

class MicroBitCommunication
{
  public:
    MicroBitCommunication(ITransport& communication, const uint8_t communicatioArduinoRxEnablePin, const uint8_t communicatioMicrobitRxSendEnablePin);

    void Start();
    void EnableCommunication();
    void DisableCommunication();

    void Update();
    bool OnTargetHit(void (*onTargetHitCallback)(const uint8_t player, const uint8_t points));
    void GiveNumPlayers(const uint8_t numPlayers);
    //void GiveGameMode(const uint8_t mode);
    void SendStart();
    void SendQuit();

  private:
    bool ParseReceiveBuffer(const uint8_t* buffer, size_t bufferSize);
    void CallCallback();

    const uint8_t m_communicatioArduinoRxEnablePin;
    const uint8_t m_communicatioMicrobitRxSendEnablePin;

    ITransport& m_communication;
    const char m_valueSeparator = ';';
    void (*m_onTargetHitCallback)(const uint8_t player, const uint8_t points);

    ReceiveSubject m_receivedSubject = ReceiveSubject::SubjectCount;
    uint8_t m_numReceivedValues = 0;
    uint8_t m_receivedValues[RECEIVE_BUFFER_SIZE] = {};
};
