# Candy Grabber Project

## Overview

The **Candy Grabber Project** involves building an interactive candy grabber using an **Arduino Uno** and **PlatformIO**. This device is designed to move in three dimensions (X, Y, Z) to grab candies, providing a fun and engaging experience. Currently, the project is in its initial stage, focusing on basic functionality, and will be documented as it evolves.

## Hardware Components

- **Microcontroller**: Arduino Uno
- **Motor Controllers**: 2 x L298N H-Bridge Motor Drivers
- **User Input**: Circuit boards with pull-down resistors for switches and joysticks
- **Coin Input Switch**: A simple circuit board with a pull-down resistor connected to a switch
- **Power Supply**: Dedicated circuit board for power management

## Circuit Design

The project utilizes multiple circuit boards to effectively manage various components:

1. **Motor Control Board**: Interfaces with the L298N motor drivers to control the movement of the grabber.
2. **Switch/Joystick Board**: Houses all switches and joysticks used for controlling the grabber's movement.
3. **Coin Input Board**: A basic circuit featuring a pull-down resistor connected to a switch for coin input control.
4. **Power Supply Board**: Ensures the entire system is powered correctly and safely.

## Project Structure

The project is organized as follows:

```
/CandyGrabber
├── src
│   ├── main.ino          # Main Arduino sketch
│   ├── CandyGrabber.cpp  # Class implementation
│   └── CandyGrabber.h    # Class declaration
├── lib                   # External libraries (if any)
└── platformio.ini        # PlatformIO configuration file
```

## Features

- **X, Y, Z Movement**: Control the grabber's movement in three dimensions.
- **User Input**: Responds to joystick and switch inputs to navigate and operate the grabber.
- **Timed Game Functionality**: The grabber operates for a set duration before returning to a designated position to release the candy.

## Future Development

While the current version utilizes the Arduino Uno for simplicity, there are plans to migrate to an ESP32 in the future, which will offer more GPIO pins and enhanced features for expanded functionality and improved performance.

### Upcoming Enhancements

- **Documentation**: A detailed guide on how to build the circuit and set up the project will be provided soon.
- **ESP32 Migration**: Transitioning to ESP32 for enhanced capabilities.
- **Timer Module**: Integration of a timer module to improve game functionality, allowing for better tracking of game duration.
- **Win Indicator**: Implementation of a light switch that will illuminate to indicate whether the player has won.
- **LED Indicators**: Addition of LEDs on top of the grabber for visual feedback during gameplay, enhancing user experience and interaction.

## Installation

To get started with this project:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/GoldenxSun/CandyGrabber.git
   cd CandyGrabber
   ```

2. **Open with PlatformIO**: Launch the project in PlatformIO for development and uploading.
   - You can use **Visual Studio Code** along with the **PlatformIO extension** for a smooth experience. Ensure you have installed the necessary libraries for the project.

3. **Upload to Arduino**: Connect your Arduino Uno and upload the sketch to your device.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.