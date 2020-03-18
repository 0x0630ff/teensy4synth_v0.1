#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=108.0000228881836,341.66668701171875
AudioSynthWaveformModulated waveformMod1;   //xy=122,445.6666660308838
AudioSynthWaveform       waveform2; //xy=176.01040649414062,409.67709732055664
AudioMixer4              mixer1;         //xy=490.0104331970215,500.677038192749
AudioEffectEnvelope      envelope1;      //xy=602.0104064941406,463.4548568725586
AudioAmplifier           amp1;           //xy=695.0104293823242,419.67706871032715
AudioOutputI2S           i2s1;           //xy=758.0001106262207,336.666690826416
AudioConnection          patchCord1(waveform1, 0, mixer1, 0);
AudioConnection          patchCord2(waveform1, 0, waveformMod1, 0);
AudioConnection          patchCord3(waveformMod1, 0, mixer1, 2);
AudioConnection          patchCord4(waveform2, 0, mixer1, 1);
AudioConnection          patchCord5(mixer1, envelope1);
AudioConnection          patchCord6(envelope1, amp1);
AudioConnection          patchCord7(amp1, 0, i2s1, 0);
AudioConnection          patchCord8(amp1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=302.0104103088379,367.6770610809326
// GUItool: end automatically generated code
