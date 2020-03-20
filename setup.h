// v1.1

#include "Arduino.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       LFO1;          //xy=116,243
AudioSynthWaveform       LFO2;          //xy=549,235
AudioSynthWaveform       waveform2;      //xy=124,163
AudioSynthWaveform       waveform1;      //xy=126,99
AudioSynthWaveformPWM    pwm1;           //xy=244,227
AudioSynthWaveformPWM    pwm2;           //xy=244,260
AudioSynthWaveformSineModulated sine_fm1;       //xy=254,131
AudioSynthWaveformSineModulated sine_fm2;       //xy=255,188
AudioMixer4              mixer1;         //xy=420,141
AudioMixer4              mixer2;         //xy=421,217
AudioMixer4              mixer3;         //xy=551,173
AudioMixer4              mixer4;         //xy=806,193
AudioFilterStateVariable filter1;        //xy=674,203
AudioAmplifier           amp1;           //xy=936,193
AudioOutputI2S           i2s2;           //xy=1073,194
AudioConnection          patchCord1(LFO1, pwm1);
AudioConnection          patchCord2(LFO1, pwm2);
AudioConnection          patchCord3(waveform2, sine_fm2);
AudioConnection          patchCord4(waveform2, 0, mixer1, 2);
AudioConnection          patchCord5(waveform1, sine_fm1);
AudioConnection          patchCord6(waveform1, 0, mixer1, 0);
AudioConnection          patchCord7(pwm1, 0, mixer2, 0);
AudioConnection          patchCord8(pwm2, 0, mixer2, 1);
AudioConnection          patchCord9(sine_fm1, 0, mixer1, 1);
AudioConnection          patchCord10(sine_fm2, 0, mixer1, 3);
AudioConnection          patchCord11(mixer1, 0, mixer3, 0);
AudioConnection          patchCord12(mixer2, 0, mixer3, 1);
AudioConnection          patchCord13(LFO2, 0, filter1, 1);
AudioConnection          patchCord14(mixer3, 0, filter1, 0);
AudioConnection          patchCord15(mixer3, 0, mixer4, 0);
AudioConnection          patchCord16(filter1, 0, mixer4, 1);
AudioConnection          patchCord17(filter1, 1, mixer4, 2);
AudioConnection          patchCord18(filter1, 2, mixer4, 3);
AudioConnection          patchCord19(mixer4, amp1);
AudioConnection          patchCord20(amp1, 0, i2s2, 0);
AudioConnection          patchCord21(amp1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=127,44
// GUItool: end automatically generated code
