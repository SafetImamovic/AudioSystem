#include "SkuPjesama.h"
#include "Pjesma.h"


SkupPjesama::SkupPjesama(std::string ime, std::string datumKreiranja, bool ponovi, bool shuffle, std::string kreator)
    : Ime(ime), DatumKreiranja(datumKreiranja), PonoviSkupPjesama(ponovi), Shuffle(shuffle), Kreator(kreator){}

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

std::vector<Pjesma> SkupPjesama::ucitajPjesmeIzDatoteke(const std::string& filename)
{
    std::vector<Pjesma> pjesme;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nemoguæe otvoriti datoteku: " << filename << std::endl;
        return pjesme;
    }

    std::string line;
    std::string temp = "";

    int idPjesme = 0, idWav, idSlika, idAlbum;
    std::string lokacijaPjesme, lokacijeSlike, ime, imeAutora, album, datumObjave, recordLabel, trajanjePjesme;
    bool pripadaAlbumu, jeLajkana;

    while (std::getline(file, line)) {
        std::istringstream iss(line);

        std::getline(file, line); temp = line; idPjesme = std::atoi(temp.c_str()); temp = "";

        std::getline(file, line); temp = line;  lokacijaPjesme = temp; temp = "";

        std::getline(file, line); temp = line; lokacijeSlike = temp; temp = "";

        std::getline(file, line); temp = line; ime = temp; temp = "";

        std::getline(file, line); temp = line; imeAutora = temp; temp = "";

        std::getline(file, line); temp = line; pripadaAlbumu = std::atoi(temp.c_str()); temp = "";

        std::getline(file, line); temp = line; album = temp; temp = "";

        std::getline(file, line); temp = line; idAlbum = std::atoi(temp.c_str()); temp = "";

        std::getline(file, line); temp = line; jeLajkana = std::atoi(temp.c_str()); temp = "";

        std::getline(file, line); temp = line;  datumObjave = temp; temp = "";

        std::getline(file, line); temp = line; recordLabel = temp; temp = "";

        std::getline(file, line); temp = line; trajanjePjesme = temp; temp = "";

        std::getline(file, line); temp = line; temp = "";

        Pjesma p(idPjesme, lokacijaPjesme, lokacijeSlike, ime, imeAutora, pripadaAlbumu, album, idAlbum, jeLajkana, datumObjave, recordLabel, trajanjePjesme);
        pjesme.push_back(p);
    }

    file.close();
    return pjesme;
}

std::vector<Pjesma> SkupPjesama::getPjesme()
{
    return this->Pjesme;
}

void SkupPjesama::setPjesme(std::vector<Pjesma>& pjesme)
{
    this->Pjesme = pjesme;
}
