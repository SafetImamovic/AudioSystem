#include "muzikaTest.h"

void AudioPlayer::Pokreni() {
    int izbor;
    do {
        setNiz();
        Menu();
        std::cout << ">> ";
        std::cin >> izbor;
        Izbornik(izbor);

    } while (izbor != 6);
}

void AudioPlayer::setNiz()
{
    niz[0] = "capcarap";
    niz[1] = "hitler";
    niz[2] = "dale";
    niz[3] = "do gole koze";
    niz[4] = "nepopravljivo";
    niz[5] = "rolex";
    niz[6] = "smack that";
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
    std::cout << "1. Unesi ime" << std::endl;
    std::cout << "2. Pusti/pauziraj" << std::endl;
    std::cout << "3. Pojacaj" << std::endl;
    std::cout << "4. Smanji" << std::endl;
    std::cout << "5. Lista" << std::endl;
    std::cout << "6. Exit" << std::endl;
    if (isPlaying) {
        std::cout << "Trenutna pjesma na radiju: " << soundFilePath << '\n';
    }
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
    if (isPlaying) {
        PlaySound(NULL, 0, 0);
        isPlaying = false;
    }
    else {
        std::wstring wSoundFilePath(soundFilePath.begin(), soundFilePath.end());
        PlaySoundW(wSoundFilePath.c_str(), NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP | SND_NODEFAULT);
        isPlaying = true;
    }
}

void AudioPlayer::Pojacaj() {
    int newVolume = getSystemVolume() + 1000;
    setSystemVolume(newVolume);
}

void AudioPlayer::Smanji() {
    int newVolume = getSystemVolume() - 1000;
    setSystemVolume(newVolume);
}

int AudioPlayer::getSystemVolume() {
    DWORD volume;
    waveOutGetVolume(0, &volume);
    return LOWORD(volume);
}

void AudioPlayer::setSystemVolume(DWORD volume) {
    waveOutSetVolume(0, volume);
}