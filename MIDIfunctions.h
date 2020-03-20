#include "Arduino.h"

const byte BUFFER = 8;  // size of keyboard buffer
const float DIV127 = (1.0 / 127.0);

void MIDIContolChange(byte channel, byte control, byte value){
    // Midi Switch
    switch (control)
    {
    case 99:
        // whatever
        break;

    case 100:  // this is the control cc number
        /* do something with value variable */
        break;
    
    default:
        break;
    }
}   

void keyBuff(byte note, bool playNote){
    static byte buff[BUFFER];
    static byte buffSize = 0;
    // Add note
}

void midiNoteOn(byte channel, byte note, byte velocity){
    // do something with the note, channel, velocity etc...
    keyBuff(note, true);
}

void midiNoteOff(byte channel, byte note, byte velocity){
    keyBuff(note, false);
}

void MIDIsetup(void){
    // set up midi via usb. call in setup();
    usbMIDI.setHandleControlChange(MIDIContolChange);
}
