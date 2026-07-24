# Arduino Embedded Systems Portfolio

A collection of practical, real-world-oriented embedded systems projects built using an Arduino Uno-compatible controller board and a general-purpose electronics starter kit. Each project addresses a genuine real-world problem (security, automation, agriculture, motion control, industrial signaling) rather than a simple demo, and each is fully documented with its own wiring diagram, build/test process, and complete source code.

## About This Repository

This repo brings together 11 individual projects, each living in its own folder. Every project folder contains:
- Its own `README.md` — real-world problem addressed, parts list, wiring diagram, build/test process, and planned improvements
- Arduino sketch(es) (`.ino` files), including individual stage-test sketches where relevant, plus the final combined code
- A wiring diagram image
- (Where available) a demo photo or video link

## Projects

| # | Project | Core Skills Demonstrated |
|---|---|---|
| 1 | [Smart Agriculture Environmental Monitor & Automated Irrigation Controller](./project-1-irrigation-controller) | Multi-sensor integration, threshold logic, relay/inductive-load protection |
| 2 | [Two-Factor Secure Access Control System (RFID + Keypad)](./project-2-two-factor-access) | SPI + matrix scanning, security state-machine design |
| 3 | [Perimeter Intrusion Alarm with Tamper Detection](./project-3-intrusion-alarm) | Finite state machines, sensor fusion |
| 4 | [Timestamped Event Logging Terminal](./project-4-event-logger) | I2C communication, real-time data logging *(pending RTC battery)* |
| 5 | [IR Remote-Controlled Home Automation Hub](./project-5-ir-automation-hub) | IR protocol decoding, command-mapping design *(pending remote battery)* |
| 6 | [Dual-Channel Industrial Alert & Output Driver Module](./project-6-dual-channel-driver) | H-bridge/driver IC operation, power-rail smoothing |
| 7 | [Two-Axis Precision Positioning Platform](./project-7-positioning-platform) | Stepper motor control, quantified accuracy testing |
| 8 | [Motion-Sensing Digital Tilt Level / Stabilization Platform](./project-8-tilt-stabilizer) | I2C sensor fusion, feedback control, signal smoothing |
| 9 | [Digital Countdown Timer / Process Control Panel](./project-9-countdown-timer) | Display-driver ICs, non-blocking timing |
| 10 | [Ultrasonic Smart Parking / Obstacle Proximity Alert System](./project-10-parking-assistant) | Ultrasonic timing, proportional feedback |
| 11 | [Ambient-Reactive Smart Lighting Automation](./project-11-smart-lighting) | Combined-condition automation logic |

## Hardware Used

All 11 projects are built from a single general-purpose Arduino starter kit (Uno-compatible controller board, breadboard, sensors, actuators, and driver ICs), reused and rewired project-to-project rather than requiring separate hardware sets. Two projects (4 and 5) depend on small coin-cell batteries for their RTC and IR remote modules respectively — their READMEs note current build/test status accordingly.

## How to Use This Repository

Each project folder is self-contained — open its `README.md` first for context on what it does and why, then refer to its wiring diagram and `.ino` files to reproduce the build.
