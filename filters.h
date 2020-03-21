// filters
//
#include "Arduino.h"
// #include "setup.h"

void filterSetup(void) {
    filter1.frequency(100);
    filter1.resonance(0.6);
    filter1.octaveControl(0.5);
}

void sweepFilter(void) {
    float AR = analogRead(15);
    double freq = map(AR, 0, 1023, 60, 10000);
    filter1.frequency(freq);
    Serial.println(freq);
}
