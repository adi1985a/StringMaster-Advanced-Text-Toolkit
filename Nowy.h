#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Utils.h"

class String1 {
private:
    std::string tekst;
    std::ofstream logFile;

    void logError(const std::string& error);

public:
    String1();
    ~String1();

    static void displayHeader();

    void zastap_fraze();
    void znajdz();
    void usun();
    void odgadnij();
    void kolejnosc();
    void polacz();
    void dopisz();
    void skopiuj();
    void ascii();
    void duze();
    void male();

    void saveToFile();
    void loadFromFile();
    void displayHelp();
};
