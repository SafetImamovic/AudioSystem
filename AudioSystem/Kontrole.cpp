#include "Kontrole.h"

void Kontrole::InicijalizacijaTipki()
{
	Tipka TipkaPoslije, TipkaPrije, TipkaPustiPauziraj, TipkaLoop;

	sf::Vector2f velicinaTipke = sf::Vector2f(this->visinaTipke, this->visinaTipke);

	int pocetnaKoordinataX = this->videoMode.width / 2 - this->sirinaTipke * 4 / 2;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke;
	//racuna donju granicu prozora

	TipkaPoslije.SetTipka(
		"Poslije",
		L"▷▷",
		velicinaTipke,
		32,
		sf::Color::White,
		this->PrimarnaBoja,
		this->font,
		sf::Vector2f(pocetnaKoordinataX + 2 * this->sirinaTipke, pocetnaKoordinataY),
		{ 22, 28 }
	);

	TipkaPrije.SetTipka(
		"Prije",
		L"◁◁",
		velicinaTipke,
		32,
		sf::Color::White,
		PrimarnaBoja,
		this->font,
		sf::Vector2f(pocetnaKoordinataX, pocetnaKoordinataY),
		{ 22, 28 }
	);

	TipkaPustiPauziraj.SetTipka(
		"PustiPauziraj",
		L"▶◼",
		velicinaTipke,
		32,
		sf::Color::White,
		PrimarnaBoja,
		this->font,
		sf::Vector2f(pocetnaKoordinataX + this->sirinaTipke, pocetnaKoordinataY),
		{ 22, 28 }
	);

	TipkaLoop.SetTipka(
		"Loop",
		L"⟳",
		velicinaTipke,
		50,
		sf::Color::White,
		PrimarnaBoja,
		this->font,
		sf::Vector2f(pocetnaKoordinataX + 3 * this->sirinaTipke, pocetnaKoordinataY),
		{ 27, 13 }
	);

	this->Tipke.push_back(TipkaPoslije);
	this->Tipke.push_back(TipkaPrije);
	this->Tipke.push_back(TipkaPustiPauziraj);
	this->Tipke.push_back(TipkaLoop);
}

void Kontrole::InicijalizacijaScroll()
{
	int scrollBarInnerVisina = 4;
	int scrollBarInnerSirina = this->sirinaScroll - 50;
	int pocetnaKoordinataX = this->videoMode.width/2 - this->sirinaScroll/2;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke - this->visinaScroll;

	this->ScrollPozadina.setSize(sf::Vector2f(this->sirinaScroll, this->visinaScroll));
	this->ScrollPozadina.setFillColor(sf::Color(30, 30, 30));
	this->ScrollPozadina.setPosition(sf::Vector2f(pocetnaKoordinataX, pocetnaKoordinataY));

	this->ScrollBar.setSize(sf::Vector2f(scrollBarInnerSirina, scrollBarInnerVisina));
	this->ScrollBar.setFillColor(sf::Color::White);
	this->ScrollBar.setPosition(sf::Vector2f(pocetnaKoordinataX + this->sirinaScroll / 2 - scrollBarInnerSirina / 2,
		pocetnaKoordinataY + this->visinaScroll / 2 - scrollBarInnerVisina / 2));

	this->ScrollSimbol.setFont(this->font);
	//this->ScrollSimbol.setString(L"⚫");
	this->ScrollSimbol.setString(L"|");
	this->ScrollSimbol.setPosition(sf::Vector2f(pocetnaKoordinataX + this->sirinaScroll/2 - scrollBarInnerSirina/2,
		pocetnaKoordinataY + this->visinaScroll/2 - scrollBarInnerVisina/2));
}

void Kontrole::InicijalizacijaGlasnoca()
{
	int glasnocaBarInnerVisina = 4;
	int glasnocaBarInnerSirina = this->sirinaGlasnoca - 50;

	int pocetnaKoordinataX = this->videoMode.width / 2 - this->sirinaGlasnoca / 2 + this->sirinaTipke*4/2;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke;

	this->GlasnocaPozadina.setSize(sf::Vector2f(this->sirinaGlasnoca, this->visinaGlasnoca));
	this->GlasnocaPozadina.setFillColor(sf::Color(30, 30, 30));
	this->GlasnocaPozadina.setPosition(sf::Vector2f(100 + pocetnaKoordinataX, pocetnaKoordinataY));

	this->GlasnocaBar.setSize(sf::Vector2f(glasnocaBarInnerSirina, glasnocaBarInnerVisina));
	this->GlasnocaBar.setFillColor(sf::Color::White);
	this->GlasnocaBar.setPosition(sf::Vector2f(100 + pocetnaKoordinataX + this->sirinaGlasnoca / 2 - glasnocaBarInnerSirina / 2,
		pocetnaKoordinataY + this->visinaGlasnoca / 2 - glasnocaBarInnerVisina / 2));

	this->GlasnocaSimbol.setFont(this->font);
	//this->GlasnocaSimbol.setString(L"⚫");
	this->GlasnocaSimbol.setString(L"|");
	this->GlasnocaSimbol.setPosition(sf::Vector2f(100 + pocetnaKoordinataX + this->sirinaGlasnoca / 2 - glasnocaBarInnerSirina / 2, -18 +
		pocetnaKoordinataY + this->visinaGlasnoca / 2 - glasnocaBarInnerVisina / 2));
}

