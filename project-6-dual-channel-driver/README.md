## Project 6: Dual-Channel Industrial Alert & Output Driver Module (L293D)
<img width="1280" height="960" alt="WhatsApp Image 2026-10-24 at 17 28 30" src="https://github.com/user-attachments/assets/d3626769-77ff-4990-b624-b45c282aa02f" />



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

# Build & Test Process
The L293D was placed and powered first, with its output voltage swing verified on a multimeter
before any load was attached, confirming the chip itself was alive and switching correctly. The
active buzzer was added to Channel A and tested independently; the relay was added to Channel B
(with 1N4007 flyback protection) and tested independently. Both channels were then
combined into one sketch demonstrating independent and simultaneous switching, printing the
current state to Serial Monitor for a clear demo.

# What I’d Improve With More Time
• Add PWM-based intensity/volume control on each channel (the L293D’s enable pins support
PWM) rather than simple on/off switching.
• Extend to a full 2-motor demonstration if a spare DC motor becomes available, to show the
chip’s more typical bidirectional motor-control use case.
• Add current-sensing feedback to detect a failed/disconnected load on either channel.
