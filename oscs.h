// oscilators
// section to set up all the oscilators.
#include "Arduino.h"
#include "setup.h"

// waveform1
waveform1.begin(WAVEFORM_SAWTOOTH);
waveform1.amplitude(0.75);
waveform1.frequency(FREQUENCY + 1.5);
waveform1.pulseWidth(0.15);

// waveform2
waveform2.begin(WAVEFORM_SINE);
waveform2.amplitude(0.75);
waveform2.frequency(FREQUENCY - 1.5);

// sine_fm1
sine_fm1.amplitude(0.75);
sine_fm1.frequency(FREQUENCY);

// sine_fm2
sine_fm2.amplitude(0.75);
sine_fm2.frequency(FREQUENCY - 1.25);

// pwm1

// pwm2

////// LFO SECTIONS //////

// LFO 
// main lfo connected to the pwm oscilators.
// LFO1.frequency(0.1);
// LFO1.amplitude(1);

// LFO2
// lfo for the filter movement.

