# Virtuelne funckije

# Primjer koristenja virtualne funckije u klasi "SkupPjesama"

```c++
class SkupPjesama {
protected:
std::vector<Pjesma> Pjesme;
std::string Ime;
std::string DatumKreiranja;
bool PonoviSkupPjesama;
bool Shuffle;
std::string Kreator;
int BrojPjesama;

public:
virtual void operator + (const Pjesma& pjesma);
virtual void operator - (const Pjesma& pjesma);

    // Getteri
    virtual std::vector<Pjesma> &getPjesme();
    virtual std::string getIme() const;
    virtual std::string getImeKreatora() const;

    // Setteri
    virtual void setPjesme(std::vector<Pjesma>& pjesme);

    SkupPjesama(std::string ime, std::string datumKreiranja, bool ponovi, bool shuffle, std::string kreator);

    // Primjer dodavanja pjesme
    virtual void dodajPjesmu(const Pjesma& pjesma);

    virtual void IzbaciPjesmu(int index);

    // Primjer dohvaæanja svih pjesama
    virtual const std::vector<Pjesma>& dohvatiSvePjesme() const;

    // Funkcija za pretraživanje pjesama
    virtual std::vector<Pjesma> pretraziPjesme(const std::string& kriterijum);

    //
    virtual std::vector<Pjesma> ucitajPjesmeIzDatoteke(const std::string& filename);
};
```



