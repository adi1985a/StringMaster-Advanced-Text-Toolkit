#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Utils.h"

class String1 {
private:
    std::string tekst;
    std::string tekst2;
    std::string szukaj;
    std::string imie;
    std::ofstream logFile;

public:
    String1();
    ~String1();
    
    void wpisz_tekst();
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
    
    // New functions
    void saveToFile();
    void loadFromFile();
    void displayHelp();
    void logError(const std::string& error);
    static void displayHeader();
};


