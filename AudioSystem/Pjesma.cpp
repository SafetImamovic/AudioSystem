
#include "Pjesma.h"

// Implementacija konstruktora
Pjesma::Pjesma(unsigned int idWav, unsigned int idSlika, const std::string& ime, const std::string& imeAutora,
    bool pripadaAlbumu, const std::string& album, unsigned int idAlbum,
    bool jeLajkana, const std::string& datumObjave, const std::string& recordLabel)
    : ID_WAV(idWav), ID_SLIKA(idSlika), Ime(ime), ImeAutora(imeAutora),
    DaLiPripadaAlbumu(pripadaAlbumu), Album(album), ID_Album(idAlbum),
    DaLiJeLajkana(jeLajkana), DatumObjave(datumObjave), RecordLabel(recordLabel)
{

}

// Implementacija destruktora
Pjesma::~Pjesma()
{
    // Nije potrebno ni�ta posebno osloba�ati jer ne koristimo dinami�ki alocirane resurse u ovoj klasi
}

// Implementacija gettera
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
    return DaLiJeLajkana;
}

std::string Pjesma::getDatumObjave() const
{
    return DatumObjave;
}

std::string Pjesma::getRecordLabel() const
{
    return RecordLabel;
}

// Implementacija settera
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
    DaLiJeLajkana = jeLajkana;
}

void Pjesma::setDatumObjave(const std::string& datumObjave)
{
    DatumObjave = datumObjave;
}

void Pjesma::setRecordLabel(const std::string& recordLabel)
{
    RecordLabel = recordLabel;
}
