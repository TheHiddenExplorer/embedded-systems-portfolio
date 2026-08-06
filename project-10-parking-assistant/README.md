# Project 10: Ultrasonic Smart Parking / Obstacle Proximity Alert System

## Problem This Solves
This replicates the parking-assist sensors found in real vehicles — a system that gives proportional, increasingly urgent feedback as an object gets closer, then confirms a stable “parked” state before taking an automated action.

## Parts List
• Arduino Uno-compatible controller board
• Ultrasonic distance sensor (HC-SR04 style)
• 3x LED(green, yellow, red — distance zones)
• Passive buzzer
• Servo motor (barrier arm)
• Resistors: 220Ω (x3 for LEDs)
• Breadboard, jumper wires

## Wiring Diagram
--

## Build & Test Process
The ultrasonic sensor was wired and tested first, confirming distance readings changed correctly as an object was moved closer/farther. The three zone LEDs and buzzer were tested independently, then the barrier servo. In the combined sketch, distance is mapped into three LED zones with buzzer beep-rate scaling inversely with distance, and a persistence check (object must remain in the “parked” range continuously for 3 seconds) triggers the servo barrier — tested by moving an object progressively closer and holding it steady in the target zone.

## What I’d Improve With More Time
• Add a second ultrasonic sensor for two-point distance sensing (e.g., front and rear detection).
• Log parking events with timestamps (combining with the RTC module) for a simple “usage
history.”
• Replace the fixed distance-zone thresholds with values calibrated against a real, physical
parking scenario rather than desk-scale testing.
