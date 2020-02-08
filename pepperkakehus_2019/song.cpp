#include <algorithm>
#include "pitches.h"
#include "song.h"

Song *allIWantForChristmas()
{
    int speed = 3000;
    int tones[] = {
        NOTE_A3, NOTE_A3,
        NOTE_G3, NOTE_B3, NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4,
        NOTE_PAUSE, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4,
        NOTE_PAUSE, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
        NOTE_PAUSE, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_DS4, NOTE_D4,
        NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_G4, NOTE_E4, NOTE_FS4, NOTE_DS4,
        NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_DS4,
        NOTE_PAUSE, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_D5, NOTE_D5, NOTE_C5,
        NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_DS4, NOTE_A4, NOTE_B4,
        NOTE_G4,
        NOTE_PAUSE};
    int length = sizeof(tones) / sizeof(tones[0]);
    float durations[] = {
        8, 16,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 5.34, 16, 8, 8, 8, 8, 8,
        8, 16, 16, 8, 16, 5.34, 8, 16, 5.34,
        8, 16, 16, 16, 16, 8, 8, 8, 16, 5.34,
        8, 8, 8, 8, 8, 8, 4,
        8, 16, 16, 8, 8, 8, 8, 4,
        8, 16, 16, 8, 8, 8, 2.67,
        8, 8, 8, 8, 8, 4, 8,
        1,
        1};

    int *pTones = new int[length];
    float *pDurations = new float[length];

    for (int i = 0; i < length; i++)
    {
        pTones[i] = tones[i];
        pDurations[i] = durations[i];
    }
    return new Song(pTones, pDurations, length, speed);
}

Song *jingleBells()
{
    int speed = 1000;
    int tones[] = {
        NOTE_G3, NOTE_E4, NOTE_D4, NOTE_C4,
        NOTE_G3, NOTE_G3, NOTE_G3,
        NOTE_G3, NOTE_E4, NOTE_D4, NOTE_C4,
        NOTE_A3, NOTE_PAUSE,
        NOTE_A3, NOTE_F4, NOTE_E4, NOTE_D4,
        NOTE_B3, NOTE_PAUSE,
        NOTE_G4, NOTE_G4, NOTE_F4, NOTE_D4,
        NOTE_E4, NOTE_PAUSE,

        NOTE_G3, NOTE_E4, NOTE_D4, NOTE_C4,
        NOTE_G3,
        NOTE_G3, NOTE_E4, NOTE_D4, NOTE_C4,
        NOTE_A3, NOTE_A3,
        NOTE_A3, NOTE_F4, NOTE_E4, NOTE_D4,
        NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
        NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4,
        NOTE_C4, NOTE_G4,

        NOTE_E4, NOTE_E4, NOTE_E4,
        NOTE_E4, NOTE_E4, NOTE_E4,
        NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4,
        NOTE_E4, NOTE_PAUSE,
        NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
        NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
        NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4,
        NOTE_D4, NOTE_G4,

        NOTE_E4, NOTE_E4, NOTE_E4,
        NOTE_E4, NOTE_E4, NOTE_E4,
        NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4,
        NOTE_E4, NOTE_PAUSE,

        NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
        NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
        NOTE_G4, NOTE_G4, NOTE_F4, NOTE_D4,
        NOTE_C4};
    int length = sizeof(tones) / sizeof(tones[0]);
    float durations[] = {
        4, 4, 4, 4,
        2, 8, 8,
        4, 4, 4, 4,
        1.333, 4,
        4, 4, 4, 4,
        1.333, 4,
        4, 4, 4, 4,
        1.333, 4,

        4, 4, 4, 4,
        1,
        4, 4, 4, 4,
        1.333, 4,
        4, 4, 4, 4,
        4, 4, 4, 4,
        4, 4, 4, 4,
        2, 2,

        4, 4, 2,
        4, 4, 2,
        4, 4, 2.667, 8,
        1.333, 4,
        4, 4, 2.667, 8,
        4, 4, 4, 8, 8,
        4, 4, 4, 4,
        2, 2,

        4, 4, 2,
        4, 4, 2,
        4, 4, 2.667, 8,
        1.333, 4,
        4, 4, 2.667, 8,
        4, 4, 4, 8, 8,
        4, 4, 4, 4,
        1};

    int *pTones = new int[length];
    float *pDurations = new float[length];

    for (int i = 0; i < length; i++)
    {
        pTones[i] = tones[i];
        pDurations[i] = durations[i];
    }
    return new Song(pTones, pDurations, length, speed);
}