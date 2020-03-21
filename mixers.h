// Mixer section.
// for set up of all the mixers in the set up.
#include "Arduino.h"

void mixerSetup(void) {
    // mixer1 
    // adds main waveforms and sine fm.
    float WAVEFORM1 = 0.8;
    float WAVEFORM2 = 0.8;
    float SINEFM2 = 0.8;
    float SINEFM1 = 0.8;
    mixer1.gain(0, WAVEFORM1);
    mixer1.gain(1, SINEFM1);
    mixer1.gain(2, WAVEFORM2);
    mixer1.gain(3, SINEFM2);

    // mixer2
    // adds in pwm with lfo
    float PWM1 = 0.0;
    float PWM2 = 0.0;
    mixer2.gain(0, PWM1);
    mixer2.gain(1, PWM2);
    

    // mixer 3
    // adds together the previous two mixers for all voices to join
    float SYNTHMIX1 = 0.9;
    float SYNTHMIX2 = 0.0;
    mixer3.gain(0, SYNTHMIX1);
    mixer3.gain(1, SYNTHMIX2);


    // mixer 4
    // final mixer to adjust the dry wet levels of the filter section.
    float RAWSIGNAL = 0.5;
    float LOWPASSIN = 0.8;
    float BANDPASSIN = 0.0;
    float HIGHPASSIN = 0.0;
    mixer4.gain(0, RAWSIGNAL);
    mixer4.gain(1, LOWPASSIN);
    mixer4.gain(2, BANDPASSIN);
    mixer4.gain(3, HIGHPASSIN);
}


void nadafunc(void){
    Serial.println('NADA');
}