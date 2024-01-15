# Klase

<code-block lang="plantuml">
   <![CDATA[
   @startuml

left to right direction

class AudioPlayer
{
sf::RenderWindow* window; //sf::RenderWindow definise prozor za GUI
std::unique_ptr<sf::RenderWindow> windowSmart;

sf::Event event; //event je objekat koji moze da poprimi vrijednost ili vrstu eventa koji se je desio unutar prozora,
..
//cak i van prozora ako je tako definisano
..
sf::VideoMode videoMode; //zadaje rezoluciju prozoru
..
sf::Vector2i mousePozProzor; //cuva poziciju misa relativnu prozoru (koordinate)
..
sf::Font font, fontBold, fontBoldest, fontEmoji;
..
Tipka PromijeniRezolucijuToggleTEST;
..
sf::Color PrimarnaBoja, SekundarnaBoja, AkcenatBoja;
..
float TempGlasnoca;
..
Kontrole kontrole;
..
AudioPlayer player;
..
InfoPjesma infoPjesma;
..
SkupPjesama* pSvePjesme; //deklarsina playlista kao njena nadklasa // polimorfizam
..
std::vector<std::string> NizPjesmi;
..
std::vector<InfoPjesma::InfoPjesmaRender> IPRMain;
..
std::vector<InfoPjesma::InfoPlaylisteRender> PRMain;
..
bool like;
..
bool DodavanjeUPlaylistAktivno = false;
..
std::vector<PlayLista> PlayListe;
..
int ID_TRENUTNE_PLAYLISTE;
..
int ID_PJESMA_ZA_DODAT;
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