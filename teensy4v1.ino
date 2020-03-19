/*
    Teensy Synth testing sketch...
*/
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <MIDI.h>

#include "setup.h"
#include "MIDIfunctions.h"

const int blinkspeed = 500;
int FREQUENCY = 54;
int LEDSTATE = HIGH;
float prevVol = 0.0;
int stamp = 0;

int step_number = 0;
int note_sequence[] = {54, 54, 65, 54, 108, 108, 65, 108};
int note_length = 128;

float BPM = 108;
float quarter_note = 60000 / BPM;
float sixteenth_note = quarter_note / 4;

int ledBlinkTimer = millis();  // number of milliseconds.
int blinkDelay = 250;

// Pin 13 LED
int led = 13;

////////////////////////////////////////////// SET UP ############################################################

// the setup routine runs once when you press reset:
void setup() {
    // set up midi via usb.
    // be sure to set type as MIDI in Arduino Tools -> Usb Type
    // usbMIDI.setHandleControlChange(MIDIContolChange);

    // initialize the I/O.
    pinMode(15, INPUT);  // volume controller.
    pinMode(13, INPUT);
    pinMode(14, OUTPUT);
    pinMode(led, OUTPUT);

    digitalWrite(14, HIGH);

    AudioMemory(20);

    Serial.begin(115200);

    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);

    mixer1.gain(0,0.6);
    mixer1.gain(1,0.65);
    mixer1.gain(2,0.7);
    mixer1.gain(3,0.7);

    mixer2.gain(0,0.25);
    mixer2.gain(1,1);

    // amp1.gain(10);

    LFO.frequency(0.1);
    LFO.amplitude(1);

    filter1.frequency(100);
    filter1.resonance(0.75);

    envelope1.attack(0);
    envelope1.decay(0.5);
    envelope1.sustain(50);
    envelope1.release(0.125);

    waveform1.begin(WAVEFORM_SAWTOOTH);
    waveform1.amplitude(0.75);
    waveform1.frequency(FREQUENCY + 1.5);
    waveform1.pulseWidth(0.15);

    waveform2.begin(WAVEFORM_SINE);
    waveform2.amplitude(0.75);
    waveform2.frequency(FREQUENCY - 1.5);

    waveformMod1.begin(WAVEFORM_SAWTOOTH);
    waveformMod1.amplitude(0.75);
    waveformMod1.frequency(FREQUENCY);
    waveformMod1.frequencyModulation(0.25);

    waveformMod2.begin(WAVEFORM_SAWTOOTH);
    waveformMod2.amplitude(0.75);
    waveformMod2.frequency(FREQUENCY - 1.25);
    waveformMod2.frequencyModulation(0.25);
}

////////////////////////////////////////////// Functions ############################################################

void adjust_volume(void){
    float AR = analogRead(15);
    double vol = AR / 1000;

    if (vol != prevVol) {
        Serial.print(" Vol ");
        Serial.println(vol);
        // Serial.println("Set");
        // amp1.gain(vol);
        sgtl5000_1.volume(vol);
        prevVol = vol;
    }
}

void blinkLed(void){
    float now = millis();
    if ((now - ledBlinkTimer) > blinkDelay){
        LEDSTATE = !LEDSTATE;
        digitalWrite(led, LEDSTATE);   // turn the LED on (HIGH is the voltage level)
        ledBlinkTimer = millis();
    }
}

void take_step(void){
    Serial.print("Step number ");
    Serial.println(step_number);
    Serial.print("Size of Note sequence ");
    Serial.println(sizeof(note_sequence)/(sizeof(int)));
    if (step_number == sizeof(note_sequence)/(sizeof(int))){
        step_number = 0;
    } else {
        step_number++;
    }
}

bool waitingForStep(void){
    float now = millis();
    if ((now - stamp) > note_length){
        return false;
    }
    else{
        return true;
    }
}

float stickValue(void){
    int X = analogRead(14);
    Serial.print("X: ");
    Serial.println(X);
}
////////////////////////////////////////////// Main Loop ############################################################

// the loop routine runs over and over again forever:
void loop() {
    stamp = millis();

    usbMIDI.read();
    
    FREQUENCY = note_sequence[step_number];

    Serial.print("Freq: ");
    Serial.println(FREQUENCY);
    
    waveform1.frequency(FREQUENCY + 1.5);
    waveform2.frequency(FREQUENCY - 1.5);
    waveformMod1.frequency(FREQUENCY);
    waveformMod1.frequencyModulation(note_sequence[step_number] / 100);
    waveformMod2.frequency(FREQUENCY);
    waveformMod2.frequencyModulation(note_sequence[step_number] / 100);
    
    envelope1.noteOn();
    envelope1.noteOff();
    
    while (waitingForStep()){
        // do stuff that might need constant updating.
        // Serial.println(waitingForStep());
    }

    // stickValue();
    adjust_volume();  // track fader to adjust volume... 
    blinkLed();  // blink LED to show activity
    take_step();  // step through note_sequence
    
}
