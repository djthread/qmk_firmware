#!/bin/sh
make tv44:djthread44 && \
  sudo dfu-programmer atmega32u4 erase && \
  sudo dfu-programmer atmega32u4 flash tv44_djthread44.hex && \
  sudo dfu-programmer atmega32u4 start
