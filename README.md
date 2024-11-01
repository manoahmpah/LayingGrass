# LayingGrass 🌱

Welcome to **LayingGrass** – an exciting console-based strategy game where players compete to expand their territory by placing grass tiles on the board! The player with the largest area of grass at the end of the game wins!

## Table of Contents
1. [About the Game](#about-the-game)
2. [How to Play](#how-to-play)
3. [Features](#features)
4. [Installation](#installation)
5. [Game Preview](#game-preview)
6. [Instructions](#instructions)
7. [Game Rules](#game-rules)
8. [Technologies Used](#technologies-used)
9. [Contributing](#contributing)

---

## About the Game
**LayingGrass** is a strategic tile-placement game where players try to create the largest square of grass on a grid. Each player receives tiles that must touch their existing territory, leading to engaging tactical decisions. This project is built in **C++** and runs in the console, featuring ASCII art to enhance the experience.

## How to Play
1. **Start the game** from the main menu.
    - Players enter their names and choose colors.
    - Each player receives a starting 1x1 grass tile and a tile exchange coupon.
2. **Take turns** to place tiles adjacent to their territory.
3. **Complete nine rounds** and buy extra tiles using coupons.
4. **The player with the largest grass area** at the end wins!

## Features
- Dynamic gameplay with tile placement and strategic decision-making.
- Engaging grid-based board where players can compete.
- **Special squares** that provide bonuses such as tile exchange and tile theft.
- ASCII art and clear console design for an immersive gaming experience.

## Installation

### Prerequisites
- You will need a C++ compiler (e.g., GCC or Visual Studio) installed on your machine.

### Steps
1. Clone this repository:
    ```bash
    git clone https://github.com/mpahmanoah/LayingGrass.git
    ```

2. Navigate to the project directory:
    ```bash
    cd LayingGrass/src
    ```

3. Compile the game:
    ```bash
    g++ -o layinggrass main.cpp
    ```

4. Run the game:
    ```bash
    ./layinggrass
    ```

### Windows Users
If you're on Windows, you can use the provided `.bat` file to compile and run the game, or use your favorite IDE like Visual Studio.

## Game Preview
```
╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗
║                                                                                                      ║
║     ██╗      █████╗ ██╗   ██╗██╗███╗   ██╗ ██████╗      ██████╗ ██████╗  █████╗ ███████╗███████╗     ║
║     ██║     ██╔══██╗╚██╗ ██╔╝██║████╗  ██║██╔════╝     ██╔════╝ ██╔══██╗██╔══██╗██╔════╝██╔════╝     ║
║     ██║     ███████║ ╚████╔╝ ██║██╔██╗ ██║██║  ███╗    ██║  ███╗██████╔╝███████║███████╗███████╗     ║
║     ██║     ██╔══██║  ╚██╔╝  ██║██║╚██╗██║██║   ██║    ██║   ██║██╔══██╗██╔══██║╚════██║╚════██║     ║
║     ███████╗██║  ██║   ██║   ██║██║ ╚████║╚██████╔╝    ╚██████╔╝██║  ██║██║  ██║███████║███████║     ║
║     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝     ║
║                                                                                                      ║
║                               WELCOME TO THE LAYING GRASS STRATEGY GAME                              ║
║                                                                                                      ║
║                                 "Expand your territory and dominate!"                                ║
║                                                                                                      ║
║                                    ╔═══════════════════════════╗                                     ║
║                                    ║   [1] Start Game          ║                                     ║
║                                    ║   [2] Instructions        ║                                     ║
║                                    ║   [3] Setting             ║                                     ║
║                                    ║   [4] Exit                ║                                     ║
║                                    ╚═══════════════════════════╝                                     ║
║                                                                                                      ║
║                                  Select an option and press Enter...                                 ║
║                                                                                                      ║
╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝
```

## Instructions
- **Main Menu**: 
    - Press `1` to start a new game.
    - Press `2` to view game instructions.
    - Press `3` to go to setting.
    - Press `4` to exit the game.

- **Gameplay**:
    - Use the numeric keys to input coordinates (e.g., `4 7`) to attack.
    - The game continues until all ships from one player are sunk.
    
## Technologies Used
- **C++**: Core programming language for the game's logic.
- **ASCII Art**: For console-based visual effects and UI design.

## Contributing
Contributions are welcome! If you have any ideas or improvements for this project, feel free to fork the repository, create a feature branch, and submit a pull request.

### Steps for contributing:
1. Fork the project
2. Create a new branch (`git checkout -b feature-branch`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to the branch (`git push origin feature-branch`)
5. Open a pull request

---

**Enjoy the game, and may the best captain win!** 🛳️🔥

---

