// filters
//
#include "Arduino.h"
// #include "setup.h"

void filterSetup(void){
    filter1.frequency(100);
    filter1.resonance(0.7);
}