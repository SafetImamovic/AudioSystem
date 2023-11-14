#include "muzikaTest.h"

// Globalni mutex printMutex koristi se za sinhronizaciju ispisa na konzoli
// kako bi se sprijeèilo meðusobno preplitanje poruka kada se koristi više niti.
std::mutex printMutex;


// Konstruktor klase AudioPlayer
AudioPlayer::AudioPlayer()
{
    // Postavljanje inicijalnih vrijednosti èlanova klase
    this->soundFilePath = "capcarap";
    this->trenutniIndeksPjesme = 0;
    this->seconds = 0;
    this->isPlaying = false;
    this->listaDisplayed = false;
    this->isPlaybackComplete = false;
    this->trajanjePjesme = 200;
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

    } while (izbor != 7);
}

// Inicijalizacija niza pjesama
void AudioPlayer::setNiz()
{
    niz[0] = "capcarap";
    niz[1] = "patrola";
    niz[2] = "dale";
    niz[3] = "do_gole_koze";
    niz[4] = "nepopravljivo";
    niz[5] = "rolex";
    niz[6] = "smack_that";
    niz[7] = "whiskey";
}

// Ispis liste pjesama
void AudioPlayer::Lista(std::string niz[]) {
    for (int i = 0; i < 10; i++) {
        std::cout << std::setw(2) << i + 1 << ". ";
        std::cout << std::setw(10) << niz[i] << " ";
    }
}

// Ispis glavnog izbornika
void AudioPlayer::Menu() {
    system("cls");
    std::cout << '\n';
    std::cout << "       ***** (Unesi '0' za refresh) *****        " << std::endl;
    std::cout << '\n';
    std::cout << "       1. Unesi ime" << std::endl;
    std::cout << "       2. Pusti/pauziraj" << std::endl;
    std::cout << "       3. Pojacaj" << std::endl;
    std::cout << "       4. Smanji" << std::endl;
    std::cout << "       5. Lista" << std::endl;
    std::cout << "       6. Preskoci trenutnu pjesmu" << std::endl;
    std::cout << "       7. Exit" << std::endl;
    std::cout << '\n';
    std::cout << '\n';
    if (listaDisplayed) {
        Lista(niz);
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
    bool found = false;
    for (int i = 0; i < 10; i++) {
        if (fileName == niz[i]) {
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
        PlaySound(NULL, 0, 0);
        this->isPlaying = false;
        this->seconds = 0;
        //->isPlaybackComplete = true;
    }
    else {
        // Pokretanje reprodukcije
        std::wstring wSoundFilePath(soundFilePath.begin(), soundFilePath.end());
        PlaySoundW(wSoundFilePath.c_str(), NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP | SND_NODEFAULT);
        this->trajanjePjesme = 200;
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

        {
            std::lock_guard<std::mutex> lockGuard(printMutex);
            // Ispis trenutne pozicije pjesme
            std::cout << "\rTrenutna pjesma na radiju: " << soundFilePath << std::flush
                << " ( " << this->seconds / 60 << ":" << this->seconds % 60 << " )" << std::flush;

            std::cout << " >> ";
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
    if (this->trenutniIndeksPjesme < 10) {
        this->soundFilePath = this->niz[this->trenutniIndeksPjesme];
        std::wstring wSoundFilePath(this->niz[this->trenutniIndeksPjesme].begin(), this->niz[this->trenutniIndeksPjesme].end());
        PlaySound(NULL, 0, 0);
        PlaySoundW(wSoundFilePath.c_str(), NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP | SND_NODEFAULT);
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

// Destruktor klase AudioPlayer
AudioPlayer::~AudioPlayer()
{
    return;
}