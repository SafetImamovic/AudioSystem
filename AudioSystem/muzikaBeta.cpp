#include "muzikaBeta.h"

// Globalni mutex printMutex koristi se za sinhronizaciju ispisa na konzoli
// kako bi se sprijeèilo meðusobno preplitanje poruka kada se koristi više niti.
std::mutex printMutex;

WAVEFORMATEX waveformat;

// Konstruktor klase AudioPlayer
AudioPlayer::AudioPlayer()
{
    // Postavljanje inicijalnih vrijednosti èlanova klase
    this->soundFilePath = "Akon-SmackThat.wav";
    this->trenutniIndeksPjesme = 0;
    this->seconds = 0;
    this->isPlaying = false;
    this->listaDisplayed = false;
    this->isPlaybackComplete = false;
    this->trajanjePjesme = 200;

    waveFormat.wFormatTag = WAVE_FORMAT_PCM;
    waveFormat.nChannels = 2;
    waveFormat.nSamplesPerSec = 44100;
    waveFormat.wBitsPerSample = 16;
    waveFormat.nBlockAlign = (waveFormat.nChannels * waveFormat.wBitsPerSample) / 8;
    waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
    waveFormat.cbSize = 0;

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

    } while (izbor != 11);
}

// Inicijalizacija niza pjesama
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

// Funkcija koja vraæa ime fajla bez ekstenzije
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
    std::cout << "       1.  Unesi ime" << std::endl;
    std::cout << "       2.  Pusti/pauziraj" << std::endl;
    std::cout << "       3.  Pojacaj" << std::endl;
    std::cout << "       4.  Smanji" << std::endl;
    std::cout << "       5.  Lista" << std::endl;
    std::cout << "       6.  Preskoci trenutnu pjesmu" << std::endl;
    std::cout << "       7.  Premotaj unazad" << std::endl;
    std::cout << "       8.  Premotaj unaprijed" << std::endl;
    std::cout << "       9.  Ubrzaj pjesmu" << std::endl;
    std::cout << "       10. Uspori pjesmu" << std::endl;
    std::cout << "       11. Exit" << std::endl;
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
        unesiIme();
        break;
    case 2:
        pustiPauza();
        break;
    case 3:
        Pojacaj();
        break;
    case 4:
        Smanji();
        break;
    case 5:
        listaDisplayed = true;
        break;
    case 6:
        isPlaybackComplete = true;
        break;
    case 7:
        //std::cout << "Jos uvijek u testu!\n";
        //Sleep(1000);
        premotajUnazad();
        break;
    case 8:
        //std::cout << "Jos uvijek u testu!\n";
        //Sleep(1000);
        premotajUnaprijed();
        break;
    case 9:
        //std::cout << "Jos uvijek u testu!\n";
        //Sleep(1000);
        Ubrzaj();
        break;
    case 10:
        //std::cout << "Jos uvijek u testu!\n";
        //Sleep(1000);
        Uspori();
        break;
    case 11:
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
    std::cin >> fileName;

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
}

// Metoda za reprodukciju/pauziranje pjesme
void AudioPlayer::pustiPauza() {
    if (this->isPlaying) {
        // Zaustavljanje reprodukcije
        music.stop();
        this->isPlaying = false;
        this->seconds = 0;
        //->isPlaybackComplete = true;
    }
    else {
        // Pokretanje reprodukcije
        music.openFromFile(soundFilePath);
        music.play();
        this->trajanjePjesme = music.getDuration().asSeconds();
        this->isPlaying = true;
        this->isPlaybackComplete = false;

        // Pokretanje thread-a za praæenje vremena reprodukcije
        std::thread(&AudioPlayer::Vrijeme, this).detach();
    }
}

// Metoda koja prati trajanje reprodukcije
void AudioPlayer::Vrijeme() {
    while (this->isPlaying) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        this->seconds++;

        // Ažurirajte trenutno vrijeme i broj uzoraka
        currentTimeInSeconds = static_cast<double>(this->seconds);
        currentSamplePosition = this->seconds * this->waveFormat.nSamplesPerSec;

        {
            std::lock_guard<std::mutex> lockGuard(printMutex);
            // Ispis trenutne pozicije pjesme
            std::cout << "\rTrenutna pjesma na radiju: " << ImeFajlaBezEkstenzije(soundFilePath) << std::flush
                << " ( " << this->seconds / 60 << ":" << this->seconds % 60 << " )" << std::flush;

            std::cout << "    >> ";
        }

        // Provjera završetka reprodukcije
        if (this->seconds >= this->trajanjePjesme) {
            this->isPlaybackComplete = true;
        }

        // Pokretanje nove pjesme nakon završetka trenutne
        if (this->isPlaybackComplete) {
            novaPjesma();
            break;
        }
    }
}

// Metoda za prelazak na sljedeæu pjesmu
void AudioPlayer::novaPjesma() {
    this->trenutniIndeksPjesme++;
    if (this->trenutniIndeksPjesme < songList.size()) {
        this->soundFilePath = songList[this->trenutniIndeksPjesme];
        music.stop();
        music.openFromFile(soundFilePath);
        music.play();
        this->isPlaying = true;
        this->isPlaybackComplete = false;
        this->seconds = 0;
        std::thread(&AudioPlayer::Vrijeme, this).detach();
    }
}

// Metoda za pojaèavanje zvuka
void AudioPlayer::Pojacaj() {
    DWORD currentVolume = getSystemVolume();

    WORD leftVolume = LOWORD(currentVolume);
    WORD rightVolume = HIWORD(currentVolume);

    if (leftVolume < 0xFFFF - 8000) {
        leftVolume += 8000;
    }

    if (rightVolume < 0xFFFF - 8000) {
        rightVolume += 8000;
    }

    DWORD newVolume = MAKELONG(leftVolume, rightVolume);

    setSystemVolume(newVolume);
}

// Metoda za smanjenje zvuka
void AudioPlayer::Smanji() {
    DWORD currentVolume = getSystemVolume();

    WORD leftVolume = LOWORD(currentVolume);
    WORD rightVolume = HIWORD(currentVolume);

    if (leftVolume > 8000) {
        leftVolume -= 8000;
    }

    if (rightVolume > 8000) {
        rightVolume -= 8000;
    }

    DWORD newVolume = MAKELONG(leftVolume, rightVolume);

    setSystemVolume(newVolume);
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
    }
}

//    Metoda za premotavanje unaprijed tokom reprodukcije.
void AudioPlayer::premotajUnaprijed() {
    if (music.getStatus() == sf::Music::Playing) {
        sf::Time currentPosition = music.getPlayingOffset();

        sf::Time fastForwardDuration = sf::seconds(5.0f);
        currentPosition += fastForwardDuration;

        music.setPlayingOffset(currentPosition);
    }
}

// Metoda koja skenira odreðeni folder i popunjava set sa imenima muzièkih fajlova.
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


void AudioPlayer::PromijeniBrzinuReprodukcije(double faktor) {
    music.setPitch(faktor);
}


void AudioPlayer::Ubrzaj() {
    PromijeniBrzinuReprodukcije(1.3);
}

void AudioPlayer::Uspori() {
    PromijeniBrzinuReprodukcije(0.9);
}
// Destruktor klase AudioPlayer
AudioPlayer::~AudioPlayer()
{

}