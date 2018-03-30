#!/bin/sh
# avrdude -p atmega32u4 -c avr109 -U flash:w:sweet16_djthread.hex:i -P /dev/cu.usbmodem1411
make sweet16:djthread:avrdude
