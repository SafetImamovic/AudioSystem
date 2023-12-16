#pragma once
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
#include <filesystem>
#include <vector>
#include <set>
#include <Shellapi.h>
#include <fstream>
#include <SFML/Audio/Music.hpp>
#include <cstring>
#include <mutex>


class AudioPlayer
{
private:
    std::vector<std::string> songList;
    std::string soundFilePath;
    bool isPlaying;
    bool listaDisplayed;  
    bool isPlaybackComplete;
    size_t trenutniIndeksPjesme;
    size_t seconds;
    float trajanjePjesme;
    double currentTimeInSeconds;
    WAVEFORMATEX waveFormat;
    size_t currentSamplePosition;
    std::mutex printMutex;
    sf::Music music;
    sf::Time tempVrijeme;
    double brzina;
    sf::Time startTime;
    sf::Time pauseTime;
    //std::thread timeTrackingThread;
    sf::Time newTime;
    sf::Time currentTime;
    bool shouldStop;
    double effectiveSpeed;
    int tempSekunde;


public:

    AudioPlayer();

    ~AudioPlayer();

    void setNiz();

    void Pokreni();

    void Lista();

    std::string ImeFajlaBezEkstenzije(const std::string& filePath);

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

    void staraPjesma();

    void premotajUnazad();

    void premotajUnaprijed();

    void ScanFolderForMusicFiles(const std::string& folderPath, std::vector<std::string>& fileNames);

    void PromijeniBrzinuReprodukcije(double faktor);

    void Ubrzaj();

    void Uspori();

};