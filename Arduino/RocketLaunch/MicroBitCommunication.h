#pragma once

#include "ITransport.h"

enum class SendSubject
{
  PlayerCount = 0,
  GameMode = 1,
  Start = 2,
  Quit = 3,
  SubjectCount
};

enum class ReceiveSubject
{
  Hit = 0,
  SubjectCount
};

class MicroBitCommunication
{
  public:
    MicroBitCommunication(ITransport& communication, const uint8_t communicationEnablePin);

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

    const uint8_t m_communicationEnablePin;

    ITransport& m_communication;
    const char m_valueSeparator = ';';
    void (*m_onTargetHitCallback)(const uint8_t player, const uint8_t points);

    ReceiveSubject m_receivedSubject = ReceiveSubject::SubjectCount;
    uint8_t m_numReceivedValues = 0;
    uint8_t m_receivedValues[RECEIVE_BUFFER_SIZE] = {};
};
