# Project 1: Smart Agriculture Environmental Monitor & Automated Irrigation Controller

## Problem This Solves
Manual watering of plants or small crops wastes water and risks under- or over-watering, since
it relies on guesswork rather than data. This project automates the decision using real sensor
readings — a simplified version of the sensor-and-actuator logic used in commercial precision
agriculture systems.

## Parts List
• Arduino Uno-compatible controller board
• DHT11 temperature & humidity sensor
• Thermistor (NTC)
• Photoresistor (LDR)
• Water level sensor
• Potentiometer (threshold adjustment)
• LCD1602 display
• 3x LED(green, yellow, red)
• Active buzzer
• 1x NPNtransistor (PN2222 or S8050)
• 1x 1N4007 diode
• 5Vrelay
• Resistors: 220Ω (x3 for LEDs), 10kΩ (x3 for sensor dividers), 1kΩ (transistor base)
• Breadboard, jumper wires, 9V power supply

## Wiring Diagram
--

## Build & Test Process
Built and tested incrementally: DHT11 confirmed alone via Serial Monitor, followed by the ther
mistor and photoresistor voltage-divider circuits (each validated individually against expected
analog ranges), then the water level sensor and threshold potentiometer. The LCD was wired
and tested with a basic “Hello World” sketch before integration. Status LEDs and the active
buzzer were verified with simple blink/beep sketches. The transistor-driven relay stage (with
1N4007 flyback protection) was tested last, confirming an audible relay click on digitalWrite
HIGH/LOW before merging all sub-circuits into the final combined sketch, which implements
threshold-based irrigation logic and a low-water safety cutoff.

## What I’d Improve With More Time
• Replace the fixed analog threshold logic with a rolling average filter to reduce false triggers
from sensor noise.
• Add non-volatile storage (e.g., logging to an SD card module) for long-term environmental
data rather than only live Serial Monitor output.
• Introduce a proper PID or hysteresis-based control loop for the “pump” instead of simple
on/off threshold switching, to prevent relay chatter at borderline readings.
• Add a real soil-moisture sensor (not included in this kit) alongside the existing sensors for
more accurate irrigation decisions.
