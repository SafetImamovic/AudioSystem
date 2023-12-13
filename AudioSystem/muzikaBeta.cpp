#include "muzikaBeta.h"

// Globalni mutex printMutex koristi se za sinhronizaciju ispisa na konzoli
// kako bi se sprijeèilo meðusobno preplitanje poruka kada se koristi više niti.
std::mutex printMutex2;

WAVEFORMATEX waveformat2;

// Konstruktor klase AudioPlayer
AudioPlayer2::AudioPlayer2()
{
    // Postavljanje inicijalnih vrijednosti èlanova klase
    this->soundFilePath2 = L"Akon-SmackThat";
    this->trenutniIndeksPjesme2 = 0;
    this->seconds2 = 0;
    this->isPlaying2 = false;
    this->listaDisplayed2 = false;
    this->isPlaybackComplete2 = false;
    this->trajanjePjesme2 = 200;

    waveFormat2.wFormatTag = WAVE_FORMAT_PCM;
    waveFormat2.nChannels = 2;
    waveFormat2.nSamplesPerSec = 44100;
    waveFormat2.wBitsPerSample = 16;
    waveFormat2.nBlockAlign = (waveFormat2.nChannels * waveFormat2.wBitsPerSample) / 8;
    waveFormat2.nAvgBytesPerSec = waveFormat2.nSamplesPerSec * waveFormat2.nBlockAlign;
    waveFormat2.cbSize = 0;

}

// Glavna metoda za upravljanje audio playerom
void AudioPlayer2::Pokreni2() {
    int izbor;
    do {
        setNiz2();
        Menu2();
        std::cout << ">> ";
        std::cin >> izbor;
        if (izbor == 0) {
            Menu2();
            std::cout << ">> ";
            std::cin >> izbor;
        }
        Izbornik2(izbor);

    } while (izbor != 11);
}

// Inicijalizacija niza pjesama
void AudioPlayer2::setNiz2()
{
    ScanFolderForMusicFiles2(L".", songList2);
}

// Ispis liste pjesama
void AudioPlayer2::Lista2() {
    const int indexWidth = 8;
    const int nameWidth = 60;

    // Ispisivanje zaglavlja tabele
    std::wcout << std::left << std::setw(indexWidth) << L"Mjesto " << std::setw(nameWidth) << L" Pjesma" << std::endl;
    std::wcout << '\n';
    // Ispisivanje svake pesme u tabeli
    for (size_t i = 0; i < songList2.size(); i++) {
        std::wcout << std::left << std::setw(indexWidth) << i + 1 << std::setw(nameWidth) << ImeFajlaBezEkstenzije2(this->songList2[i]) << std::endl;
        std::cout << "---------------------------------" << '\n';
    }

    std::cout << std::endl;
}

// Funkcija koja vraæa ime fajla bez ekstenzije
std::wstring AudioPlayer2::ImeFajlaBezEkstenzije2(const std::wstring& filePath) {
    size_t lastDotPos = filePath.find_last_of(L".");
    return filePath.substr(0, lastDotPos);
}

// Funkcija za ispis svih pjesama iako nisu dostupne
void AudioPlayer2::sveLista2() {
    for (const auto& song : songList2) {
        std::wcout << song << std::endl;
    }
    std::cout << std::endl;
}

// Ispis glavnog izbornika
void AudioPlayer2::Menu2() {
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
    if (listaDisplayed2) {
        Lista2();
        std::cout << std::endl;
        std::cout << std::endl;
    }

    listaDisplayed2 = false;
}

// Metoda za izbor opcije iz glavnog izbornika
void AudioPlayer2::Izbornik2(int izbor) {
    switch (izbor) {
    case 1:
        unesiIme2();
        break;
    case 2:
        pustiPauza2();
        break;
    case 3:
        Pojacaj2();
        break;
    case 4:
        Smanji2();
        break;
    case 5:
        listaDisplayed2 = true;
        break;
    case 6:
        isPlaybackComplete2 = true;
        break;
    case 7:
        std::cout << "Jos uvijek u testu!\n";
        Sleep(1000);
        //premotajUnazad2();
        break;
    case 8:
        std::cout << "Jos uvijek u testu!\n";
        Sleep(1000);
        //premotajUnaprijed2();
        break;
    case 9:
        std::cout << "Jos uvijek u testu!\n";
        Sleep(1000);
        //Ubrzaj2();
        break;
    case 10:
        std::cout << "Jos uvijek u testu!\n";
        Sleep(1000);
        //Uspori2();
        break;
    case 11:
        std::cout << "Hvala na koristenju!\n";
        break;
    default:
        std::cout << "Greska!" << std::endl;
    }
}

// Metoda za unos imena pjesme
void AudioPlayer2::unesiIme2() {
    std::wstring fileName2;
    std::wcout << L"Unesi ime: ";
    std::wcin >> fileName2;

    if (!std::filesystem::path(fileName2).has_extension()) {
        fileName2 += L".wav";
    }

    bool found = false;
    for (size_t i = 0; i < songList2.size(); i++) {
        if (fileName2 == songList2[i]) {
            this->soundFilePath2 = fileName2;
            found = true;
            break;
        }
    }
    if (!found) {
        std::wcout << L"Nemamo tu pjesmu na stanju" << std::endl;
    }
}

