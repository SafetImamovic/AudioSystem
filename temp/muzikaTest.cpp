#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <iomanip>

using namespace std;

class AudioPlayer {
private:
    string niz[10] = { "capcarap", "hitler", "dale", "do gole koze", "nepopravljivo", "rolex", "smack that", "whiskey" };
    string soundFilePath = "";
    bool isPlaying = false;
    bool listaDisplayed = false;

public:
    void Pokreni() {
        int izbor;
        do {
            Menu();
            cout << ">> ";
            cin >> izbor;
            Izbornik(izbor);

        } while (izbor != 6);
    }

    void Lista(string niz[]) {
        for (int i = 0; i < 10; i++) {
            cout << setw(2) << i + 1 << ". ";
            cout << setw(10) << niz[i] << " ";
        }
    }

    void Menu() {
        system("cls");
        cout << '\n';
        cout << "1. Unesi ime" << endl;
        cout << "2. Pusti/pauziraj" << endl;
        cout << "3. Pojacaj" << endl;
        cout << "4. Smanji" << endl;
        cout << "5. Lista" << endl;
        cout << "6. Exit" << endl;
        if (isPlaying) {
            cout << "Trenutna pjesma na radiju: " << soundFilePath << '\n';
        }
        if (listaDisplayed) {
            Lista(niz);
            cout << endl;
            cout << endl;
        }

        listaDisplayed = false;
    }

    void Izbornik(int izbor) {
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
            cout << "Greska!" << endl;
        }

    }

    void unesiIme() {
        string fileName;
        cout << "Unesi ime: ";
        cin >> fileName;
        bool found = false;
        for (int i = 0; i < 10; i++) {
            if (fileName == niz[i]) {
                this->soundFilePath = fileName;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Nemamo tu pjesmu na stanju" << endl;
        }
    }

    void pustiPauza() {
        if (isPlaying) {
            PlaySound(NULL, 0, 0);
            isPlaying = false;
        }
        else {
            wstring wSoundFilePath(soundFilePath.begin(), soundFilePath.end());
            PlaySoundW(wSoundFilePath.c_str(), NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP | SND_NODEFAULT);
            isPlaying = true;
        }
    }
    
    void Pojacaj() {
        int newVolume = getSystemVolume() + 1000; 
        setSystemVolume(newVolume);
    }

    void Smanji() {
        int newVolume = getSystemVolume() - 1000; 
        setSystemVolume(newVolume);
    }

   
    int getSystemVolume() {
        DWORD volume;
        waveOutGetVolume(0, &volume);
        return LOWORD(volume);
    }

    
    void setSystemVolume(DWORD volume) {
        waveOutSetVolume(0, volume);
    }

};

int main() {
    AudioPlayer player;
    player.Pokreni();

    return 0;
}