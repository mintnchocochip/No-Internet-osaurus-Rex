# Arduino Dino Game

This project recreates the classic Chrome Dinosaur Game on an Arduino platform. It's a fun and educational project that combines hardware and software to create an engaging game experience.

## Table of Contents
- [Overview](#overview)
- [Materials Required](#materials-required)
- [Game Mechanics](#game-mechanics)
- [Installation](#installation)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Contributing](#contributing)
- [Team](#team)

## Overview

The Arduino Dino Game is a recreation of the popular offline game found in Google Chrome. Players control a dinosaur character, making it jump to avoid obstacles. The game's difficulty increases as the player's score grows.

## Materials Required

- Arduino UNO board
- LCD display
- Switch key (Joystick)
- Custom PCB
- Buzzer (optional, for sound effects)

## Game Mechanics

1. **Movement**: Use the switch to control the dino's jumping.
2. **Obstacles**: Randomly generated trees appear on the screen, which the player must avoid.
3. **Scoring**: The player's score increases as they progress.
4. **Game Over**: Triggered upon collision with an obstacle.
5. **Restart**: Players can restart the game to try and beat their high score.

## Installation

1. Connect the hardware components according to the circuit diagram (not provided in this README).
2. Install the Arduino IDE on your computer.
3. Install the LiquidCrystal library if not already present.
4. Copy the provided source code into a new Arduino sketch.
5. Upload the sketch to your Arduino board.

## Usage

1. Power on the Arduino.
2. Press the switch key (A4) to start the game.
3. Use the switch to make the dinosaur jump and avoid obstacles.
4. Try to achieve the highest score possible!

## Code Structure

The main components of the code include:

- Game initialization
- Main game loop
- Character and obstacle generation
- Input handling
- Collision detection
- Score tracking

For a detailed look at the code, please refer to the source code section in the project files.

## Contributing

We welcome contributions to improve the Arduino Dino Game! Here are some ways you can contribute:

1. Report bugs
2. Suggest enhancements
3. Add new features
4. Improve documentation

Please feel free to fork the repository and submit pull requests.

## Team

This project was developed by:
- github.com/RK18113
- Palaniyappan 
- github.com/mintchocochip
- Madhan

## License

GNU Public License v3.0

---

We hope you enjoy playing and tinkering with the Arduino Dino Game! If you have any questions or suggestions, please open an issue in this repository.
