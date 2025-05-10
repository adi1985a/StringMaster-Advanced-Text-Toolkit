#pragma once
#include <windows.h>
#include <iostream>
#include <limits>

namespace Utils {
    enum Color {
        WHITE = 7,
        LIGHT_BLUE = 11,
        LIGHT_GREEN = 10,
        LIGHT_RED = 12,
        LIGHT_YELLOW = 14,
        LIGHT_PURPLE = 13
    };

    inline void setColor(Color color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    inline void drawLine(char symbol = '-', int length = 50) {
        std::string line(length, symbol);
        std::cout << line << std::endl;
    }

    inline void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    inline void waitForKeyPress() {
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}
