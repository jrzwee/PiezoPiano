# PiezoPiano

<p align="center">
  <img width="512" height="512" src="/hardware/renders/20211024_PiezoPiano_A_V1.2.png">
</p>

## What´s this?
PiezoPiano is a PCB piano which can play one octave - all at once. It is programmed via Arduino.

## Implementation
The processor generates a square wave for every note which is played. This is realised via timers and a interrupt.

```c
#define C4 84                   // Each note gets a different frequency
unsigned char notes[8] = {0};   // Array for individual counting of notes
```
In the section above the global variable 'notes' is initialized.
```c
notes[1]++;                     // This array contains eight 

// Generate Note 1
if(!(PINB & BTN1) && (notes[1] >= C4))
{
  setBit(PIND, NTE1);           // Toggle Pin for 50 % Duty Cycle (PIND and NTE1 are just defines for a PORT and a PIN)
  notes[1] = 0;                 // Reset Counter
}
```
This code snippet gives an insight how the waveform is generated. The algorithm is extended for all eight channels.

## Build of Material - BOM
TBD as there is a refactoring in the making.

## Pinout
![PCB Pinout](/hardware/pinout/piezopiano_pinout.svg)

## Renders
<p align="center">
  <img width="512" height="512" src="/hardware/renders/piezopiano_v13_direct_side.png">
  <img width="512" height="512" src="/hardware/renders/piezopiano_v13_render.png">
</p>

## License
[CERN-OHL-S](https://ohwr.org/cern_ohl_s_v2.pdf)