float Kontrole::UpdatePozicijaSimbolaWindow(sf::RenderWindow &window)
{
	int scrollBarInnerVisina = 4;
	int scrollBarInnerSirina = this->sirinaScroll - 50;
	float pocetnaKoordinataX = this->videoMode.width / 2 - this->sirinaScroll / 2;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke - this->visinaScroll;
	
	if (this->Hover(window, this->ScrollPozadina))
	{
		/*
		this->ScrollSimbol.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x - 40, 575));
		int DonjaGranica = 360;
		int GornjaGranica = 900;
		
		float Interval = GornjaGranica - DonjaGranica;
		*/
		//std::cout << (sf::Mouse::getPosition(window).x - 10 - 360) / Interval  << "\n";
		std::cout << "nice";
		return ((sf::Mouse::getPosition(window).x - pocetnaKoordinataX) / this->sirinaScroll);
	}
	
}

float Kontrole::UpdatePozicijaSimbolaWindowGlasnoca(sf::RenderWindow& window)
{
	float pocetnaKoordinataX = this->videoMode.width / 2 - this->sirinaGlasnoca / 2 + this->sirinaTipke * 4 / 2;
	int glasnocaBarInnerVisina = 4;
	float pocetnaKoordinataYGlasnoca = this->videoMode.height - this->visinaTipke;
	if (this->Hover(window, this->GlasnocaPozadina))
	{
		this->GlasnocaSimbol.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x - 10, -18 +
			pocetnaKoordinataYGlasnoca + this->visinaGlasnoca / 2 - glasnocaBarInnerVisina / 2));
		return ((sf::Mouse::getPosition(window).x - pocetnaKoordinataX + 100) / this->sirinaGlasnoca) - 1;
	}
	
}

void Kontrole::UpdatePozicijaSimbola(float index)
{
	int scrollBarInnerVisina = 4;
	int scrollBarInnerSirina = 550;
	int pocetnaKoordinataX = this->videoMode.width / 2 - this->sirinaScroll / 2;

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke - this->visinaScroll;


	this->ScrollSimbol.setPosition(sf::Vector2f(index*(this->sirinaScroll) + pocetnaKoordinataX - 10, pocetnaKoordinataY + 5));
}

void Kontrole::RenderScroll(sf::RenderWindow &window)
{
	window.draw(this->ScrollPozadina);
	window.draw(this->ScrollBar);
	window.draw(this->ScrollSimbol);
}

void Kontrole::RenderGlasnoca(sf::RenderWindow& window)
{
	window.draw(this->GlasnocaPozadina);
	window.draw(this->GlasnocaBar);
	window.draw(this->GlasnocaSimbol);
}

void Kontrole::SetKontrole(sf::VideoMode &videoMode, sf::Font &font, sf::Color PirmarnaBoja, sf::Color SekundrnaBoja, sf::Color AkcenatBoja)
{
	this->videoMode = videoMode;
	this->font = font;
	this->PrimarnaBoja = PrimarnaBoja;
	this->SekundarnaBoja = SekundrnaBoja;
	this->AkcenatBoja = AkcenatBoja;

	this->InicijalizacijaTipki();
	this->InicijalizacijaScroll();
	this->InicijalizacijaGlasnoca();
}

void Kontrole::RenderVrijeme(sf::RenderWindow& window, float sekunde, float trajanje, sf::Color PrimarnaBoja)
{
	int pocetnaKoordinataX = this->videoMode.width / 2 - this->sirinaScroll / 2;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke - this->visinaScroll;

	sf::RectangleShape pozadina({ 150, 50 });
	pozadina.setFillColor(PrimarnaBoja);
	sf::Text text;
	text.setCharacterSize(16);
	text.setFont(this->font);
	std::string TEXT;


	TEXT = formatTime(sekunde) + " / " + formatTime(trajanje);
	pozadina.setPosition(sf::Vector2f(pocetnaKoordinataX + this->sirinaScroll, pocetnaKoordinataY));
	text.setPosition(sf::Vector2f(pocetnaKoordinataX + this->sirinaScroll + 2, pocetnaKoordinataY + 14));


	text.setString(TEXT);
	window.draw(pozadina);
	window.draw(text);
}