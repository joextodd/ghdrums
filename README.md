Guitar Hero Drums MIDI Interceptor
==================================

This project is for using the Guitar Hero Drum Kit as a MIDI controller. As the kit only sends MIDI ON commands, the idea is to intercept these and send the corresponding OFF commands a short while after. The MIDI output is then easier to work with in a DAW.

Hardware
--------

- STM32F4 Discovery Board
- 2x 5pin DIN connectors
- 6N138 Optoisolator 
- 7404 Hex Inverter
- 270ohm, 3x220ohm resistors

![alt tag](https://raw.github.com/joetodd109/ghdrums/master/img/midi.png)