#include <iostream>
#include <string>
#include <cstdlib>
#include "Nowy.h"
#include "Utils.h"
#include <stdexcept>

/*
Operations on Strings.
1.  Replace the selected part of the word with another.
2.  Find the selected phrase in the text.
3.  Remove the selected phrase from the text.
4.  Guess the gender by name.
5.  Swap the word order.
6.  Add two words together.
7.  Add phrases to the text.
8.  Copy the phrase from the text and save it as a new variable.
9.  Convert numbers to ASCII characters.
10. Convert text to uppercase.
11. Convert text to lowercase.
*/
using namespace std;

int main() {
    String1 S1;
    
    while(true) {
        try {
            Utils::clearScreen();
            String1::displayHeader();
            Utils::drawLine('=');
            
            cout << "\nMENU:\n";
            Utils::drawLine('-');
            
            Utils::setColor(Utils::LIGHT_BLUE);
            cout << "1.  Replace text        - Replace part of the text with another\n";
            cout << "2.  Find text          - Search for specific text\n";
            cout << "3.  Remove text        - Delete part of the text\n";
            cout << "4.  Gender by name     - Guess gender from name\n";
            cout << "5.  Reverse text       - Change text order\n";
            cout << "6.  Concatenate        - Join two texts\n";
            cout << "7.  Insert text        - Add text at position\n";
            cout << "8.  Copy text          - Copy part of text\n";
            cout << "9.  ASCII converter    - Convert to ASCII\n";
            cout << "10. To uppercase       - Convert to uppercase\n";
            cout << "11. To lowercase       - Convert to lowercase\n";
            cout << "12. Save to file       - Save current text\n";
            cout << "13. Load from file     - Load text from file\n";
            cout << "14. Help              - Show detailed help\n";
            cout << "15. Exit              - End program\n";
            Utils::setColor(Utils::WHITE);

            Utils::drawLine('-');
            cout << "\nEnter your choice (1-15): ";
            
            int wybor;
            cin >> wybor;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input - please enter a number");
            }

            Utils::clearScreen();
            
            switch(wybor) {
                case 1: S1.zastap_fraze(); break;
                case 2: S1.znajdz(); break;
                case 3: S1.usun(); break;
                case 4: S1.odgadnij(); break;
                case 5: S1.kolejnosc(); break;
                case 6: S1.polacz(); break;
                case 7: S1.dopisz(); break;
                case 8: S1.skopiuj(); break;
                case 9: S1.ascii(); break;
                case 10: S1.duze(); break;
                case 11: S1.male(); break;
                case 12: S1.saveToFile(); break;
                case 13: S1.loadFromFile(); break;
                case 14: S1.displayHelp(); break;
                case 15: return 0;
                default: throw runtime_error("Invalid option selected");
            }
            
            Utils::waitForKeyPress();
            
        } catch (const exception& e) {
            Utils::setColor(Utils::LIGHT_RED);
            cout << "\nError: " << e.what() << endl;
            Utils::setColor(Utils::WHITE);
            Utils::waitForKeyPress();
        }
    }
    return 0;
}
