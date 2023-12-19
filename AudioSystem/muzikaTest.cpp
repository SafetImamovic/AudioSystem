﻿#include "muzikaTest.h"

// Globalni mutex printMutex koristi se za sinhronizaciju ispisa na konzoli
// kako bi se sprijecilo meðusobno preplitanje poruka kada se koristi više niti.
std::mutex printMutex;

WAVEFORMATEX waveformat;

// Konstruktor klase AudioPlayer
AudioPlayer::AudioPlayer()
{
    // Postavljanje inicijalnih vrijednosti clanova klase
    this->glasnocaJedan = 0xFFFF;
    this->glasnocaDva = 0xFFFF;
    this->glasnoca = MAKELONG(this->glasnocaJedan, this->glasnocaDva);
    this->trenutniIndeksPjesme = 0;
    this->seconds = 1;
    this->isPlaying = false;
    this->listaDisplayed = false;
    this->isPlaybackComplete = false;
    this->trajanjePjesme = music.getDuration().asSeconds();
    this->brzina = 1.0;
    this->effectiveSpeed = 1.0;
    this->tempVrijeme = sf::Time::Zero;
    this->startTime = sf::Time::Zero;
    this->pauseTime = sf::Time::Zero;
    this->newTime = sf::Time::Zero;
    this->currentTime = sf::Time::Zero;
    this->shouldStop = false;
    this->tempSekunde = 200;
    this->currentTimeInSeconds = 0.0;

  // timeTrackingThread = std::thread(&AudioPlayer::Vrijeme, this);

    this->waveFormat.wFormatTag = WAVE_FORMAT_PCM;
    this->waveFormat.nChannels = 2;
    this->waveFormat.nSamplesPerSec = 44100;
    this->waveFormat.wBitsPerSample = 16;
    this->waveFormat.nBlockAlign = (waveFormat.nChannels * waveFormat.wBitsPerSample) / 8;
    this->waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
    this->waveFormat.cbSize = 0;
    this->currentSamplePosition = 0;
}

// Glavna metoda za upravljanje audio playerom
void AudioPlayer::Pokreni() {
    int izbor;
    do {
        setNiz();
        Menu();
        std::cout << ">> ";
        std::cin >> izbor;
        if (izbor == 0) {
            Menu();
            std::cout << ">> ";
            std::cin >> izbor;
        }
        Izbornik(izbor);

    } while (izbor != 13);
}

// Inicijalizacija liste pjesama
void AudioPlayer::setNiz()
{
    ScanFolderForMusicFiles(".", songList);
}

// Ispis liste pjesama
void AudioPlayer::Lista() {
    const int indexWidth = 8;
    const int nameWidth = 60;

    // Ispisivanje zaglavlja tabele
    std::cout << std::left << std::setw(indexWidth) << "Mjesto " << std::setw(nameWidth) << " Pjesma" << std::endl;
    std::cout << '\n';
    // Ispisivanje svake pesme u tabeli
    for (size_t i = 0; i < songList.size(); i++) {
        std::cout << std::left << std::setw(indexWidth) << i + 1 << std::setw(nameWidth) << ImeFajlaBezEkstenzije(this->songList[i]) << std::endl;
        std::cout << "---------------------------------" << '\n';
    }

    std::cout << std::endl;
}

// Funkcija koja vraca ime fajla bez ekstenzije
std::string AudioPlayer::ImeFajlaBezEkstenzije(const std::string& filePath) {
    size_t lastDotPos = filePath.find_last_of(".");
    return filePath.substr(0, lastDotPos);
}

// Funkcija za ispis svih pjesama iako nisu dostupne
void AudioPlayer::sveLista() {
    for (const auto& song : songList) {
        std::cout << song << std::endl;
    }
    std::cout << std::endl;
}

