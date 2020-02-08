#ifndef Toggle_button_h
#define Toggle_button_h

typedef void (*ToggleCallbackFunction) (bool toggle);

class ToggleButton
{
  public:
    ToggleButton(int pin, ToggleCallbackFunction callback);
    void loop();
  private:
    int _pin;
    long _time = 0;         // the last time the output pin was toggled
    long _debounce = 200;   // the debounce time, increase if the output flickers
    int _previous = LOW; 
    bool _state;
    // int state = HIGH;      // the current state of the output pin
    // int outPin = 13;

    ToggleCallbackFunction _callback;
};

#endif
