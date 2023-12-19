#include "InfoPjesma.h"

sf::RectangleShape InfoPjesma::pozadinaLista;
sf::RectangleShape InfoPjesma::pozadinaPjesma;
sf::Vector2f InfoPjesma::pozicijaLista;
sf::Vector2f InfoPjesma::pozicijaPjesma;
sf::Vector2f InfoPjesma::dimenzijeLista;
sf::Vector2f InfoPjesma::dimenzijaPjesma;
sf::Color InfoPjesma::PrimarnaBoja;
std::string InfoPjesma::NaslovPjesme;
sf::Text InfoPjesma::textNaslov;
sf::Font InfoPjesma::font;

void InfoPjesma::SetPjesma(std::string naslov, sf::Font &font)
{
	InfoPjesma::NaslovPjesme = naslov;
	InfoPjesma::font = font;
	InfoPjesma::dimenzijaPjesma = sf::Vector2f(300, 200);
	InfoPjesma::pozicijaPjesma = sf::Vector2f(0, 720 - 200);
	InfoPjesma::PrimarnaBoja = sf::Color(30, 30, 30);

	InfoPjesma::textNaslov.setFont(InfoPjesma::font);
	InfoPjesma::textNaslov.setString(InfoPjesma::NaslovPjesme);

	InfoPjesma::textNaslov.setPosition(InfoPjesma::pozicijaPjesma);
	InfoPjesma::textNaslov.setFillColor(sf::Color::White);

	InfoPjesma::pozadinaPjesma.setSize(InfoPjesma::dimenzijaPjesma);
	InfoPjesma::pozadinaPjesma.setPosition(InfoPjesma::pozicijaPjesma);
	InfoPjesma::pozadinaPjesma.setFillColor(InfoPjesma::PrimarnaBoja);
}

void InfoPjesma::RenderPjesma(sf::RenderWindow &window)
{
	window.draw(InfoPjesma::pozadinaPjesma);
	window.draw(InfoPjesma::textNaslov);
}

void InfoPjesma::SetList()
{

}

void InfoPjesma::RenderList(sf::RenderWindow& window)
{
}
