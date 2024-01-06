#include "SkuPjesama.h"
#include "Pjesma.h"

SkupPjesama::SkupPjesama(const std::string& ime) : Ime(ime) {}

void SkupPjesama::dodajPjesmu(const Pjesma& pjesma) {
    Pjesme.push_back(pjesma);
}

const std::vector<Pjesma>& SkupPjesama::dohvatiSvePjesme() const {
    return Pjesme;
}

std::vector<Pjesma> SkupPjesama::pretraziPjesme(const std::string& kriterijum) {
    std::vector<Pjesma> rezultati;
    for (const auto& pjesma : Pjesme) {
        if (pjesma.getIme().find(kriterijum) != std::string::npos ||
            pjesma.getImeAutora().find(kriterijum) != std::string::npos ||
            pjesma.getAlbum().find(kriterijum) != std::string::npos) {
            rezultati.push_back(pjesma);
        }
    }
    return rezultati;
}
