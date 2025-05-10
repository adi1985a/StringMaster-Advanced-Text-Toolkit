# String Operations Program

## Description
A C++ console application for performing various string operations. Supports text manipulation, gender guessing by name, ASCII conversion, case conversion, and file operations. Features a colorful interface and robust error handling. Created by Adrian Lesniak.

## Features
- Replace part of the text
- Find specific text
- Remove text
- Guess gender from name
- Reverse text order
- Concatenate texts
- Insert text at a position
- Copy part of text
- Convert to ASCII
- Convert to uppercase/lowercase
- Save/load text to/from file
- Display detailed help

## Requirements
- C++ compiler (e.g., g++)
- Header files: `Nowy.h` and `Utils.h` (not provided)
- Windows OS for full color functionality (via `Utils.h`)

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Ensure `Nowy.h` and `Utils.h` are in the project directory.
3. Compile the program:
   ```bash
   g++ main.cpp -o string_operations
   ```

## Usage
1. Run the program:
   ```bash
   ./string_operations
   ```
2. Choose options 1-15 from the menu:
   - 1: Replace text
   - 2: Find text
   - 3: Remove text
   - 4: Guess gender by name
   - 5: Reverse text
   - 6: Concatenate texts
   - 7: Insert text
   - 8: Copy text
   - 9: ASCII converter
   - 10: To uppercase
   - 11: To lowercase
   - 12: Save to file
   - 13: Load from file
   - 14: Show help
   - 15: Exit

## Notes
- Requires `Nowy.h` to define `String1` class with methods like `zastap_fraze()`, `znajdz()`, etc.
- `Utils.h` provides helper functions (e.g., `clearScreen()`, `setColor()`).
- Error handling ensures robust operation with invalid inputs.

## Author
Adrian Lesniak

## License
MIT License