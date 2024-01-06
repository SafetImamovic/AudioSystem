#pragma once
#include "SkuPjesama.h"

class PlayLista : public SkupPjesama {
private:
    std::string Kreator; // Dodan privatni atribut
    std::string DatumKreiranja; // Dodan privatni atribut

public:
    // Konstruktor
    PlayLista(const std::vector<Pjesma>& pjesme, const std::string& ime, const std::string& datumKreiranja,
        bool ponoviSkupPjesama, bool shuffle, std::string kreator);


    // Primjer dodavanja pjesme u playlistu
    void dodajPjesmuUPlaylistu(Pjesma& pjesma);

    // Primjer brisanja pjesme iz playliste
    void obrisiPjesmuIzPlayliste(Pjesma& pjesma);

    // Ažuriranje datuma kreiranja playliste
    void azurirajDatumKreiranja();

};

