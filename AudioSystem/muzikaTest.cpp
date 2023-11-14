#include "muzikaTest.h"

std::mutex printMutex;

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

    } while (izbor != 6);
}

void AudioPlayer::setNiz()
{
    niz[0] = "capcarap";
    niz[1] = "hitler";
    niz[2] = "dale";
    niz[3] = "do_gole_koze";
    niz[4] = "nepopravljivo";
    niz[5] = "rolex";
    niz[6] = "smack_that";
    niz[7] = "whiskey";
}

void AudioPlayer::Lista(std::string niz[]) {
    for (int i = 0; i < 10; i++) {
        std::cout << std::setw(2) << i + 1 << ". ";
        std::cout << std::setw(10) << niz[i] << " ";
    }
}

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
    std::cout << "       6. Exit" << std::endl;
    std::cout << '\n';
    std::cout << '\n';
    if (listaDisplayed) {
        Lista(niz);
        std::cout << std::endl;
        std::cout << std::endl;
    }

    listaDisplayed = false;
}


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
        break;
    default:
        std::cout << "Greska!" << std::endl;
    }
}

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

void AudioPlayer::pustiPauza() {
    if (this->isPlaying) {
        PlaySound(NULL, 0, 0);
        this->isPlaying = false;
        this->isPlaybackComplete = true;
    }
    else {
        std::wstring wSoundFilePath(soundFilePath.begin(), soundFilePath.end());
        PlaySoundW(wSoundFilePath.c_str(), NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP | SND_NODEFAULT);
        this->isPlaying = true;
        this->isPlaybackComplete = false;

        std::thread(&AudioPlayer::Vrijeme, this).detach();
    }
}

void AudioPlayer::Vrijeme() {
    int seconds = 0;

    while (isPlaying) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        seconds++;

        {
            std::lock_guard<std::mutex> lockGuard(printMutex);
            std::cout << "\rTrenutna pjesma na radiju: " << soundFilePath
                << " ( " << seconds / 60 << ":" << seconds % 60 << " )" << std::flush;
        }

        if (!isPlaying) {
            break;
        }
    }
}

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


int AudioPlayer::getSystemVolume() {
    DWORD volume;
    waveOutGetVolume(0, &volume);
    return volume;
}

void AudioPlayer::setSystemVolume(DWORD volume) {
    waveOutSetVolume(0, volume);
}