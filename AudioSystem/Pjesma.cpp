#include "Pjesma.h"

// Implementacija konstruktora

Pjesma::Pjesma()
    : ID_Pjesme(0), lokacijaPjesme(""), lokacijaSlike(""), Ime(""), ImeAutora(""),
    DaLiPripadaAlbumu(false), Album(""), ID_Album(0),
    DaLiJeLajkana(false), DatumObjave(""), RecordLabel(""), TrajanjePjesme("")
{

}

Pjesma::Pjesma(unsigned int idPjesme, std::string lokacijaPjesme, std::string lokcijaSlike, const std::string& ime, const std::string& imeAutora,
    bool pripadaAlbumu, const std::string& album, unsigned int idAlbum,
    bool jeLajkana, const std::string& datumObjave, const std::string& recordLabel, const std::string &trajanjePjesme)
    : ID_Pjesme(idPjesme), lokacijaPjesme(lokacijaPjesme), lokacijaSlike(lokcijaSlike), Ime(ime), ImeAutora(imeAutora),
    DaLiPripadaAlbumu(pripadaAlbumu), Album(album), ID_Album(idAlbum),
    DaLiJeLajkana(jeLajkana), DatumObjave(datumObjave), RecordLabel(recordLabel), TrajanjePjesme(trajanjePjesme)
{

}

// Implementacija gettera
unsigned int Pjesma::getID_Pjesme() const
{
    return ID_Pjesme;
}


unsigned int Pjesma::getID_WAV() const
{
    return ID_WAV;
}

unsigned int Pjesma::getID_SLIKA() const
{
    return ID_SLIKA;
}

std::string Pjesma::getIme() const
{
    return Ime;
}

std::string Pjesma::getImeAutora() const
{
    return ImeAutora;
}

bool Pjesma::getDaLiPripadaAlbumu() const
{
    return DaLiPripadaAlbumu;
}

std::string Pjesma::getAlbum() const
{
    return Album;
}

unsigned int Pjesma::getID_Album() const
{
    return ID_Album;
}

bool Pjesma::getDaLiJeLajkana() const
{
    return this->DaLiJeLajkana;
}

std::string Pjesma::getDatumObjave() const
{
    return this->DatumObjave;
}

std::string Pjesma::getRecordLabel() const
{
    return this->RecordLabel;
}

// Implementacija settera
void Pjesma::setID_Pjesme(unsigned int idPjesme)
{
    ID_Pjesme = idPjesme;
}

std::string Pjesma::getTrajanjePjesme() const
{
    return this->TrajanjePjesme;
}

void Pjesma::setID_WAV(unsigned int idWav)
{
    ID_WAV = idWav;
}

void Pjesma::setID_SLIKA(unsigned int idSlika)
{
    ID_SLIKA = idSlika;
}

void Pjesma::setIme(const std::string& ime)
{
    Ime = ime;
}

void Pjesma::setImeAutora(const std::string& imeAutora)
{
    ImeAutora = imeAutora;
}

void Pjesma::setDaLiPripadaAlbumu(bool pripadaAlbumu)
{
    DaLiPripadaAlbumu = pripadaAlbumu;
}

void Pjesma::setAlbum(const std::string& album)
{
    Album = album;
}

void Pjesma::setID_Album(unsigned int idAlbum)
{
    ID_Album = idAlbum;
}

void Pjesma::setDaLiJeLajkana(bool jeLajkana)
{
    this->DaLiJeLajkana = jeLajkana;
}

void Pjesma::setDatumObjave(const std::string& datumObjave)
{
    DatumObjave = datumObjave;
}

void Pjesma::setRecordLabel(const std::string& recordLabel)
{
    RecordLabel = recordLabel;
}

std::string Pjesma::getLokacijaPjesme() const
{
    return this->lokacijaPjesme;
}

std::string Pjesma::getLokacijaSlike() const
{
    return this->lokacijaSlike;
}

void Pjesma::getInfo() const
{
    std::cout << this->getID_Pjesme() << "\n";
    std::cout << this->getLokacijaPjesme() << "\n";
    std::cout << this->getLokacijaSlike() << "\n";
    std::cout << this->getIme() << "\n";
    std::cout << this->getImeAutora() << "\n";
    std::cout << this->getDaLiPripadaAlbumu() << "\n";
    std::cout << this->getAlbum() << "\n";
    std::cout << this->getID_Album() << "\n";
    std::cout << this->getDaLiJeLajkana () << "\n";
    std::cout << this->getDatumObjave() << "\n";
    std::cout << this->getRecordLabel() << "\n";
}


