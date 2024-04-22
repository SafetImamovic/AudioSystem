#pragma once

#include <string>
#include <iostream>

class Pjesma {
private:
    unsigned int ID_Pjesme;
    unsigned int ID_WAV;
    unsigned int ID_SLIKA;
    std::string lokacijaPjesme;
    std::string lokacijaSlike;
    std::string Ime;
    std::string ImeAutora;
    bool DaLiPripadaAlbumu;
    std::string Album;
    unsigned int ID_Album;
    
    std::string DatumObjave;
    std::string RecordLabel;
    std::string TrajanjePjesme;

public:
    bool DaLiJeLajkana;
    Pjesma();
    Pjesma(unsigned int idPjesme, std::string lokacijaPjesme, std::string lokcijaSlike, const std::string& ime, const std::string& imeAutora,
        bool pripadaAlbumu, const std::string& album, unsigned int idAlbum,
        bool jeLajkana, const std::string& datumObjave, const std::string& recordLabel, const std::string &trajanjePjesme);

    ~Pjesma() = default;

    unsigned int getID_Pjesme() const;
    unsigned int getID_WAV() const;
    unsigned int getID_SLIKA() const;
    std::string getImePjesme() const;
    std::string getImeAutora() const;
    bool getDaLiPripadaAlbumu() const;
    std::string getAlbum() const;
    unsigned int getID_Album() const;
    bool getDaLiJeLajkana() const;
    std::string getDatumObjave() const;
    std::string getRecordLabel() const;
    std::string getTrajanjePjesme() const;

    void setID_Pjesme(unsigned int idPjesme);
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
    std::string getLokacijaPjesme() const;
    std::string getLokacijaSlike() const;
    void getInfo() const;
};

