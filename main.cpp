#include <iostream>
#include <stdexcept>
#include "Nowy.h"
#include "Utils.h"

using namespace std;

int main() {
    String1 S1;

    while (true) {
        try {
            Utils::clearScreen();
            String1::displayHeader();
            Utils::drawLine('=', 52);

            cout << "\nMENU:\n";
            Utils::drawLine('-', 52);

            Utils::setColor(Utils::LIGHT_BLUE);
            cout << " 1) Replace text       - Replace part of the text\n";
            cout << " 2) Find text          - Search for specific text\n";
            cout << " 3) Remove text        - Delete part of the text\n";
            cout << " 4) Gender by name     - Guess gender by name\n";
            cout << " 5) Reverse text       - Reverse the text\n";
            cout << " 6) Concatenate        - Join two texts\n";
            cout << " 7) Insert text        - Add text at a position\n";
            cout << " 8) Copy text          - Copy part of the text\n";
            cout << " 9) ASCII converter    - Char → ASCII code\n";
            cout << "10) To uppercase       - Convert to UPPERCASE\n";
            cout << "11) To lowercase       - Convert to lowercase\n";
            cout << "12) Save to file       - Save current text\n";
            cout << "13) Load from file     - Load text from file\n";
            cout << "14) Help               - Show detailed help\n";
            cout << "15) Exit               - Quit program\n";
            Utils::setColor(Utils::WHITE);

            Utils::drawLine('-', 52);
            cout << "\nEnter choice [1-15]: ";
            int choice;
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw runtime_error("Please enter a number");
            }

            Utils::clearScreen();
            switch (choice) {
                case 1:  S1.zastap_fraze();   break;
                case 2:  S1.znajdz();         break;
                case 3:  S1.usun();           break;
                case 4:  S1.odgadnij();       break;
                case 5:  S1.kolejnosc();      break;
                case 6:  S1.polacz();         break;
                case 7:  S1.dopisz();         break;
                case 8:  S1.skopiuj();        break;
                case 9:  S1.ascii();          break;
                case 10: S1.duze();           break;
                case 11: S1.male();           break;
                case 12: S1.saveToFile();     break;
                case 13: S1.loadFromFile();   break;
                case 14: S1.displayHelp();    break;
                case 15: return 0;
                default: throw runtime_error("Invalid option");
            }

            Utils::waitForKeyPress();
        }
        catch (const exception& e) {
            Utils::setColor(Utils::LIGHT_RED);
            cerr << "\nError: " << e.what() << endl;
            Utils::setColor(Utils::WHITE);
            Utils::waitForKeyPress();
        }
    }
}