// Ispis glavnog izbornika
void AudioPlayer::Menu() {
    system("cls");
    std::cout << '\n';
    std::cout << "       ***** (Unesi '0' za refresh) *****        " << std::endl;
    std::cout << '\n';
    std::cout << "       1.  Unesi ime                                        " << std::endl;
    std::cout << "       2.  Pusti/pauziraj                           *****    " << std::endl;
    std::cout << "       3.  Pojacaj                                  **  ***  " << std::endl;
    std::cout << "       4.  Smanji                                   **    *  " << std::endl;
    std::cout << "       5.  Lista                                    **      " << std::endl;
    std::cout << "       6.  Preskoci trenutnu pjesmu                 **      " << std::endl;
    std::cout << "       7.  Povratak na staru pjesmu                 **      " << std::endl;
    std::cout << "       8.  Premotaj unazad                        ****      " << std::endl;
    std::cout << "       9.  Premotaj unaprijed                    ******     " << std::endl;
    std::cout << "       10. Ubrzaj pjesmu                          ****      " << std::endl;
    std::cout << "       11. Uspori pjesmu" << std::endl;
    std::cout << "       12. Normalna brzina pjesme" << std::endl;
    std::cout << "       13. Exit" << std::endl;
    std::cout << '\n';
    std::cout << '\n';
    if (listaDisplayed) {
        Lista();
        std::cout << std::endl;
        std::cout << std::endl;
    }

    listaDisplayed = false;
}

// Metoda za izbor opcije iz glavnog izbornika
void AudioPlayer::Izbornik(int izbor) {
    switch (izbor) {
    case 1:
        this->isPlaying = false;
        unesiIme();
        break;
    case 2:
        pustiPauza();
        break;
    case 3:
        Pojacaj(0);
        break;
    case 4:
        Smanji();
        break;
    case 5:
        listaDisplayed = true;
        break;
    case 6:
        this->tempSekunde = 0;
        novaPjesma();
        break;
    case 7:
        this->tempSekunde = 0;
        staraPjesma();
        break;
    case 8:
        //std::cout << "Jos uvijek u testu!\n";
        //Sleep(1000);
        premotajUnazad();
        break;
    case 9:
        //std::cout << "Jos uvijek u testu!\n";
        //Sleep(1000);
        premotajUnaprijed();
        break;
    case 10:
        //std::cout << "Jos uvijek u testu!\n";
        //Sleep(1000);
        Ubrzaj();
        break;
    case 11:
        //std::cout << "Jos uvijek u testu!\n";
        //Sleep(1000);
        Uspori();
        break;
    case 12:
        music.setPitch(1);
        break;
    case 13:
        std::cout << "Hvala na koristenju!\n";
        break;
    default:
        std::cout << "Greska!" << std::endl;
    }
}

