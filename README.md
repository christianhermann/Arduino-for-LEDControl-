# Arduino-for-LEDControl-

Arduino firmware for controlling LED illumination systems in fluorescence microscopy applications, particularly for FRET (Förster Resonance Energy Transfer) experiments.

## Overview

This repository contains Arduino sketches that work in conjunction with the [EnhancedLEDControl](https://github.com/christianhermann/EnhancedLEDControl) MATLAB application to provide precise hardware-level control of LED systems.

## Repository Structure

### Enhanced_LEDControl_Arduino
The main Arduino firmware for the enhanced LED control system.

**Key Components:**
- `Enhanced_LEDControl_Arduino.ino` - Main sketch file
- `FRET.ino` - FRET-specific illumination sequences
- `FRETwPulse.ino` - FRET with pulsed illumination support
- `Light.ino` - Basic LED control functions
- `complexLight.ino` - Advanced illumination patterns
- `Functions.ino` - Utility functions and helpers

### FRET_Patch3
Updated version with additional features and bug fixes for FRET applications.

### Arduino LED Ansteuerung FRET1
Original FRET LED control implementation.

## Features

- Serial communication with MATLAB/computer control software
- Multi-channel LED control
- PWM-based intensity adjustment
- Support for complex illumination sequences
- FRET-optimized timing protocols
- Pulsed illumination capabilities

## Hardware Requirements

- Arduino board (Mega or compatible)
- LED driver circuits
- Power supply for LEDs
- Serial USB connection to computer

For detailed hardware setup, refer to the [arduinoLEDcontrolunit](https://github.com/christianhermann/arduinoLEDcontrolunit) repository.

## Installation

1. Install the Arduino IDE
2. Clone or download this repository
3. Open the desired sketch folder (recommended: `Enhanced_LEDControl_Arduino`)
4. Upload to your Arduino board
5. Connect the Arduino to your LED control hardware

## Usage

The Arduino firmware receives commands via serial communication from the MATLAB control software:
1. Upload the firmware to your Arduino
2. Connect LEDs according to your hardware configuration
3. Launch the EnhancedLEDControl MATLAB application
4. Configure the serial port in the software
5. Control LEDs through the graphical interface

## Communication Protocol

The firmware listens for serial commands to control LED states, intensities, and timing sequences. Commands are sent from the host computer application.

## Compatibility

Works with:
- [EnhancedLEDControl](https://github.com/christianhermann/EnhancedLEDControl) - MATLAB-based control software

## Contributing

Contributions, bug reports, and feature requests are welcome. Please open an issue or submit a pull request.

## License

Please refer to the repository license file for usage terms and conditions.
