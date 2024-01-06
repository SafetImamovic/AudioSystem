#pragma once
#include <vector>
#include "Pjesma.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
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

    SkupPjesama()=default;

    // Primjer dodavanja pjesme
    void dodajPjesmu(const Pjesma& pjesma);

    // Primjer dohvaæanja svih pjesama
    const std::vector<Pjesma>& dohvatiSvePjesme() const;

    // Funkcija za pretraživanje pjesama
    std::vector<Pjesma> pretraziPjesme(const std::string& kriterijum);

    //
    std::vector<Pjesma> ucitajPjesmeIzDatoteke(const std::string& filename);
};
