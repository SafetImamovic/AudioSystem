# Učitavanje Podataka (fstream)

## Funkcija koja učitava pjesme

```c++
  std::vector<Pjesma> SkupPjesama::ucitajPjesmeIzDatoteke(
    const std::string& filename
  );
```

Funkcija na početku programa je pozvana da učita sve pjesme koji su definirane u **PjesmeData.txt**
fajlu. **PjesmeData.txt** fajl sadrži definicije svih pjesama koje postoje u programu.

Funkcija nema zadanog delimitera tako da učitava čitavu jednu liniju .txt fajla kao string.
Taj string se onda u odnosu na atribut klase type cast-a u odgovarajući tip podatka.

- Dio funkcije koja vrši čitanje:
    ```c++
        // Dok uspješno čita iz fajla:
        while (std::getline(file, line)) {
            // Pretvara string "line" u istringstream objekat
            std::istringstream iss(line);
  
            //Ako je atribut objekta klase Pjesma int, uradi konverziju:
            std::getline(file, line);
            temp = line;
            idPjesme = std::atoi(temp.c_str());
            temp = "";
    ```

- Pošto se broj atributa ne mijenja, unaprijed funkcija učitava tačno **14** linija iz fajla, tih 14 linija predstavljaju atribute jedne pjesmu, daju putanju da player dođe do audio fajla koji odgovara pjesmi, daju putanju za cover, itd.

<code-block lang="plantuml">
   <![CDATA[
   @startuml

  class Pjesma {
  unsigned int ID_Pjesme;
  ..
  unsigned int ID_WAV;
  ..
  unsigned int ID_SLIKA;
  ..
  std::string lokacijaPjesme;
  ..
  std::string lokacijaSlike;
  ..
  std::string Ime;
  ..
  std::string ImeAutora;
  ..
  bool DaLiPripadaAlbumu;
  ..
  std::string Album;
  ..
  unsigned int ID_Album;
  ..
  std::string DatumObjave;
  ..
  std::string RecordLabel;
  ..
  std::string TrajanjePjesme;
  }

  @enduml
  ]]>
</code-block>
 
## Reprezentacija Pjesama u Bazi

> Tačno **14** linija .txt fajla predstavlja tačno **14**
> atributa koji se linerano mapiraju u atribute objekta Pjesme.
> Ako se promijeni redoslijed atributa .txt fajla ili
> obriše jedna linije ili više, poremetit će strukturu svih pjesama.
{style="warning"}

- Primjer dvije pjesme u **PjesmeData.txt** fajlu:

    ```
    ---------------------------------------------------------------
    1
    Pjesme/Skrillex & Boys Noize - Fine Day Anthem.wav
    Covers/Skrillex & Boys Noize - Fine Day Anthem.jpg
    Fine Day Anthem
    Skrillex & Boys Noize
    0
    0
    0
    1
    2023
    OWSLA
    3:13
    -
    ---------------------------------------------------------------
    2
    Pjesme/Skrillex with Bobby Raps - Leave Me Like This.wav
    Covers/Skrillex with Bobby Raps - Leave Me Like This.jpg
    Leave Me Like This
    Skrillex with Bobby Raps
    1
    0
    0
    1
    2023
    OWSLA
    3:08
    -
    ```
  
- Primjer učitavanja pjesme "Skrillex & Boys Noize - Fine Day Anthem"
  
  | **ID**  | Atributi Pjesme iz **PjesmeData.txt**              | Reprezentacija Objekta klase **Pjesma** |
  |---------|----------------------------------------------------|-----------------------------------------|
  | **1.**  | 64 puta '-' za redom                               | Označava početak atributa Pjesme        |
  | **2.**  | 1                                                  | Označava ID Pjesme                      |
  | **3.**  | Pjesme/Skrillex & Boys Noize - Fine Day Anthem.wav | Označava putanju .wav fajla Pjesme      |
  | **4.**  | Covers/Skrillex & Boys Noize - Fine Day Anthem.jpg | Označava putanju .jpg fajla Pjesme      |
  | **5.**  | Fine Day Anthem                                    | Označava ime Pjesme                     |
  | **6.**  | Skrillex & Boys Noize                              | Označava ime Autora Pjesme              |
  | **7.**  | 0                                                  | Označava bool da li pripada Albumu      |
  | **8.**  | 0                                                  | Označava ime Albuma                     |
  | **9.**  | 0                                                  | Označava ID Albuma                      |
  | **10.** | 1                                                  | Označava da li je lajkana Pjesma        |
  | **11.** | 2023                                               | Označava godinu release-a               |
  | **12.** | OWSLA                                              | Označava Record Label                   |
  | **13.** | 3:13                                               | Označava Trajanje Pjesme                |
  | **14.** | '-'                                                | Označava kraj svih atributa             |