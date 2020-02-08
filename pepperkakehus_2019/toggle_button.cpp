#include "Arduino.h"
#include "toggle_button.h"

ToggleButton::ToggleButton(int pin, ToggleCallbackFunction callback)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _callback = callback;
}

void ToggleButton::loop() {
  int reading = digitalRead(_pin);
  
  if (reading == HIGH && _previous == LOW && millis() - _time > _debounce) {
    _state = !_state;
    _callback(_state);
    _time = millis();    
  }
  _previous = reading;
}
