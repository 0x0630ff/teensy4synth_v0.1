/*
    Teensy Synth testing sketch...
    'teensy4v1.1'
*/
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
// #include <MIDI.h>

#include "setup.h"  // where the audio design export is pasted.
#include "MIDIfunctions.h"  // does stuff for midi.. might import a library later..
// #include "mixers.h"
// #include "amps.h"
// #include "oscs.h"
// #include "filters.h"

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
    // be sure to set type as MIDI in Arduino Tools -> Usb Type
    MIDIsetup();

    // initialize the I/O.
    pinMode(15, INPUT);  // volume controller.
    pinMode(led, OUTPUT);

    AudioMemory(20);
    Serial.begin(115200);
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);
}

////////////////////////////////////////////// Functions ############################################################

void adjust_volume(void){
    float AR = analogRead(15);
    double vol = AR / 1000;

    if (vol != prevVol) {
        Serial.print(" Vol ");
        Serial.println(vol);
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

// float stickMod(void){
//     int X = analogRead(14);
//     Serial.print("X: ");
//     Serial.println(X);
// }

////////////////////////////////////////////// Main Loop ############################################################

// the loop routine runs over and over again forever:
void loop() {
    stamp = millis();

    Serial.println("%~ START ~%");
    
    usbMIDI.read();
    
    FREQUENCY = note_sequence[step_number];

    Serial.print("Freq: ");
    Serial.println(FREQUENCY);
    
    waveform1.frequency(FREQUENCY + 1.5);
    waveform2.frequency(FREQUENCY - 1.5);
    sine_fm1.frequency(FREQUENCY);
    sine_fm2.frequency(FREQUENCY);
    
    while (waitingForStep()){
        // do stuff that might need constant updating.
    }

    // stickMod();
    adjust_volume();  // track fader to adjust volume... 
    blinkLed();  // blink LED to show activity
    take_step();  // step through note_sequence
}
