#include "Nowy.h"
#include "Utils.h"
#include <algorithm>
#include <ctime>

using namespace std;

String1::String1() {
    logFile.open("string_operations.log", ios::app);
}

String1::~String1() {
    if (logFile.is_open()) logFile.close();
}

void String1::logError(const string& error) {
    if (logFile.is_open()) {
        auto now = time(nullptr);
        char buf[20];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
        logFile << buf << " | ERROR: " << error << endl;
    }
}

void String1::displayHeader() {
    Utils::setColor(Utils::LIGHT_PURPLE);
    cout << "****************************************************\n";
    cout << "*           String Operations Program              *\n";
    cout << "*              By Adrian Lesniak                   *\n";
    cout << "****************************************************\n\n";
    Utils::setColor(Utils::WHITE);
}

// 1) Replace
void String1::zastap_fraze() {
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\n[Replace] Enter the text to operate on:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    getline(cin >> ws, tekst);

    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nEnter start pos, length, and new text:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    int pos, len;
    string repl;
    cin >> pos >> len;
    getline(cin >> ws, repl);

    try {
        if (pos < 1 || pos > static_cast<int>(tekst.size()) || len < 0 || pos - 1 + len > static_cast<int>(tekst.size())) {
            logError("Replace failed: invalid position or length");
            throw runtime_error("Invalid position or length for replace");
        }
        tekst.replace(pos - 1, len, repl);
        cout << "\nResult: " << tekst << "\n";
    } catch (...) {
        logError("Replace failed");
        throw runtime_error("Replace operation error");
    }
}

// 2) Find
void String1::znajdz() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Find] Enter the text to search in:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nSearching in: \"" << tekst << "\"\n";
    cout << "[Find] Enter substring to search:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    string sub; cin >> sub;
    auto idx = tekst.find(sub);
    if (idx != string::npos)
        cout << "\nFound at position: " << idx + 1 << "\n";
    else
        cout << "\nNot found\n";
}

// 3) Remove
void String1::usun() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Remove] Enter the text to operate on:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nCurrent text: \"" << tekst << "\"\n";
    cout << "[Remove] Enter start pos and length:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    int pos, len; cin >> pos >> len;
    try {
        if (pos < 1 || pos > static_cast<int>(tekst.size()) || len < 0 || pos - 1 + len > static_cast<int>(tekst.size())) {
            logError("Remove failed: invalid position or length");
            throw runtime_error("Invalid position or length for remove");
        }
        tekst.erase(pos - 1, len);
        cout << "\nResult: " << tekst << "\n";
    } catch (...) {
        logError("Remove failed");
        throw runtime_error("Remove operation error");
    }
}

// 4) Gender guess
void String1::odgadnij() {
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\n[Gender] Enter a Polish name:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    string name; cin >> name;
    char last = tolower(name.back());
    cout << "\nGuessed: " << (last == 'a' ? "Female" : "Male") << "\n";
}

// 5) Reverse
void String1::kolejnosc() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Reverse] Enter the text to reverse:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nOriginal: " << tekst << "\n";
    Utils::setColor(Utils::WHITE);
    reverse(tekst.begin(), tekst.end());
    cout << "Reversed: " << tekst << "\n";
}

// 6) Concatenate
void String1::polacz() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Concat] Enter the base text:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nCurrent text: \"" << tekst << "\"\n";
    cout << "[Concat] Enter text to append:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    string extra; getline(cin >> ws, extra);
    tekst += extra;
    cout << "\nResult: " << tekst << "\n";
}

// 7) Insert
void String1::dopisz() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Insert] Enter the base text:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nCurrent text: \"" << tekst << "\"\n";
    cout << "[Insert] Enter pos and text:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    int pos; string add; cin >> pos; getline(cin >> ws, add);
    try {
        if (pos < 1 || pos > static_cast<int>(tekst.size()) + 1) {
            logError("Insert failed: invalid position");
            throw runtime_error("Invalid position for insert");
        }
        tekst.insert(pos - 1, add);
        cout << "\nResult: " << tekst << "\n";
    } catch (...) {
        logError("Insert failed");
        throw runtime_error("Insert operation error");
    }
}

// 8) Copy
void String1::skopiuj() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Copy] Enter the text to copy from:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nCurrent text: \"" << tekst << "\"\n";
    cout << "[Copy] Enter start pos and length:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    int pos, len; cin >> pos >> len;
    if (pos < 1 || pos > static_cast<int>(tekst.size()) || len < 0 || pos - 1 + len > static_cast<int>(tekst.size())) {
        logError("Copy failed: invalid position or length");
        throw runtime_error("Invalid position or length for copy");
    }
    cout << "\nCopied: " << tekst.substr(pos - 1, len) << "\n";
}

// 9) ASCII code
void String1::ascii() {
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\n[ASCII] Enter a character:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    char c; cin >> c;
    cout << "\nCode: " << int(c) << "\n";
}

// 10) Uppercase
void String1::duze() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Uppercase] Enter the text to convert:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    transform(tekst.begin(), tekst.end(), tekst.begin(), ::toupper);
    Utils::setColor(Utils::WHITE);
    cout << "\n" << tekst << "\n";
}

// 11) Lowercase
void String1::male() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Lowercase] Enter the text to convert:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
    Utils::setColor(Utils::WHITE);
    cout << "\n" << tekst << "\n";
}

// 12) Save to file
void String1::saveToFile() {
    Utils::setColor(Utils::LIGHT_GREEN);
    if (tekst.empty()) {
        cout << "\n[Save] Enter the text to save:\n" << Utils::SEPARATOR << "\n";
        Utils::setColor(Utils::WHITE);
        getline(cin >> ws, tekst);
    }
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nCurrent text: \"" << tekst << "\"\n";
    cout << "[Save] Enter filename:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    string fn; cin >> fn;
    ofstream f(fn);
    if (!f) throw runtime_error("Cannot open file");
    f << tekst;
    cout << "\nSaved successfully\n";
}

// 13) Load from file
void String1::loadFromFile() {
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\n[Load] Enter filename:\n" << Utils::SEPARATOR << "\n";
    Utils::setColor(Utils::WHITE);
    string fn; cin >> fn;
    ifstream f(fn);
    if (!f) throw runtime_error("Cannot open file");
    getline(f, tekst, '\0');
    cout << "\nLoaded text:\n" << tekst << "\n";
}

// 14) Detailed help
void String1::displayHelp() {
    Utils::setColor(Utils::LIGHT_YELLOW);
    cout << "\nDetailed Help:\n";
    Utils::drawLine();
    cout << "1) Replace:      repl[pos,len] = new_text\n"
            "2) Find:         search substring\n"
            "3) Remove:       erase(pos,len)\n"
            "4) Gender:       last-letter rule\n"
            "5) Reverse:      reverse text\n"
            "6) Concat:       append text\n"
            "7) Insert:       insert at pos\n"
            "8) Copy:         substr(pos,len)\n"
            "9) ASCII:        char → code\n"
           "10) Uppercase:   toupper()\n"
           "11) Lowercase:   tolower()\n"
           "12) Save:        write to file\n"
           "13) Load:        read from file\n"
           "14) Help:        this screen\n"
           "15) Exit:        quit program\n";
    Utils::setColor(Utils::WHITE);
}
