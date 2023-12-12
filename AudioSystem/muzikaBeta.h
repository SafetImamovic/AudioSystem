#pragma once
#pragma comment(lib, "Strmiids.lib")
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <algorithm>
#include <dshow.h>
#include <uuids.h>
#include <atlbase.h>
#include <filesystem>
#include <vector>
#include <set>
#include <Shellapi.h>
#include <fstream>
#include <SFML/Audio.hpp>

class AudioPlayer2 {
private:
    std::vector<std::wstring> songList2;
    std::wstring soundFilePath2;
    bool isPlaying2;
    bool listaDisplayed2;
    bool isPlaybackComplete2;
    int trenutniIndeksPjesme2;
    int seconds2;
    int trajanjePjesme2;
    double currentTimeInSeconds2;
    WAVEFORMATEX waveFormat2;
    double currentSamplePosition2;

public:
    AudioPlayer2();

    ~AudioPlayer2();

    void setNiz2();

    void Pokreni2();

    void Lista2();

    std::wstring ImeFajlaBezEkstenzije2(const std::wstring& filePath);

    void sveLista2();

    void Menu2();

    void Izbornik2(int izbor);

    void unesiIme2();

    void pustiPauza2();

    void Pojacaj2();

    void Smanji2();

    void Vrijeme2();

    int getSystemVolume2();

    void setSystemVolume2(DWORD volume);

    void novaPjesma2();

    void premotajUnazad2();

    void premotajUnaprijed2();

    static void CALLBACK StartPlaybackCallbackStatic2(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

    void StartPlaybackCallback2(UINT uTimerID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);

    void ScanFolderForMusicFiles2(const std::wstring& folderPath, std::vector<std::wstring>& fileNames);

    void PromijeniBrzinuReprodukcije2(double faktor);

    void Ubrzaj2();

    void Uspori2();

};