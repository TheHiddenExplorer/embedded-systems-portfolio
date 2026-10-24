# Project 4: Timestamped Event Logging Terminal

## Problem This Solves
Any real access-control, security, or industrial system needs an audit trail of when events occurred, not just that they occurred.This project builds the foundational piece of that: a debounced event trigger paired with accurate, power-loss-resistant timekeeping.

## Parts List
• Arduino Uno-compatible controller board
• RT Cmodule (DS3231/DS1307-style) + backup coin-cell battery
• Sound sensor module
• LCD1602 display
• Push button (log reset)
• LED(event indicator)
• Resistors: 220Ω (LED)
• Breadboard, jumper wires

## Wiring Diagram
--

## Build & Test Process
The RTC was wired over I2C and its time set once via the RTClib example, with the adjust() call
commented out afterward to prevent the clock resetting on every power-up. The sound sensor
was tested independently for clap detection, and its onboard sensitivity trimmed as needed. The
LCD, reset button, and event LED were each verified individually. The combined sketch logs a
timestamp and increments an event counter on each debounced sound trigger, displayed on both
the LCD and Serial Monitor. (Pending: the power-cycle proof test — unplugging and replugging
the Arduino to confirm the RTC retains accurate time via its backup battery.)

## What I’d Improve With More Time
• Log events to an SD card or EEPROM instead of only the live LCD/Serial output, so history
survives beyond the current session.
• Replace the simple sound-sensor trigger with a more meaningful “real” event source (e.g.,
the PIR sensor from Project 3 or the RFID reader from Project2), turning this into a genuine
access-log system.
• Add a way to export or review logged events without needing to watch Serial Monitor live.
