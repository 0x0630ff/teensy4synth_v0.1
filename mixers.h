// Mixer section.
// for set up of all the mixers in the set up.
#include "Arduino.h"
#include "setup.h"

// mixer1
// adds main waveforms and sine fm.
mixer1.gain(0, 0.6);
mixer1.gain(1, 0.6);
mixer1.gain(2, 0.7);
mixer1.gain(3, 0.7);

// mixer2
// adds in pwm with lfo
mixer2.gain(0, 0.7);
mixer2.gain(1, 0.8);

// mixer 3
// adds together the previous two mixers for all voices to join
//

// mixer 4
// final mixer to adjust the dry wet levels of the filter section.
//