// Metoda za unos imena pjesme
void AudioPlayer::unesiIme() {
    std::string fileName;
    std::cout << "Unesi ime: ";
    std::cin.ignore();
    getline(std::cin, fileName);

    if (!std::filesystem::path(fileName).has_extension()) {
        fileName += ".wav";
    }

    bool found = false;
    for (size_t i = 0; i < songList.size(); i++) {
        if (fileName == songList[i]) {
            this->soundFilePath = fileName;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Nemamo tu pjesmu na stanju" << std::endl;
    }
    this->isPlaying = false;
    this->pauseTime = sf::Time::Zero;
    music.setPitch(1.0);
}

// Metoda za reprodukciju/pauziranje pjesme
void AudioPlayer::pustiPauza() {
    if (this->isPlaying) {
        this->glasnoca = getSystemVolume();
        // Zaustavljanje reprodukcije
        this->tempVrijeme = music.getPlayingOffset();
        music.stop();
        this->isPlaying = false;
        this->pauseTime = this->tempVrijeme;
        this->seconds = static_cast<int>(this->pauseTime.asSeconds());
        this->miliseconds = static_cast<int>(this->pauseTime.asMilliseconds());
        //this->isPlaybackComplete = true;
        
    }
    else {
        // Pokretanje reprodukcije
        
        music.openFromFile(soundFilePath);
        //music.setPitch(1.0);
        music.play();
        setSystemVolume(this->glasnoca);
        this->startTime = music.getPlayingOffset() - this->tempVrijeme;
        music.setPlayingOffset(this->pauseTime);
        this->trajanjePjesme = music.getDuration().asSeconds();
        this->isPlaying = true;
        this->isPlaybackComplete = false;
        this->shouldStop = false;
        this->pauseTime = this->tempVrijeme;
        // Pokretanje thread-a za pracenje vremena reprodukcije
        std::thread(&AudioPlayer::Vrijeme, this).detach();
        this->tempSekunde = 0;       
    }
}

// Metoda koja prati trajanje reprodukcije
void AudioPlayer::Vrijeme() {
    try {
        sf::Time lastOffset = sf::Time::Zero;
        while (!this->shouldStop && this->isPlaying && !this->isPlaybackComplete) {
            this->tempSekunde = static_cast<int>(this->seconds);

            if (this->shouldStop) {
                break;
            }

            if (!this->isPlaying) {
                break;
            }
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            //this->trajanjePjesme = music.getDuration().asSeconds();
            lastOffset = music.getPlayingOffset();

            this->currentTime = lastOffset;
            sf::Time playingOffset = music.getPlayingOffset();
            
            this->seconds = static_cast<int>(currentTime.asSeconds());
            this->miliseconds = static_cast<int>(currentTime.asMilliseconds());

            this->effectiveSpeed = this->brzina > 0 ? this->brzina : 1.0;
            this->seconds = static_cast<int>(currentTime.asSeconds() * effectiveSpeed);
            this->miliseconds = static_cast<int>(currentTime.asMilliseconds() * effectiveSpeed);

            // Ažurirajte trenutno vrijeme i broj uzoraka
            currentTimeInSeconds = static_cast<double>(this->seconds);
            currentSamplePosition = this->seconds * this->waveFormat.nSamplesPerSec;          
            
            {
                std::lock_guard<std::mutex> lockGuard(printMutex);
                
                    // Ispis trenutne pozicije pjesme
                std::cout << "\rTrenutna pjesma na radiju: " << ImeFajlaBezEkstenzije(soundFilePath) << std::flush
                    << " ( " << this->seconds / 60 << ":" << this->seconds % 60 << " )" << std::flush;
                   // << " " << tempSekunde << std::flush;
                        
                    
                    std::cout << "    >> ";
                
            }
           
            // Provjera završetka reprodukcije
            if (this->tempSekunde >= this->trajanjePjesme-2) {
                this->isPlaybackComplete = true;
                this->shouldStop = true;
                novaPjesma();
            }

            // Pokretanje nove pjesme nakon završetka trenutne
            //if (this->isPlaybackComplete) {              
             //   novaPjesma();
            //}
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Greska tokom pustanja: " << e.what() << std::endl;
        this->isPlaying = false;
        this->isPlaybackComplete = true;
    }
    catch (...) {
        std::cerr << "Nepoznata greska.\n";
        this->isPlaying = false;
        this->isPlaybackComplete = true;
        this->soundFilePath = this->songList[3];
        novaPjesma();
    }
    //std::thread(&AudioPlayer::Vrijeme, this).join();
}

// Metoda za prelazak na sljedecu pjesmu
void AudioPlayer::novaPjesma() {
    this->shouldStop = true;
    this->tempSekunde = 0;
    this->trenutniIndeksPjesme++;
        
    if (this->trenutniIndeksPjesme < this->songList.size()) {
        try {
            this->effectiveSpeed = 1.0;
            this->brzina = 1.0;
            music.stop();
            this->soundFilePath = songList[this->trenutniIndeksPjesme];
            music.openFromFile(soundFilePath);
            music.setPitch(1.0);
            PromijeniBrzinuReprodukcije(1.0);
            this->pauseTime = sf::Time::Zero;
            //this->currentTime = sf::Time::Zero;
            music.play();
            this->trajanjePjesme = music.getDuration().asSeconds();
            this->isPlaying = true;
            this->isPlaybackComplete = false;
            this->shouldStop = false;
            this->seconds = 1;
            this->miliseconds = 100;

            std::thread(&AudioPlayer::Vrijeme, this).detach();
        }catch (const std::exception& e) {
            std::cerr << "Greska tokom pokretanja: " << e.what() << std::endl;
        
            this->isPlaying = false;
            this->isPlaybackComplete = true;
        }
        catch (...) {
            std::cerr << "Random greska\n";
            this->isPlaying = false;
            this->isPlaybackComplete = true;            
        }
    }
    else {
        std::cout << "Kraj liste." << std::endl;
        this->shouldStop = true;
        this->soundFilePath = "Jala i Buba - Dale.wav";
        music.stop();
        music.play();
    }
}

// Metoda za prelazak na sljedecu pjesmu
void AudioPlayer::staraPjesma() {
    this->shouldStop = true;
    this->tempSekunde = 0;
    this->trenutniIndeksPjesme--;
    if (this->trenutniIndeksPjesme < this->songList.size()) {
        try {
            this->effectiveSpeed = 1.0;
            this->brzina = 1.0;
            music.stop();
            this->soundFilePath = songList[this->trenutniIndeksPjesme];
            music.openFromFile(soundFilePath);
            music.setPitch(1.0);
            PromijeniBrzinuReprodukcije(1.0);
            this->pauseTime = sf::Time::Zero;
            //this->currentTime = sf::Time::Zero;
            music.play();
            this->trajanjePjesme = music.getDuration().asSeconds();
            this->isPlaying = true;
            this->isPlaybackComplete = false;
            this->shouldStop = false;
            this->seconds = 1;
            this->miliseconds = 100;
            std::thread(&AudioPlayer::Vrijeme, this).detach();
        }
        catch (const std::exception& e) {
            std::cerr << "Greska tokom pokretanja: " << e.what() << std::endl;

            this->isPlaying = false;
            this->isPlaybackComplete = true;
        }
        catch (...) {
            std::cerr << "Random greska\n";
            this->isPlaying = false;
            this->isPlaybackComplete = true;
        }
    }
    else {
        std::cout << "Greska, ode ti." << std::endl;
        this->shouldStop = false;
        return;
    }
}

// Metoda za pojacavanje zvuka
void AudioPlayer::Pojacaj(float velicina) {

    DWORD currentVolume = getSystemVolume();

    WORD leftVolume = LOWORD(currentVolume);
    WORD rightVolume = HIWORD(currentVolume);

    if (leftVolume < 0xFFFF - 4000 && rightVolume < 0xFFFF - 4000) {
        leftVolume += 4000;
        rightVolume += 4000;
    }
    else
    {
        leftVolume = 0xFFFF;
        rightVolume = 0xFFFF;
    }

    DWORD newVolume = MAKELONG(leftVolume, rightVolume);

    setSystemVolume(newVolume);

    this->velicina = (static_cast<float>(newVolume) / 0xFFFF) / 0xFFFF;
}

// Metoda za smanjenje zvuka
void AudioPlayer::Smanji() {
    DWORD currentVolume = getSystemVolume();

    WORD leftVolume = LOWORD(currentVolume);
    WORD rightVolume = HIWORD(currentVolume);

    if (leftVolume > 4000 && rightVolume > 4000) {
        leftVolume -= 4000;
        rightVolume -= 4000;
    }
    else
    {
        leftVolume = 0;
        rightVolume = 0;
    }


    DWORD newVolume = MAKELONG(leftVolume, rightVolume);

    setSystemVolume(newVolume);

    this->velicina = (static_cast<float>(newVolume) / 0xFFFF) / 0xFFFF;
}

// Metoda za dobijanje trenutnog sistema zvuka
int AudioPlayer::getSystemVolume() {
    DWORD volume;
    waveOutGetVolume(0, &volume);
    return volume;
}

// Metoda za postavljanje sistema zvuka na novu vrijednost
void AudioPlayer::setSystemVolume(DWORD volume) {
    waveOutSetVolume(0, volume);
}

//    Metoda za premotavanje unazad tokom reprodukcije.
void AudioPlayer::premotajUnazad() {
    if (music.getStatus() == sf::Music::Playing) {
        sf::Time currentPosition = music.getPlayingOffset();

        sf::Time rewindDuration = sf::seconds(5.0f);
        currentPosition -= rewindDuration;

        music.setPlayingOffset(currentPosition);
        this->seconds -= 5.0;
    }
}

//    Metoda za premotavanje unaprijed tokom reprodukcije.
void AudioPlayer::premotajUnaprijed() {
    if (music.getStatus() == sf::Music::Playing) {
        sf::Time currentPosition = music.getPlayingOffset();

        sf::Time fastForwardDuration = sf::seconds(5.0f);
        currentPosition += fastForwardDuration;

        music.setPlayingOffset(currentPosition);
        this->seconds += 5.0;
    }
}

// Metoda koja skenira odredeni folder i popunjava set sa imenima muzickih fajlova.
void AudioPlayer::ScanFolderForMusicFiles(const std::string& folderPath, std::vector<std::string>& fileNames) {
    std::set<std::string> uniqueFileNames;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string fileName = entry.path().filename().string();
            std::string extension = entry.path().extension().string();

            if (extension == ".wav") {
                uniqueFileNames.insert(fileName);
            }
        }
    }

    fileNames.assign(uniqueFileNames.begin(), uniqueFileNames.end());
}

