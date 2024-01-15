# Audio System
---
## Opis Teme

Naš tim odlučio se fokusirati na izradu audio sistema pod nazivom "**Audio System**", 
koji će simulirati funkcionalnosti popularnih music streaming servisa. 
Ova tema je odabrana iz nekoliko važnih razloga koji kombiniraju tehnički izazov, 
korisničko iskustvo i relevantnost u današnjem digitalnom vremenu.

Prvenstveno, ova tema pruža izuzetnu priliku za primjenu koncepta **objektno 
orijentiranog programiranja** (**OOP**) u **C++**. Razvoj music streaming servisa zahtijeva dobro 
organiziranu strukturu podataka i modularni pristup, što savršeno odgovara OOP paradigmi. 
Korištenjem **klasa**, **objekata**, **nasljeđivanja** itd., planiramo stvoriti sistem koji je 
jednostavan za održavanje, proširivanje i ponovnu upotrebu.

Relevantnost teme također proizlazi iz trenutačnih trendova potrošnje medija. 
Digitalna distribucija muzike postala je dominantna, a streaming servisi su postali 
preferirani način pristupa muzičkom sadržaju.

Uzimajući u obzir navedene razloge, vjerujemo da je tema "**Audio System**" izazovna, 
relevantna i inspirativna. Kroz implementaciju ovog projekta, planiramo ne samo primijeniti 
stečena znanja iz programiranja već i stvoriti korisnički orijentiran, funkcionalan sustav koji će 
zadovoljiti potrebe ljubitelja muzike i entuzijasta tehnologije.

## Struktura Repozitorija

[Link AudioSystem Repozitorija](https://github.com/SafetImamovic/AudioSystem)

<code-block lang="plantuml">
   @startmindmap
   * AudioSystem
     ** Covers
     ** DLL
     ** External
     *** include
     **** SFML
     ***** Audio
     ***** Graphics
     ***** Network
     ***** System
     ***** Window
     *** lib
     *** Eman
     ** Fonts
     ** Pjesme
     ** PjesmeData.txt
  @endmindmap
</code-block>

<code-block lang="plantuml">
   <![CDATA[
   @startuml
   
   left to right direction
   
   class User {
   id : INTEGER
   int nice;
   ..
   other_id : INTEGER
   }
   
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
   
   
   
   class Pjesma2 {
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

<seealso>
<!--Give some related links to how-to articles-->
</seealso>
