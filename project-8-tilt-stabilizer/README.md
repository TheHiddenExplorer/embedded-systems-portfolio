## Project 8: Motion-Sensing Digital Tilt Level / Stabilization Platform (Single-Axis)

# Problem This Solves
Digital spirit levels and single-axis camera/gimbal stabilizers rely on exactly this sensor-and
actuator combination: real-time tilt sensing feeding a servo-based correction. This project builds
a working version of both functions — a live digital level, and single-axis active stabilization.

# Parts List
• Arduino Uno-compatible controller board
• GY-521 module (MPU6050 accelerometer/gyroscope)
• Servo SG90
• LCD1602 display
• Potentiometer (manual calibration offset)
• Breadboard, jumper wires

# Wiring Diagram
--

# Build & Test Process
The GY-521 was wired over I2C and tested with an I2C bus scan followed by a basic connection
check and raw-value sketch, confirming accelerometer readings changed correctly under man
ual tilting. The LCD and the SG90 servo were each tested independently. The combined sketch
converts raw accelerometer data into a tilt angle using atan2(), applies a manual calibration
offset read from the potentiometer, smooths the signal with a simple moving-average filter to
reduce jitter, and maps the result to the servo output. Accuracy was spot-checked against a
physical protractor/spirit level. (Note: originally scoped as a two-axis platform using a second
3V servo; simplified to single-axis after confirming the 3V servo was not included in the kit as
received.)

# What I’d Improve With More Time
• Source a second servo to extend this to true two-axis (pitch and roll) stabilization as origi
nally planned.
• Incorporate the gyroscope axes (not just the accelerometer) with a proper complementary
or Kalman filter for more stable, drift-resistant angle estimates.
• Replace the manual potentiometer calibration with an automatic “zero” routine triggered
by a button press while the platform is known to be level.