// Metoda za reprodukciju/pauziranje pjesme
void AudioPlayer2::pustiPauza2() {
    if (this->isPlaying2) {
        // Zaustavljanje reprodukcije
        PlaySound(NULL, 0, 0);
        this->isPlaying2 = false;
        this->seconds2 = 0;
        //->isPlaybackComplete = true;
    }
    else {
        // Pokretanje reprodukcije
        std::wstring wSoundFilePath(soundFilePath2.begin(), soundFilePath2.end());
        PlaySoundW(wSoundFilePath.c_str(), NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP | SND_NODEFAULT);
        this->trajanjePjesme2 = 200;
        this->isPlaying2 = true;
        this->isPlaybackComplete2 = false;

        // Pokretanje thread-a za praæenje vremena reprodukcije
        std::thread(&AudioPlayer2::Vrijeme2, this).detach();
    }
}

// Metoda koja prati trajanje reprodukcije
void AudioPlayer2::Vrijeme2() {
    while (this->isPlaying2) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        this->seconds2++;

        // Ažurirajte trenutno vrijeme i broj uzoraka
        currentTimeInSeconds2 = static_cast<double>(this->seconds2);
        currentSamplePosition2 = this->seconds2 * this->waveFormat2.nSamplesPerSec;

        {
            std::lock_guard<std::mutex> lockGuard(printMutex2);
            // Ispis trenutne pozicije pjesme
            std::wcout << "\rTrenutna pjesma na radiju: " << ImeFajlaBezEkstenzije2(soundFilePath2) << std::flush
                << " ( " << this->seconds2 / 60 << ":" << this->seconds2 % 60 << " )" << std::flush;

            std::cout << "    >> ";
        }

        // Provjera završetka reprodukcije
        if (this->seconds2 >= this->trajanjePjesme2) {
            this->isPlaybackComplete2 = true;
        }

        // Pokretanje nove pjesme nakon završetka trenutne
        if (this->isPlaybackComplete2) {
            novaPjesma2();
            break;
        }
    }
}

// Metoda za prelazak na sljedeæu pjesmu
void AudioPlayer2::novaPjesma2() {
    this->trenutniIndeksPjesme2++;
    if (this->trenutniIndeksPjesme2 < songList2.size()) {
        this->soundFilePath2 = songList2[this->trenutniIndeksPjesme2];
        std::wstring wSoundFilePath(songList2[this->trenutniIndeksPjesme2].begin(), songList2[this->trenutniIndeksPjesme2].end());
        PlaySound(NULL, 0, 0);
        PlaySoundW(wSoundFilePath.c_str(), NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP | SND_NODEFAULT);
        this->isPlaying2 = true;
        this->isPlaybackComplete2 = false;
        this->seconds2 = 0;
        std::thread(&AudioPlayer2::Vrijeme2, this).detach();
    }
}

// Metoda za pojaèavanje zvuka
void AudioPlayer2::Pojacaj2() {
    DWORD currentVolume = getSystemVolume2();

    WORD leftVolume = LOWORD(currentVolume);
    WORD rightVolume = HIWORD(currentVolume);

    if (leftVolume < 0xFFFF - 8000) {
        leftVolume += 8000;
    }

    if (rightVolume < 0xFFFF - 8000) {
        rightVolume += 8000;
    }

    DWORD newVolume = MAKELONG(leftVolume, rightVolume);

    setSystemVolume2(newVolume);
}

// Metoda za smanjenje zvuka
void AudioPlayer2::Smanji2() {
    DWORD currentVolume = getSystemVolume2();

    WORD leftVolume = LOWORD(currentVolume);
    WORD rightVolume = HIWORD(currentVolume);

    if (leftVolume > 8000) {
        leftVolume -= 8000;
    }

    if (rightVolume > 8000) {
        rightVolume -= 8000;
    }

    DWORD newVolume = MAKELONG(leftVolume, rightVolume);

    setSystemVolume2(newVolume);
}

// Metoda za dobijanje trenutnog sistema zvuka
int AudioPlayer2::getSystemVolume2() {
    DWORD volume;
    waveOutGetVolume(0, &volume);
    return volume;
}

// Metoda za postavljanje sistema zvuka na novu vrijednost
void AudioPlayer2::setSystemVolume2(DWORD volume) {
    waveOutSetVolume(0, volume);
}

//    Metoda za premotavanje unazad tokom reprodukcije.
void AudioPlayer2::premotajUnazad2() {

}

//    Metoda za premotavanje unaprijed tokom reprodukcije.
void AudioPlayer2::premotajUnaprijed2() {

}

//Staticka metoda koja se poziva pri svakom "timer" dogaðaju tokom reprodukcije.
void CALLBACK AudioPlayer2::StartPlaybackCallbackStatic2(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2) {

}

//Metoda koja se poziva pri svakom "timer" dogaðaju tokom reprodukcije
void AudioPlayer2::StartPlaybackCallback2(UINT uTimerID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) {

}

// Metoda koja skenira odreðeni folder i popunjava set sa imenima muzièkih fajlova.
void AudioPlayer2::ScanFolderForMusicFiles2(const std::wstring& folderPath, std::vector<std::wstring>& fileNames) {
    std::set<std::wstring> uniqueFileNames;  // Set za spremanje jedinstvenih imena

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::wstring fileName = entry.path().filename();
            std::wstring extension = entry.path().extension();

            if (extension == L".wav") {
                uniqueFileNames.insert(fileName);  // Dodavanje u set za filtriranje duplikata
            }
        }
    }

    // Kopiranje elemenata iz seta u vektor
    fileNames.assign(uniqueFileNames.begin(), uniqueFileNames.end());
}

void AudioPlayer2::PromijeniBrzinuReprodukcije2(double faktor) {

}


void AudioPlayer2::Ubrzaj2() {
    PromijeniBrzinuReprodukcije2(2.0);
}

void AudioPlayer2::Uspori2() {
    PromijeniBrzinuReprodukcije2(0.8);
}

// Destruktor klase AudioPlayer
AudioPlayer2::~AudioPlayer2()
{

}