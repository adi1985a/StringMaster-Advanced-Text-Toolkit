#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Nowy.h"
#include "Utils.h"

using namespace std;

String1::String1() {
    logFile.open("string_operations.log", ios::app);
}

String1::~String1() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void String1::displayHeader() {
    Utils::setColor(Utils::LIGHT_PURPLE);
    cout << "****************************************************\n";
    cout << "*           String Operations Program               *\n";
    cout << "*              By Adrian Lesniak                   *\n";
    cout << "****************************************************\n";
    Utils::setColor(Utils::WHITE);
}

void String1::saveToFile() {
    string filename;
    cout << "Enter filename to save: ";
    cin >> filename;
    
    ofstream file(filename.c_str());
    if (file.is_open()) {
        file << tekst;
        cout << "Text saved successfully!\n";
        file.close();
    } else {
        throw runtime_error("Could not open file for writing");
    }
}

void String1::loadFromFile() {
    string filename;
    cout << "Enter filename to load: ";
    cin >> filename;
    
    ifstream file(filename.c_str());
    if (file.is_open()) {
        getline(file, tekst);
        cout << "Text loaded: " << tekst << endl;
        file.close();
    } else {
        throw runtime_error("Could not open file for reading");
    }
}

void String1::displayHelp() {
    Utils::setColor(Utils::LIGHT_GREEN);
    cout << "\nString Operations Help:\n";
    cout << "----------------------\n";
    cout << "1-3:  Text manipulation operations\n";
    cout << "4:    Gender detection (works with Polish names)\n";
    cout << "5-8:  Advanced text operations\n";
    cout << "9:    ASCII conversion tool\n";
    cout << "10-11: Case conversion utilities\n";
    cout << "12-13: File operations\n";
    cout << "14:    This help screen\n";
    cout << "15:    Exit the program\n";
    Utils::setColor(Utils::WHITE);
}

void String1::logError(const string& error) {
    if (logFile.is_open()) {
        time_t now = time(nullptr);
        string timestamp = ctime(&now);
        logFile << timestamp.substr(0, timestamp.length()-1) 
                << ": " << error << endl;
    }
}

void String1::wpisz_tekst() // choice 0
{

    cout << "\nEnter text: " ;
    cin >> tekst ;

}

// 1 Replace
void String1::zastap_fraze() //How to replace selected part of text
{
    int p,i;
    string z;
    cout << "Enter the position you want to replace: ";
    cin >> p;
    cout << "How many characters you want to enter: ";
    cin >> i;
    cout << "What to enter: ";
    cin >> z;

    tekst.replace(p-1,i,z);
//the replace function has 3 arguments:
//first - from which character to start replacing
//second - how many characters to replace
// third - what to replace it with, i.e. "Some Text"

    cout << tekst << endl;
    getchar();
    getchar();
}

// 2 Find
void String1::znajdz()
{

    cout << "What word are you looking for: ";
    cin >> szukaj;

    size_t pozycja = tekst.find(szukaj) ;
//size_t position - variable of the first position of the searched phrase in the text
//here is the 7th position because "cat" starts at the 7th position counting from 0 [as in the table]
//string.find(search) - function searching for a phrase from the "search" variable in the "string" variable

    if(pozycja!=string::npos)
// ! This condition will return true if the given phrase is found in the text
// and false if not found

    {
        cout << "\nWord: " << szukaj << " found in position: " << pozycja+1 << endl;
    }
    else
    {
        cout << "\nNot found." << endl;
    }
    getchar();
    getchar();

}

// 3 Delete
void String1::usun()
{

    int p,i;

    cout << "Enter the position to be deleted: ";
    cin >> p;
    cout << "Enter how many characters to delete: ";
    cin >> i;

    tekst.erase(p-1,i);

    cout << tekst ;
    getchar();
    getchar();


}

// 4 Guess
void String1::odgadnij()
{

    cout << "Please enter your name: " ;
    cin >> imie; // exp.Anna - all of polish woman names ends with "a"

    int dlugosc=imie.length(); // the length of the name in this case is 4 characters

    if(imie[dlugosc-1]=='a')
    {
// If the last letter of the name ends in a, then it's female
// name(length-1) - the last letter of the name, we number the tables from 0, so a[0]n[1]n[2]A[3]   {
        cout << "You are a woman!" ; // because the last letter of the name is "a", and women's names in polish usually end with an "a"
    }
    else
    {
        cout << "You are a man!" ; // if the name does not end in a, it must be masculine
    }
    getchar();
    getchar();


}

// 5 Order
void String1::kolejnosc()
{

    int dlugosc=tekst.length(); // it will be 4
//    cout << length;

    for (int i=(dlugosc-1); i>=0; i--) // (length-1) - last letter.
        //We count the arrays from 0! So 4-1=3 S[0]T[1]O[2]P[3]
    {
        cout << tekst[i] ;
    }
    getchar();
    getchar();

}

// 6 Connect
void String1::polacz()
{

    string cale;

    cout << "Enter what to add: ";
    cin >> tekst2;
    cale=tekst+tekst2;
    cout << cale << endl;
    getchar();
    getchar();

}

// 7 Add
void String1::dopisz()
{
    int gdzie;
    string dopis;

    cout << "Where to add: " ;
    cin >> gdzie;
    cout << "What to add: " ;
    cin >> dopis;

    tekst.insert(gdzie-1,dopis);
// the .insert function adds the text "Filemon" in position 11
// in parentheses, first the position where to add the text
//and then the text in quotes

    cout << endl << tekst ;
    getchar();
    getchar();


}

// 8 Copy
void String1::skopiuj()
{
    int gdzie, ile;

    cout << "Enter the start position to copy: ";
    cin >> gdzie;
    cout << "How many characters to copy: ";
    cin >> ile;


    string nowy_napis = tekst.substr(gdzie-1,ile); //new_inscription variable

// paste the copied part of string here
// the .substr(4,7) function extracts the specified part from inside the string string
//first argument - start with drawer 4 ("m") from string index
//second argument - extract(copy) 7 characters (copies "ala has a cat")

    cout << "Copied word: " << nowy_napis << " to the new_inscription variable" << endl;
    getchar();
    getchar();

}

// 9 Ascii table
void String1::ascii()
{

    char znak;
    cout << "Please enter a character: ";
    cin>>znak;
    cout << endl << (int)znak ;
    getchar();
    getchar();

}

// 10 Uppercase letters
void String1::duze()
{

    transform(tekst.begin(),tekst.end(),tekst.begin(),::toupper);
//:: toupper - function to convert string to uppercase
// At the beginning, we always give the transformation in brackets 4 arguments:
// first start.begin, end.end, then start.begin again
// and then the ::toupper function (turns the string to uppercase)

    cout << tekst; //"ALAN HAS A CAT"
    getchar();
    getchar();

}

// 11 Lowercase letters
void String1::male()
{

    transform(tekst.begin(),tekst.end(),tekst.begin(),::tolower);
//:: tolower - function to convert string to lower case

    cout << endl << tekst; //"Alan has a cat"
    getchar();
    getchar();

}
