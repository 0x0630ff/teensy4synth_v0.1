#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform              waveform2;                      //xy=130.0104103088379,552.6770973205566
AudioSynthWaveform              waveform1;                      //xy=132.0000228881836,496.6666965484619
AudioSynthWaveformModulated     waveformMod1;                   //xy=146,600.666675567627
AudioMixer4                     mixer1;                         //xy=337.0104064941406,591.6770858764648
AudioOutputI2S                  i2s1;                           //xy=499.99999618530273,570.6666812896729
AudioAmplifier                  amp1;                           //xy=573.0104064941406,570.6770858764648
AudioConnection                 patchCord1(waveform1, 0, mixer1, 0);
AudioConnection                 patchCord2(waveform2, 0, waveformMod1, 0);
AudioConnection                 patchCord3(waveformMod1, 0, mixer1, 2);
AudioConnection                 patchCord4(waveform2, 0, mixer1, 1);
AudioConnection                 patchCord5(mixer1, amp1);
AudioConnection                 patchCord6(amp1, 0, i2s1, 0);
AudioConnection                 patchCord7(amp1, 0, i2s1, 1);
AudioControlSGTL5000            sgtl5000;                       //xy=326.0104103088379,522.6770706176758
// GUItool: end automatically generated code
