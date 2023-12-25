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
    std::string soundFilePath, stariFilePath;
    bool isPlaying;
    bool listaDisplayed;
    bool isPlaybackComplete;
    size_t trenutniIndeksPjesme;
    size_t seconds;
    size_t miliseconds;
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
    float velicina;
    float TempGlasnoca;
    WORD glasnocaJedan, glasnocaDva;
    DWORD glasnoca;
public:

    AudioPlayer();

    ~AudioPlayer();

    void setNiz(std::vector<std::string> pjesme);

    void Pokreni();

    void Lista();

    std::string ImeFajlaBezEkstenzije(const std::string& filePath);

    void sveLista();

    void Menu();

    void Izbornik(int izbor);

    void unesiIme(std::string fileName);

    void pustiPauza();

    void Pojacaj(float velicina);

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

    //Safet dodao ovo dole
    size_t GetSekunde() const;
    float GetTrajanjePjesme() const;
    void SetGlasnoca(float velicina);
    void SetPozicija(int sekunde);
    size_t GetMiliSekunde();
    float GetGlasnoca();
    void Mute();
    void PustiPjesmuPutanja(std::string putanja);
    std::string GetImePjesmePath();
    bool DaLiJeNovaPjesma(std::string TrenutnaPjesma);
};