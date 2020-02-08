#include "Arduino.h"
#include "pitches.h"
#include "tune_player.h"

#define LED_BLINK_MILLIS 100

#define CHANNEL 0
#define RESOLUTION 8 // volume can be between 0-255

void mute()
{
  ledcWrite(CHANNEL, 0);
}

TunePlayer::TunePlayer(int buzzerPin, const int *ledPins, int ledPinsSize)
{
  _buzzerPin = buzzerPin;
  _ledPins = ledPins;
  _ledPinsSize = ledPinsSize;

  //pinMode(buzzerPin, OUTPUT);
  ledcSetup(CHANNEL, 2000, RESOLUTION);
  ledcAttachPin(buzzerPin, CHANNEL);
  mute();
  for (int i = 0; i < _ledPinsSize; i++)
  {
    pinMode(_ledPins[i], OUTPUT);
  }

  // Initialize songs
}

void TunePlayer::startTune(String name)
{
  if(name == "all_i_want_for_christmas") {
    _song = allIWantForChristmas();
  } else {
    _song = jingleBells();
  }

  // Debug
  Serial.print("Song length: ");
  Serial.println(_song->length);
  Serial.print("Song speed: ");
  Serial.println(_song->speed);
  Serial.print("Notes: ");
  for(int i=0;i<_song->length;i++) {
    Serial.print(_song->tones[i]);
    Serial.print(" ");
  }
  Serial.println("");
  Serial.print("Durations: ");
  for(int i=0;i<_song->length;i++) {
    Serial.print(_song->durations[i]);
    Serial.print(" ");
  }
  Serial.println("");
  
  if (!tunePlaying)
  {
    Serial.println("Start tune");
    _currentTone = -1;
    _currentLedPin = 0;
    tunePlaying = true;
  }
}

void TunePlayer::stopTune()
{
  Serial.println("Stop tune");

  mute();
  tunePlaying = false;

  for (int i = 0; i < _ledPinsSize; i++)
  {
    digitalWrite(_ledPins[i], LOW);
  }
}

void TunePlayer::loop()
{
  if (!tunePlaying)
  {
    return;
  }
  unsigned long currentMillis = millis();

  if (_currentTone + 1 >= _song->length && _currentToneStartedAt + (_song->speed / _song->durations[_currentTone]) < currentMillis)
  {
    stopTune();
    return;
  }

  if (_currentTone > 0 && _currentToneStartedAt + (_song->speed / _song->durations[_currentTone]) < (currentMillis + LED_BLINK_MILLIS))
  {
    for (int i = 0; i < _ledPinsSize; i++)
    {
      digitalWrite(_ledPins[i], LOW);
    }
  }

  if (_currentTone == -1 || _currentToneStartedAt + (_song->speed / _song->durations[_currentTone]) < currentMillis)
  {
    // Play the next note
    _currentTone++;
    _currentToneStartedAt = currentMillis;
    mute();
    if (_song->tones[_currentTone] != NOTE_PAUSE)
    {
      ledcWrite(CHANNEL, 128);
      ledcWriteTone(CHANNEL, _song->tones[_currentTone]);
      if (_ledPinsSize != 0)
      {
        digitalWrite(_ledPins[_currentLedPin], HIGH);
        _currentLedPin++;
        if (_currentLedPin >= _ledPinsSize)
        {
          _currentLedPin = 0;
        }
      }
    }
  }
  // Else we just keep on playing the current note
}
