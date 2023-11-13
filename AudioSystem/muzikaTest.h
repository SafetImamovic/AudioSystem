#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <iomanip>

class AudioPlayer {
private:
    std::string niz[10];
    std::string soundFilePath;
    bool isPlaying = false;
    bool listaDisplayed = false;

public:
    void setNiz();

    void Pokreni();

    void Lista(std::string niz[]);

    void Menu();

    void Izbornik(int izbor);

    void unesiIme();

    void pustiPauza();

    void Pojacaj();

    void Smanji();


    int getSystemVolume();


    void setSystemVolume(DWORD volume);

};