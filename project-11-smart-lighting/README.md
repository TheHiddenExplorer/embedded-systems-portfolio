# Project 11: Ambient-Reactive Smart Lighting Automation

## Problem This Solves
Automatic lighting that reacts to both an occupancy/trigger cue and ambient light level is a
genuine energy-efficiency feature used in modern building automation — this project builds that
combined-condition logic with a manual override, since real automation should never fully lock
out manual control.

## Parts List
• Arduino Uno-compatible controller board
• Sound sensor module
• Photoresistor (LDR)
• Potentiometer (adjustable darkness threshold)
• 5Vrelay (lighting circuit)
• 1x NPN transistor
• 1x 1N4007 diode
• Push button (manual override)
• LED(status indicator)
• Resistors: 10kΩ (LDR divider), 1kΩ (transistor base), 220Ω (status LED)
• Breadboard, jumper wires

## Wiring Diagram
--

##Build & Test Process
The sound sensor and photoresistor were each wired and tested independently, noting which
reading direction corresponded to “darker” for the specific divider wiring used. The threshold
potentiometer, transistor/relay stage, override button, and status LED were each verified individually. The combined sketch only responds to a sound trigger when the LDR indicates dark
conditions (daytime claps are explicitly ignored and logged as such), while the override button
always works regardless of automatic state.

## What I’d Improve With More Time
• Add a time-of-day awareness (combining with the RTC module) so the system can distinguish “dark because it’s night” from “dark because a hand is covering the sensor,” reducing
false triggers.
• Replace the single on/off relay output with PWM-based dimming for a more realistic smart
lighting feature.
• Add a fade-in/fade-out transition instead of an instant on/off switch.