// Metoda za promjenu brzine reprodukcije pjesme
void AudioPlayer::PromijeniBrzinuReprodukcije(double faktor) {
    music.setPitch(faktor);
}

// Metoda koja pocevava brzinu reprodukcije
void AudioPlayer::Ubrzaj() {
    double novaBrzina = this->brzina * 1.2;
    PromijeniBrzinuReprodukcije(novaBrzina);
    this->brzina = novaBrzina;
}

// Metoda koja smanjuje brzinu reprodukcije
void AudioPlayer::Uspori() {
    double novaBrzina = this->brzina * 0.8;
    PromijeniBrzinuReprodukcije(novaBrzina);
    this->brzina = novaBrzina;
}

void AudioPlayer::SetGlasnoca(float velicina)
{
    if(velicina >= 0 && velicina <= 1)
        this->velicina = velicina;
    if (this->velicina < 0 || this->velicina > 1)
        return;

    DWORD currentVolume = getSystemVolume();

    WORD leftVolume = static_cast<WORD>(this->velicina * 0xFFFF);
    WORD rightVolume = static_cast<WORD>(this->velicina * 0xFFFF);

    DWORD newVolume = MAKELONG(leftVolume, rightVolume);

    setSystemVolume(newVolume);
    //std::cout << this->velicina << std::endl;
}


