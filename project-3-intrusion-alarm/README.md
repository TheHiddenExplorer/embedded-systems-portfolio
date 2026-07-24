# Project 3: Perimeter Intrusion Alarm with Tamper Detection

## Problem This Solves
Basic motion-only alarms can be bypassed by disabling or moving the sensor housing itself. Com
mercial alarm panels add a tamper switch to the enclosure to catch this — this project replicates
that layered approach using both a motion sensor and a physical tamper switch.

## Parts List
• Arduino Uno-compatible controller board
• HC-SR501 PIR motion sensor
• Tilt switch
• Push button (arm/disarm)
• RGBLED
• Active buzzer
• 1x NPNtransistor
• Resistors: 220Ω (x3 for RGB LED), 10kΩ (tilt switch pull-down), 1kΩ (transistor base)
• Breadboard, jumper wires

## Wiring Diagram
<img width="1271" height="850" alt="image" src="https://github.com/user-attachments/assets/e002722c-9b1f-412c-b0bb-9f2ac9eda05b" />

## Build & Test Process
The PIR sensor was powered and allowed its ~60-second warm-up period before testing mo
tion detection via Serial Monitor. The tilt switch was tested independently with a pull-down
resistor to confirm a clean HIGH/LOW transition on tilt. The arm/disarm button, RGB LED, and
transistor-driven buzzer were each verified individually. All sub-circuits were then combined
into a DISARMED → ARMED → ALARM finite state machine, tested by arming the system and trigger
ing each sensor (PIR motion, then tilt tamper) separately to confirm both independently cause
an alarm state.

## What I’d Improve With More Time
• Add ashort “entry delay” after arming (common in real alarm panels) so the user has time
to leave the protected area before the system becomes active.
• Debounce the tilt switch in software as well as hardware, since mechanical tilt switches
can bounce on marginal angles.
• Addalow-power “sleep” mode between PIR polls to reduce standby current draw, relevant
if this were ever battery-powered.
• Log alarm events with a timestamp (combining with the RTC module) rather than only a
live buzzer/LED response.
