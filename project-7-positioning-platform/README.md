## Project 7: Two-Axis Precision Positioning Platform (Mini Pen-Plotter Base)
<img width="1280" height="960" alt="WhatsApp Image 2026-10-24 at 17 28 27" src="https://github.com/user-attachments/assets/bfa411d3-6fc8-490c-8263-fcb8305e1bd4" />


# Problem This Solves
Precise, repeatable positioning is the foundation of CNC machines, 3D printers, and camera
sliders. This project builds a small two-axis positioning system and, critically, quantifiably tests
its positioning accuracy rather than just demonstrating that it moves.

# Parts List
• Arduino Uno-compatible controller board
• Stepper motor + ULN2003 driver board
• Servo SG90 (pen-lift axis)
• Rotary encoder module (manual jog control)
• Joystick module (manual X/Y override)
• LCD1602 display (position readout)
• Potentiometer (jog speed control)
• 1x Electrolytic capacitor (100µF, motor power smoothing)
• Breadboard, jumper wires

# Build & Test Process
Each input/output device was wired and tested completely independently before combination,
given how pin-constrained this build is: the stepper+ULN2003 (quarter-turn test), the pen-lift
servo, the rotary encoder (direction counting), the joystick (X/Y/button reading), the LCD, and
the speed potentiometer. Once combined, positioning accuracy was validated with a repeatabil
ity test: commanding a fixed move away from a marked start point, triggering “return to home,”
and measuring physical drift with a ruler across multiple trials.

# What I’d Improve With More Time
• Add limit switches at each axis’s physical extremes to prevent over-travel damage.
• Replace open-loop stepper control with closed-loop position feedback (e.g., an encoder on
the stepper shaft itself) for guaranteed accuracy rather than assumed step-counting accu
racy.
• Extend to true 2-axis (X/Y) motion with a second stepper, rather than a single positioning
axis plus manual pen-lift.
• Add basic G-code-style command parsing over Serial for computer-driven plotting instead
of only manual jog control.
