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

const int blinkspeed = 125;
int FREQUENCY = 60;
int LEDSTATE = HIGH;
float prevVol = 0.0;
int stamp = 0;

int step_number = 0;
int note_sequence[] = {100, 100, 80, 80, 100, 60, 200, 210};
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
    usbMIDI.setHandleControlChange(MIDIContolChange);

  // initialize the digital pin as an output.
    pinMode(15, INPUT);
    pinMode(led, OUTPUT);

    AudioMemory(20);

    Serial.begin(115200);

    mixer1.gain(0,0.7);
    mixer1.gain(1,0.65);
    mixer1.gain(2,1);

    amp1.gain(0);

    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);

    envelope1.attack(125);
    envelope1.decay(125);
    envelope1.sustain(125);
    envelope1.release(125);

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
}

////////////////////////////////////////////// Functions ############################################################

void adjust_volume(void){
    float AR = analogRead(15);
    double vol = AR / 1000;

    if (vol != prevVol) {
        Serial.print("Vol: ");
        Serial.println(vol);
        // Serial.println("Set");
        amp1.gain(vol);
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
    // Serial.print("Size of Note sequence ");
    // Serial.println(sizeof(note_sequence)/(sizeof(int)));
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

////////////////////////////////////////////// Main Loop ############################################################

// the loop routine runs over and over again forever:
void loop() {
    stamp = millis();

    Serial.println("%~ START ~%");
    
    usbMIDI.read();
    
    FREQUENCY = note_sequence[step_number];
    waveform1.frequency(FREQUENCY + 1.5);
    waveform2.frequency(FREQUENCY - 1.5);
    waveformMod1.frequency(FREQUENCY);
    waveformMod1.frequencyModulation(note_sequence[step_number] / 100);


    while (waitingForStep()){
        // do stuff that might need constant updating.
        // Serial.println(waitingForStep());
            
        adjust_volume();
        blinkLed();
        
    }
    
    take_step();

    Serial.println("%~ END ~%");
}