void AudioPlayer::SetPozicija(int sekunde)
{
    sf::Time time = sf::seconds(sekunde);
    music.setPlayingOffset(time);
}

size_t AudioPlayer::GetMiliSekunde()
{
    sf::Time current = music.getPlayingOffset();
    int PLAY = static_cast<int>(current.asMilliseconds());
    return PLAY;
}

float AudioPlayer::GetGlasnoca()
{
    if (this->velicina > 0 && this->velicina < 1)
    {
        return this->velicina;
    }
}

void AudioPlayer::Mute()
{
    std::cout << "MUTE!\n";
    if (this->velicina != 0)
    {
        this->TempGlasnoca = this->velicina;
        this->velicina = 0;
    }
    else
    {
        this->velicina = 1;
    }
    std::cout << this->velicina << "\n" << this->TempGlasnoca << "\n";
    this->SetGlasnoca(this->velicina);

}

size_t AudioPlayer::GetSekunde() const
{
    return this->seconds;
}

float AudioPlayer::GetTrajanjePjesme() const
{
    return this->trajanjePjesme;
}

// Destruktor klase AudioPlayer
AudioPlayer::~AudioPlayer()
{
    this->shouldStop = true;

   /* if (timeTrackingThread.joinable()) {
        timeTrackingThread.join();
    }*/
}