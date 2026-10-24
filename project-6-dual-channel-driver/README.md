## Project 6: Dual-Channel Industrial Alert & Output Driver Module (L293D)

# Problem This Solves
Industrial control panels frequently need a microcontroller to independently drive two separate
higher-power output devices — for example, an audible alarm and a visual signal lamp — with
out overloading the microcontroller’s own GPIO pins. This project demonstrates that using the
L293D’s two independent H-bridge channels.

# Parts List
• Arduino Uno-compatible controller board
• IC L293D (dual H-bridge driver)
• Active buzzer (Channel A load)
• 5Vrelay (Channel B load, driving an indicator circuit)
• 1x 1N4007 diode
• 1x Electrolytic capacitor (100µF, power-rail smoothing)
• Breadboard, jumper wires

# Wiring Diagram
--

# Build & Test Process
The L293D was placed and powered first, with its output voltage swing verified on a multimeter
before any load was attached, confirming the chip itself was alive and switching correctly. The
6
active buzzer was added to Channel A and tested independently; the relay was added to Chan
nel B (with 1N4007 flyback protection) and tested independently. Both channels were then
combined into one sketch demonstrating independent and simultaneous switching, printing the
current state to Serial Monitor for a clear demo.
What I’d Improve With More Time
• AddPWM-basedintensity/volumecontroloneachchannel(theL293D’senablepinssupport
PWM) rather than simple on/off switching.
• Extend to a full 2-motor demonstration if a spare DC motor becomes available, to show the
chip’s more typical bidirectional motor-control use case.
• Add current-sensing feedback to detect a failed/disconnected load on either channel.
