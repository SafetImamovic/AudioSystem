# Nasljeđivanje

# Primjer nasljeđivanja klasa: 

Klasa InfoPjesma:

<code-block lang="c++">
class InfoPjesma : public ElementarneKomponente
{
public:
	struct InfoPjesmaRender : public ElementarneKomponente //ovo je strukt za render pjesme koja ce se nalazit u centru GUI-a, skupina pjesama
	{
		static int BrojPjesama;
		int Visina = 40;
		int paddingHorizontal = 10;
		int paddingVertical = 12;
		sf::Color PrimarnaBoja = sf::Color(10, 10, 10);
		sf::Font font;
		sf::Font fontEmoji;
		std::string lokacijaSlike;
		std::string lokacijaPjesme;

		int intID;
		sf::Texture Cover;
		sf::Sprite CoverRender;

		sf::Text ID;
		sf::Text Ime;
		sf::Text ImeAutora;
		sf::Text TrajanjePjesme;
		sf::Text DodajPjesmuUPlaylist;
		sf::Text ObrisiPjesmuIzPlayliste;
		sf::Text Like;

		Tipka DodajTipka;

		sf::RectangleShape GlavnaPozadina;
		sf::RectangleShape ID_Cover_Ime_Pozadina;
		sf::RectangleShape Autor_Pozadina;
		sf::RectangleShape Trajanje_Add_Like_Pozadina;
		sf::RectangleShape DodajPjesmu;
		sf::RectangleShape ObrisiPjesmu;
};
</code-block>

Klasa TextBox:

<code-block lang="c++">
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


public:
static bool JE_OZNACEN;
sf::RectangleShape backgroundShape;
TextBox() = default;

	TextBox(const TextBox& original);//manuelni kopirni konstruktor jer stringstream objekat ima specificnu kopiju

	void SetTextBox(int velicina, sf::Color boja, bool oznacen);
	void SetFont(sf::Font& font);
	void SetPosition(sf::Vector2f pozicija);
	void SetLimit(bool ImaIliNema);
	void SetLimit(bool ImaIliNema, int Limit);
	void SetOznacen(bool oznacen);
	void SetBackground(sf::Color boja, sf::Vector2f velicina);
	void SetPozadinaPozicija(sf::Vector2f pozicija);
	void SetSve(std::string ID, int velicinaTeksta, sf::Color bojaTeksta, sf::Color bojaPozadine, bool oznacen, sf::Font& font, sf::Vector2f pozicija, sf::Vector2f padding, sf::Vector2f velicinaPozadine);
	bool JeOznacen();
	void Clear();
	void PromijeniBojuPozadine(sf::Color NovaBoja);
	void SetPadding(sf::Vector2f padding, sf::Vector2f pozicija);
	void PostaviVelicinu(sf::Vector2f velicina);
	std::string GetText();

	void DrawTo(sf::RenderWindow& window);
	void OtipkanoNa(sf::Event input);
};
</code-block>