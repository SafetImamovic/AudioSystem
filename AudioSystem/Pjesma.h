#pragma once

#include <string>

class Pjesma
{
private:
    unsigned int ID_WAV;
    unsigned int ID_SLIKA;
    std::string Ime;
    std::string ImeAutora;
    bool DaLiPripadaAlbumu;
    std::string Album;
    unsigned int ID_Album;
    bool DaLiJeLajkana;
    std::string DatumObjave;
    std::string RecordLabel;

public:
    Pjesma(unsigned int idWav, unsigned int idSlika, const std::string& ime, const std::string& imeAutora,
        bool pripadaAlbumu, const std::string& album, unsigned int idAlbum,
        bool jeLajkana, const std::string& datumObjave, const std::string& recordLabel);

    ~Pjesma();

    unsigned int getID_WAV() const;
    unsigned int getID_SLIKA() const;
    std::string getIme() const;
    std::string getImeAutora() const;
    bool getDaLiPripadaAlbumu() const;
    std::string getAlbum() const;
    unsigned int getID_Album() const;
    bool getDaLiJeLajkana() const;
    std::string getDatumObjave() const;
    std::string getRecordLabel() const;

    void setID_WAV(unsigned int idWav);
    void setID_SLIKA(unsigned int idSlika);
    void setIme(const std::string& ime);
    void setImeAutora(const std::string& imeAutora);
    void setDaLiPripadaAlbumu(bool pripadaAlbumu);
    void setAlbum(const std::string& album);
    void setID_Album(unsigned int idAlbum);
    void setDaLiJeLajkana(bool jeLajkana);
    void setDatumObjave(const std::string& datumObjave);
    void setRecordLabel(const std::string& recordLabel);
};

