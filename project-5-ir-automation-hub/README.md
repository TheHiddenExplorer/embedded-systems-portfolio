## Project 5: IR Remote-Controlled Home Automation Hub
<img width="1280" height="960" alt="WhatsApp Image 2026-10-24 at 17 28 18" src="https://github.com/user-attachments/assets/c6607485-ead7-4da7-bc84-2ed4f35744af" />


# Problem This Solves
A single remote controlling multiple household functions — lighting, blinds, appliances — is
exactly how real universal remotes and smart-home hubs operate. This project replicates that
command-mapping architecture.

# Parts List
• Arduino Uno-compatible controller board
• IR receiver module + remote control
• 5V relay (simulated appliance)
• Servo SG90 (simulated blind/curtain actuator)
• RGB LED(mood lighting)
• Active buzzer (confirmation tones)
• Resistors: 220Ω (x3 RGB LED), 1kΩ (transistor base)
• Breadboard, jumper wires

# Build & Test Process
The IR receiver module’s wiring was validated first, confirming signal reception on the correct
pin with LED feedback enabled at initialization for easier debugging. The relay/transistor stage,
servo, RGB LED, and buzzer were each wired and tested individually with their own simple
sketches. Remote button codes were captured directly from Serial Monitor and mapped to the
four target actions.

## Two implementation issues were identified and resolved duringtesting, both worth documenting explicitly since they reflect genuine debugging work rather than the project simply “working first time”:
1. Raw IR code matching was unreliable. The initial version compared IrReceiver.decodedIRData.decodedRawData
directly. This worked for the first press of each button, but subsequent presses of the same
button often produced different raw values (raw data can include repeat-frame/protocol
specific bits that vary between transmissions), so commands stopped being recognised
after the first press. Fix: switched to comparing IrReceiver.decodedIRData.command
instead — this is the library’s already-decoded, protocol-independent button identifier, and
it remains stable across repeated presses of the same button.
2. The passive buzzer’s tone() call conflicted with the IR receiver. The IR remote library
uses a hardware timer to measure incoming IR pulsetimings; tone()alsoclaimsahardware
timer to generate its square wave, and on the Uno these can collide — calling tone() was
corrupting the next IRreception, again making only the first button press per session appear
to work. Fix: replaced the passive buzzer with an active buzzer, which has its own internal
oscillator and only needs digitalWrite(pin, HIGH) to sound — this uses no timer at all,
eliminating the conflict.

Serial Monitor debugging output (printing the decoded command for every press) made both of
these issues straightforward to diagnose once the symptom (“only the first press works”) pointed
toward a timing/state issue rather than a wiring fault.

# What I’d Improve With More Time
• Support “long press” and “double press” gestures for additional functions per button, rather
than one action per code.
• Add persistent state (EEPROM) so the system remembers which “appliances” were on/off
after a power cycle.
• Replace the hard-coded command-code lookup table with a “learning mode” that lets any
remote be paired to the system without reflashing code.
• Worth noting for anyone reviewing this project: the raw-code and passive-buzzer issues
above are a good example of a bug that looked like a hardware/remote problem but was
actually a software resource conflict — a useful debugging story for interviews.
