# Project 2: Two-Factor Secure Access Control System (RFID + Keypad)
<img width="1280" height="960" alt="WhatsApp Image 2026-10-24 at 17 28 32" src="https://github.com/user-attachments/assets/82aca6c0-eaa4-453b-8ac2-c2008cd0e8c0" />


## Problem This Solves
Single-factor access control(a cardalone, oraPINalone)is easy to defeat if the card is lost/stolen
or the PIN is observed. Requiring both a valid RFID card and a correct PIN is standard practice
in real building security systems, and this project implements that two-factor logic end-to-end.

## Parts List
• Arduino Uno-compatible controller board
• RC522 RFID module + card/tag (3.3V only)
• 4x4 matrix keypad module
• 5Vrelay (lock actuator)
• 1x NPN transistor
• 1x 1N4007 diode
• 2x LED(green = granted, red = denied)
• Passive buzzer
• Resistors: 220Ω (x2 for LEDs), 1kΩ (transistor base)
• Prototype expansion board (for final soldered build)
• Breadboard, jumper wires

## Build & Test Process
The RC522 was wired and tested first using the MFRC522 library’s UID-read example to capture
the authorized card’s UID.The keypad was tested independently to confirm all 16 keys registered
correctly, with row/column pin order adjusted until every key matched its expected character.
LEDs, buzzer, and the transistor-driven relay stage were each verified individually before being
combined into a state machine requiring a valid card scan followed by correct PIN entry within
a timed window. After the breadboard version was fully verified, the circuit was rebuilt on the
prototype expansion board as a permanent, presentable version.

## What I’d Improve With More Time
• Store authorized UIDs and PINs in EEPROM instead of hard-coded arrays, so they persist
and can be updated without reflashing the code.
• Add a lockout timer after repeated failed attempts (e.g., 3 wrong PINs locks the system for
30 seconds) to resist brute-force PIN guessing.
• Support multiple authorized cards/PINs rather than a single hard-coded pair.
• Add event logging (ideally combined with the RTC module from Project 4) to timestamp
every access attempt
