#pragma once
#include "SkuPjesama.h"

class PlayLista : public SkupPjesama {
private:

public:
    // Konstruktor
    PlayLista(const std::string& ime, const std::string& datumKreiranja,
        bool ponoviSkupPjesama, bool shuffle, std::string kreator) : SkupPjesama(ime, datumKreiranja, ponoviSkupPjesama, shuffle, kreator) {}


    /*
    // Primjer dodavanja pjesme u playlistu
    void dodajPjesmuUPlaylistu(Pjesma& pjesma);

    // Primjer brisanja pjesme iz playliste
    void obrisiPjesmuIzPlayliste(Pjesma& pjesma);
    */

    // Ažuriranje datuma kreiranja playliste
    void azurirajDatumKreiranja();

};

