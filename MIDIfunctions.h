#ifndef __MIDI_FUNC__
#define __MIDI_FUNC__

#include "Arduino.h"

const byte BUFFER = 8;  // size of keyboard buffer
const float DIV127 = (1.0 / 127.0);

int globalNote;
int globalVelocity;

void MIDIContolChange(byte channel, byte control, byte value) {
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

void keyBuff(byte note, bool playNote) {
    static byte buff[BUFFER];
    static byte buffSize = 0;
    // Add note
    if (playNote == true && (buffSize < BUFFER) ) {
        // make oscilatore make noise...
        buff[buffSize] = note;
        buffSize++;
        return;
    }
    // remove a note
    else if (playNote == false && buffSize != 0) {
        // more...
    }
}

void midiNoteOn(byte channel, byte note, byte velocity) {
    // do something with the note, channel, velocity etc...
    // code here...
    if ( 23 < note < 108) {
        globalNote = note;
        globalVelocity = velocity;
        keyBuff(note, true);
    }
}

void midiNoteOff(byte channel, byte note, byte velocity) {
    // stop something with the note, channel, velocity etc...
    keyBuff(note, false);
    // code here...
}

void MIDIsetup(void) {
    // set up midi via usb. call in setup();
    usbMIDI.setHandleControlChange(MIDIContolChange);
    usbMIDI.setHandleNoteOff(midiNoteOff);
    usbMIDI.setHandleNoteOn(midiNoteOn);

    //DIN MIDI INPUT NEXT...
    // MIDI.setHandleControlChange(MIDIContolChange);
    // MIDI.setHandleNoteOn(midiNoteOn);
    // MIDI.setHandleNoteOff(midiNoteOff);
}

#endif
