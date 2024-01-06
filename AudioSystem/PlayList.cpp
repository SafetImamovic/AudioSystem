#include "PlayList.h"
#include <iostream> 

PlayLista::PlayLista(const std::vector<Pjesma>& pjesme, const std::string& ime, const std::string& datumKreiranja,
    bool ponoviSkupPjesama, bool shuffle, std::string kreator) : SkupPjesama(ime), Kreator(kreator) {

    // Inicijalizacija datuma kreiranja
    azurirajDatumKreiranja();
}

void PlayLista::dodajPjesmuUPlaylistu(Pjesma idPjesme) {
    Pjesma novaPjesma = pronadiPjesmuPoID(idPjesme);
    dodajPjesmu(novaPjesma);
    azurirajDatumKreiranja();
}

void PlayLista::obrisiPjesmuIzPlayliste(Pjesma idPjesme) {
    Pjesma pjesmaZaBrisanje = pronadiPjesmuPoID(idPjesme);
    obrisiPjesmu(pjesmaZaBrisanje);
    azurirajDatumKreiranja();
}

void PlayLista::azurirajDatumKreiranja() {
    // Primjer ažuriranja datuma kreiranja playliste
    // Ovaj primjer koristi jednostavno dodavanje 7 dana na trenutni datum kao ilustraciju i mozemo ga priolagoditi svoj projektu


    std::cout << "Datum kreiranja playliste azuriran." << std::endl;
 
}

