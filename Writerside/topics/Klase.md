# Klase
---
## Primjeri najvažniji klasa u programu


Klasa **AudioPlayer**

```c++
    class AudioPlayer
    {
    private:
    PlayLista* playLista;
    std::vector<Pjesma> Pjesme;
    std::string soundFilePath, stariFilePath;
    bool isPlaying;
    bool listaDisplayed;
    bool isPlaybackComplete;
    size_t trenutniIndeksPjesme;
    size_t seconds;
    size_t miliseconds;
    int trajanjePjesme;
    double currentTimeInSeconds;
    WAVEFORMATEX waveFormat;
    size_t currentSamplePosition;
    std::mutex printMutex;
    sf::Music music;
    sf::Time tempVrijeme;
    double brzina;
    sf::Time startTime;
    sf::Time pauseTime;
    sf::Time newTime;
    sf::Time currentTime;
    bool shouldStop;
    double effectiveSpeed;
    int tempSekunde;
    float velicina;
    float TempGlasnoca;
    WORD glasnocaJedan, glasnocaDva;
    DWORD glasnoca;
    float procenatBrzine;
    bool ponavlja;
    };
```

Klasa **AplikacijaGUI**:

```c++
class AplikacijaGUI
{
private:
	sf::RenderWindow* window; //sf::RenderWindow definise prozor za GUI
	std::unique_ptr<sf::RenderWindow> windowSmart;

	sf::Event event; //event je objekat koji moze da poprimi vrijednost ili vrstu eventa koji se je desio unutar prozora,
	sf::VideoMode videoMode; //zadaje rezoluciju prozoru
	sf::Vector2i mousePozProzor; //cuva poziciju misa relativnu prozoru (koordinate)
	sf::Font font, fontBold, fontBoldest, fontEmoji;
	Tipka PromijeniRezolucijuToggleTEST;
	sf::Color PrimarnaBoja, SekundarnaBoja, AkcenatBoja;
	float TempGlasnoca;
	Kontrole kontrole;
	AudioPlayer player;
	InfoPjesma infoPjesma;
	SkupPjesama* pSvePjesme; //deklarsina playlista kao njena nadklasa // polimorfizam
	std::vector<std::string> NizPjesmi;
	std::vector<InfoPjesma::InfoPjesmaRender> IPRMain;
	std::vector<InfoPjesma::InfoPlaylisteRender> PRMain;
	bool like;
	bool DodavanjeUPlaylistAktivno = false;
	std::vector<PlayLista> PlayListe;
	int ID_TRENUTNE_PLAYLISTE;
	int ID_PJESMA_ZA_DODAT;
};
```


Klasa **Kontrole** koja nasljeđuje klasu **ElementarneKomponente**:

```c++
class Kontrole : public ElementarneKomponente
{
private:
	int visinaTipke = 60, sirinaTipke = 60, sirinaScroll, visinaScroll = 50, visinaGlasnoca = 60, sirinaGlasnoca = 200;
	sf::VideoMode videoMode;
	sf::Font font, fontBoldest, fontEmoji;
	sf::Color PrimarnaBoja, SekundarnaBoja, AkcenatBoja;
	sf::RectangleShape ScrollPozadina, GlasnocaPozadina, GlasnocaProcenatPozadina, PlaybackBrzinaPozadina, PlaybackBrzinaProcenatPozadina;
	sf::Text ScrollSimbol, GlasnocaSimbol, PlaybackBrzinaSimbol, GlasnocaProcenat, PlaybackBrzinaProcenat;
	sf::RectangleShape ScrollBar, GlasnocaBar, PlaybackBrzinaBar, ScrollBarFollow, GlasnocaBarFollow, GlobalnaPozadina;
	int pocetnaKoordinataXTipke;
	sf::RectangleShape pozadinaVrijeme, pozadinaPlaybackBrzina;
	sf::Text textVrijeme, playbackBrzina;

};
```





Klasa **Pjesma**:

```c++
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
};
```



Klasa **TextBox** koja nasljeđuje klasu **ElementarneKomponente**:

```c++
class TextBox : public ElementarneKomponente
{
private:
	sf::Text textbox;

	std::ostringstream text;
	bool jeOznacen = false;
	bool imaLimit = false;
	int Limit;

	void InputLogika(int karakterIstipkan);
	void IzbrisiZadnjiKarakter();

};
```


Klasa **Tipka** koja nasljeđuje klasu **ElementarneKomponente**:

```c++
class Tipka : public ElementarneKomponente
{
private:

	sf::Text text;
public:
sf::RectangleShape tipka;
Tipka() = default;
void SetTipka(std::string ID, std::wstring text, sf::Vector2f velicina, int karakterVelicina, sf::Color bojaText, sf::Color bojaPozadine, sf::Font& font, sf::Vector2f pozicija, sf::Vector2f textPozicija);
void PromijeniBojuPozadine(sf::Color boja);
void PromijeniBojuTexta(sf::Color boja);
void SetPozicija(sf::Vector2f pozicija);
void DrawTo(sf::RenderWindow& window);
void SetTextUTF16(std::wstring text);
void SetTextPozicija(sf::Vector2f pozicija);
std::wstring GetTextUTF16();
sf::Text& GetText();
void PromijeniKarakter(std::wstring promjena);
sf::RectangleShape &getPozadina();
sf::Text getTextElement();

};
```
