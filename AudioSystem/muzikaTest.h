#pragma once
#pragma comment(lib, "Strmiids.lib")
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

class AudioPlayer {
private:
    std::vector<std::wstring> songList;
    std::wstring soundFilePath;
    bool isPlaying;
    bool listaDisplayed;
    bool isPlaybackComplete;
    int trenutniIndeksPjesme;
    int seconds;
    int trajanjePjesme;
    double currentTimeInSeconds;
    WAVEFORMATEX waveFormat;
    double currentSamplePosition;

public:
    AudioPlayer();

    ~AudioPlayer();

    void setNiz();

    void Pokreni();

    void Lista();

    std::wstring ImeFajlaBezEkstenzije(const std::wstring& filePath);

    void sveLista();

    void Menu();

    void Izbornik(int izbor);

    void unesiIme();

    void pustiPauza();

    void Pojacaj();

    void Smanji();

    void Vrijeme();

    int getSystemVolume();

    void setSystemVolume(DWORD volume);

    void novaPjesma();

    void premotajUnazad();

    void premotajUnaprijed();

    static void CALLBACK StartPlaybackCallbackStatic(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

    void StartPlaybackCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2);

    void ScanFolderForMusicFiles(const std::wstring& folderPath, std::vector<std::wstring>& fileNames);

};