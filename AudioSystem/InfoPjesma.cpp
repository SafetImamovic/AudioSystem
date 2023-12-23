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
int InfoPjesma::PaddingVertical;
int InfoPjesma::PaddingHorizontal;
sf::RectangleShape InfoPjesma::CoverUpMain;
sf::RectangleShape InfoPjesma::CoverUpSecondary;

void InfoPjesma::SetPjesma(std::string naslov, sf::Font &font)
{
	InfoPjesma::PaddingVertical = 20;
	InfoPjesma::PaddingHorizontal = 20;
	InfoPjesma::NaslovPjesme = naslov;
	InfoPjesma::font = font;

	InfoPjesma::dimenzijaPjesma = sf::Vector2f(500, 400);
	InfoPjesma::pozicijaPjesma = sf::Vector2f(0, 720 - 200);
	InfoPjesma::PrimarnaBoja = sf::Color(30, 30, 30);

	InfoPjesma::CoverUpMain.setSize(sf::Vector2f(InfoPjesma::PaddingHorizontal, 400));
	InfoPjesma::CoverUpMain.setFillColor(sf::Color(30, 30, 30));
	InfoPjesma::CoverUpMain.setPosition(sf::Vector2f(500 - InfoPjesma::PaddingHorizontal, 720 - 200));

	InfoPjesma::CoverUpSecondary.setSize(sf::Vector2f(4000, 400));
	InfoPjesma::CoverUpSecondary.setFillColor(sf::Color::Black);
	InfoPjesma::CoverUpSecondary.setPosition(sf::Vector2f(500, 720 - 200));


	InfoPjesma::textNaslov.setFont(InfoPjesma::font);
	InfoPjesma::textNaslov.setString(InfoPjesma::NaslovPjesme);
	std::cout << InfoPjesma::textNaslov.getGlobalBounds().width;

	

	InfoPjesma::textNaslov.setPosition(
		InfoPjesma::pozicijaPjesma.x + InfoPjesma::PaddingHorizontal,
		InfoPjesma::pozicijaPjesma.y + InfoPjesma::PaddingVertical
		);

	InfoPjesma::textNaslov.setFillColor(sf::Color::White);

	InfoPjesma::pozadinaPjesma.setSize(InfoPjesma::dimenzijaPjesma);
	InfoPjesma::pozadinaPjesma.setPosition(InfoPjesma::pozicijaPjesma);
	InfoPjesma::pozadinaPjesma.setFillColor(InfoPjesma::PrimarnaBoja);
}

void InfoPjesma::RenderPjesma(sf::RenderWindow &window)
{
	window.draw(InfoPjesma::pozadinaPjesma);
	window.draw(InfoPjesma::textNaslov);
	window.draw(InfoPjesma::CoverUpMain);
	window.draw(InfoPjesma::CoverUpSecondary);
}

void InfoPjesma::SetList()
{

}

void InfoPjesma::RenderList(sf::RenderWindow& window)
{
}

void InfoPjesma::Update()
{
	if (InfoPjesma::textNaslov.getGlobalBounds().width > 500 - InfoPjesma::PaddingHorizontal * 2)
	{
		InfoPjesma::textNaslov.move(sf::Vector2f(-0.4, 0));
		std::cout << InfoPjesma::textNaslov.getPosition().x << "\n";
		if (InfoPjesma::textNaslov.getPosition().x <= -(InfoPjesma::textNaslov.getGlobalBounds().width + 10))
		{
			InfoPjesma::textNaslov.setPosition(sf::Vector2f(500 - InfoPjesma::PaddingHorizontal, 720 - 200 + InfoPjesma::PaddingVertical));
		}
	}

	
}
