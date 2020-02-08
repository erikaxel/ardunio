#ifndef TunePlayer_h
#define TunePlayer_h

#include "song.h"

class TunePlayer
{
  public:
    TunePlayer(int buzzerPin, const int *ledPins, int ledPinsSize);
    void loop();
    void startTune(String name);
    void stopTune();
    bool tunePlaying;
  private:
    int _buzzerPin;
    unsigned long _currentToneStartedAt;
    int _currentTone;
    const int *_ledPins;
    int _ledPinsSize;
    int _currentLedPin;
    Song *_song;
};

#endif
