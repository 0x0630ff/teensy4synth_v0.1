// amp section
#include "Arduino.h"
// #include "setup.h"

float prevVol = 0.0;

void ampSetup(void) {
    amp1.gain(10);
}

void adjust_volume(void) {
    float AR = analogRead(15);
    double vol = AR / 1000;

    if (vol != prevVol) {
        Serial.print("Vol: ");
        Serial.println(vol);
        // amp1.gain(vol);
        sgtl5000_1.volume(vol);
        prevVol = vol;
    }
}
