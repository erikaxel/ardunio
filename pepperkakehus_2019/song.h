#ifndef Song_h
#define Song_h

class Song
{
  public:
    Song(int* tones, float* durations, int length, int speed)
        :tones(tones),
        durations(durations),
        length(length),
        speed(speed)
    {

    }
    int* tones;
    float* durations;
    int length;
    int speed;
  private:
};

Song* allIWantForChristmas(); 
Song* jingleBells();

#endif