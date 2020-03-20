// #include <Audio.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>

// // GUItool: begin automatically generated code
// AudioSynthWaveform       waveform1;      //xy=150,99
// AudioSynthWaveformModulated waveformMod1;   //xy=158,235
// AudioSynthWaveformModulated waveformMod2; //xy=160,307
// AudioSynthWaveform       waveform2;      //xy=218,183
// AudioMixer4              mixer1;         //xy=434,215
// AudioEffectEnvelope      envelope1;      //xy=610,276
// AudioAmplifier           amp1;           //xy=738,207
// AudioOutputI2S           i2s1;           //xy=956,214
// AudioConnection          patchCord1(waveform1, 0, mixer1, 0);
// AudioConnection          patchCord2(waveform1, 0, waveformMod1, 0);
// AudioConnection          patchCord3(waveformMod1, 0, mixer1, 2);
// AudioConnection          patchCord4(waveformMod2, 0, mixer1, 3);
// AudioConnection          patchCord5(waveform2, 0, mixer1, 1);
// AudioConnection          patchCord6(waveform2, 0, waveformMod2, 0);
// AudioConnection          patchCord7(mixer1, amp1);
// AudioConnection          patchCord8(amp1, 0, i2s1, 0);
// AudioConnection          patchCord9(amp1, 0, i2s1, 1);
// AudioControlSGTL5000     sgtl5000_1;     //xy=184,28
// // GUItool: end automatically generated code

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformModulated waveformMod1;   //xy=123,233
AudioSynthWaveform       waveform1;      //xy=150,99
AudioSynthWaveform       waveform2;      //xy=218,183
AudioSynthWaveformModulated waveformMod2; //xy=291,273
AudioSynthWaveformSine   LFO;          //xy=328,378
AudioMixer4              mixer1;         //xy=434,215
AudioFilterStateVariable filter1;        //xy=461,371
AudioMixer4              mixer2; //xy=599,213
AudioEffectEnvelope      envelope1;      //xy=609,362
AudioAmplifier           amp1;           //xy=738,207
AudioOutputI2S           i2s1;           //xy=893,205
AudioConnection          patchCord1(waveformMod1, 0, mixer1, 2);
AudioConnection          patchCord2(waveform1, 0, mixer1, 0);
AudioConnection          patchCord3(waveform1, 0, waveformMod1, 0);
AudioConnection          patchCord4(waveform2, 0, mixer1, 1);
AudioConnection          patchCord5(waveform2, 0, waveformMod2, 0);
AudioConnection          patchCord6(waveformMod2, 0, mixer1, 3);
AudioConnection          patchCord7(LFO, 0, filter1, 1);
AudioConnection          patchCord8(mixer1, 0, mixer2, 0);
AudioConnection          patchCord9(mixer1, 0, filter1, 0);
AudioConnection          patchCord10(filter1, 0, envelope1, 0);
AudioConnection          patchCord11(mixer2, amp1);
AudioConnection          patchCord12(envelope1, 0, mixer2, 1);
AudioConnection          patchCord13(amp1, 0, i2s1, 0);
AudioConnection          patchCord14(amp1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=368,95
// GUItool: end automatically generated code
