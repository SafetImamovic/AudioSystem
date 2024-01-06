#pragma once
#include <vector>
#include "Pjesma.h"
#include <string>



class SkupPjesama {
protected:
    std::vector<Pjesma> Pjesme;
    std::string Ime;
    std::string DatumKreiranja;
    bool PonoviSkupPjesama;
    bool Shuffle;

public:

    // Getteri
    const std::vector<Pjesma>& getPjesme() const;
    std::string getIme() const;
    std::string getDatumKreiranja() const;
    bool getPonoviSkupPjesama() const;
    bool getShuffle() const;

    // Setteri
    void setPjesme(const std::vector<Pjesma>& pjesme);
    void setIme(const std::string& ime);
    void setDatumKreiranja(const std::string& datumKreiranja);
    void setPonoviSkupPjesama(bool ponoviSkupPjesama);
    void setShuffle(bool shuffle);


    SkupPjesama(const std::string& ime);

    // Primjer dodavanja pjesme
    void dodajPjesmu(const Pjesma& pjesma);

    // Primjer dohvaæanja svih pjesama
    const std::vector<Pjesma>& dohvatiSvePjesme() const;

    // Funkcija za pretraživanje pjesama
    std::vector<Pjesma> pretraziPjesme(const std::string& kriterijum);
};


class PlayLista : public SkupPjesama {
public:
    // Konstruktor
    PlayLista(const std::string& ime);

    // Funkcija za uèitavanje svih instanci/objekata
    void ucitajSveInstance(const SkupPjesama& skup);

    // Funkcija za pretraživanje pjesama
    void pretraziPjesme(const std::string& kriterijum);
};
