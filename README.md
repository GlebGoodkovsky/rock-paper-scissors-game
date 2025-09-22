# Rock Paper Scissors Game in C++

## Overview

This is a console-based Rock Paper Scissors game written in C++. It allows players to play multiple rounds against the computer with colorful terminal output, emojis, and detailed statistics including win, loss, and draw percentages. The game offers a fun and interactive experience within the Linux terminal style.

## Features

- Randomized computer moves
- Player input validation with retries
- Colorful output using ANSI escape codes for enhanced terminal visuals
- Emoji representation for moves and results
- Animated countdown before each round
- Win/Loss/Draw tracking with percentage statistics
- Option to continue or exit after each round
- Decorative ASCII art styling

## How to Compile and Run

Make sure you have a C++ compiler (e.g., g++) installed on your system.

```bash
g++ game.cpp -o main

./main
```

Follow the on-screen prompts to play.

## System Requirements

- Linux terminal or any terminal supporting ANSI color codes and UTF-8 emojis
- C++ compiler (g++ recommended)

## How It Works

- Player is prompted to enter 'r', 'p', or 's' to choose Rock, Paper, or Scissors.
- The computer randomly selects its move.
- The program compares moves to decide a winner for the round.
- Game statistics are updated and displayed after each round.
- Player can choose to continue or exit.

## Known Limitations

- The program relies on the terminal's support for ANSI color and emoji characters; some terminals may render emoji incorrectly.
- No persistent save feature for stats across sessions.

## Future Enhancements

- Add sound effects or terminal beeps
- Include a graphical interface using libraries like ncurses
- Extend game variants (e.g., Rock-Paper-Scissors-Lizard-Spock)
- Add difficulty levels for the computer AI

## Credits & Acknowledgments

- AI assistance was used to help develop this project, learn, and experiment with the C++ language and terminal features.

---

Feel free to fork, use, and suggest improvements!
