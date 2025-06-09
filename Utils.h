#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <limits>

namespace Utils {
    enum Color {
        WHITE        = 7,
        LIGHT_BLUE   = 11,
        LIGHT_GREEN  = 10,
        LIGHT_YELLOW = 14,
        LIGHT_PURPLE = 13,
        LIGHT_RED    = 12
    };

    const std::string SEPARATOR = "----------------------------------------";

    inline void setColor(Color c) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

    inline void drawLine(char ch = '-', int len = 52) {
        std::cout << std::string(len, ch) << "\n";
    }

    inline void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }

    inline void waitForKeyPress() {
        std::cout << "\n[Press Enter to return]";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}
