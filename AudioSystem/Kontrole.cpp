#include "Kontrole.h"

void Kontrole::InicijalizacijaTipki()
{
	Tipka TipkaPoslije, TipkaPrije, TipkaPustiPauziraj, TipkaLoop;

	sf::Vector2f velicinaTipke = sf::Vector2f(this->visinaTipke, this->visinaTipke);

	this->pocetnaKoordinataX = this->videoMode.width / 2 - this->sirinaTipke * 4 / 2;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	this->pocetnaKoordinataY = this->videoMode.height - this->visinaTipke;
	//racuna donju granicu prozora

	TipkaPoslije.SetTipka(
		"Poslije",
		L"▷▷",
		velicinaTipke,
		32,
		sf::Color::White,
		this->PrimarnaBoja,
		this->font,
		sf::Vector2f(this->pocetnaKoordinataX + 2 * this->sirinaTipke, this->pocetnaKoordinataY),
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
		sf::Vector2f(this->pocetnaKoordinataX + this->sirinaTipke, this->pocetnaKoordinataY),
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
		sf::Vector2f(this->pocetnaKoordinataX + 3 * this->sirinaTipke, this->pocetnaKoordinataY),
		{ 27, 13 }
	);

	this->Tipke.push_back(TipkaPoslije);
	this->Tipke.push_back(TipkaPrije);
	this->Tipke.push_back(TipkaPustiPauziraj);
	this->Tipke.push_back(TipkaLoop);
}

void Kontrole::InicijalizacijaScroll()
{
	this->ScrollPozadina.setSize({ 600, 50 });
	this->ScrollPozadina.setFillColor(sf::Color(30, 30, 30));
	this->ScrollPozadina.setPosition({ 340, 570 });

	this->ScrollBar.setSize({ 550, 4 });
	this->ScrollBar.setFillColor(sf::Color::White);
	this->ScrollBar.setPosition({365, 592});

	this->ScrollSimbol.setFont(this->font);
	this->ScrollSimbol.setString(L"⚫");
	this->ScrollSimbol.setPosition({ 360, 575 });
}

void Kontrole::UpdatePozicijaSimbola(sf::RenderWindow &window)
{
	if (this->Hover(window, this->ScrollPozadina))
	{

		this->ScrollSimbol.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x - 10, 575));
		int DonjaGranica = 360;
		int GornjaGranica = 900;

		float Interval = GornjaGranica - DonjaGranica;

		

		std::cout << (sf::Mouse::getPosition(window).x - 10 - 360) / Interval << "\n";

	}

}

void Kontrole::RenderScroll(sf::RenderWindow &window)
{
	window.draw(this->ScrollPozadina);
	window.draw(this->ScrollBar);
	window.draw(this->ScrollSimbol);
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
}