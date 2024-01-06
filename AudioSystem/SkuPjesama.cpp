#include "SkuPjesama.h"
#include "Pjesma.h"


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

std::vector<Pjesma> ucitajPjesmeIzDatoteke(const std::string& filename) {
    std::vector<Pjesma> pjesme;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nemoguæe otvoriti datoteku: " << filename << std::endl;
        return pjesme;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);

        // Èitanje atributa iz linije
        unsigned int idPjesme, idWav, idSlika, idAlbum;
        std::string ime, imeAutora, album, datumObjave, recordLabel;
        bool pripadaAlbumu, jeLajkana;

        if (!(iss >> idPjesme >> idWav >> idSlika >> ime >> imeAutora >> pripadaAlbumu >> album >> idAlbum >> jeLajkana >> datumObjave)) {
            std::cerr << "Neuspelo èitanje linije iz datoteke." << std::endl;
            continue;
        }

        // Èitanje ostatka linije ako postoji
        std::getline(iss, recordLabel, '-');

        // Kreiranje objekta klase Pjesma i dodavanje u vektor
        Pjesma pjesma(idPjesme, idWav, idSlika, ime, imeAutora, pripadaAlbumu, album, idAlbum, jeLajkana, datumObjave, recordLabel);
        pjesme.push_back(pjesma);
    }

    file.close();
    return pjesme;
}