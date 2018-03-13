#!/bin/sh
make tv44:djthread && \
  sudo dfu-programmer atmega32u4 erase && \
  sudo dfu-programmer atmega32u4 flash tv44_djthread.hex && \
  sudo dfu-programmer atmega32u4 start
