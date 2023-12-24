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
std::string InfoPjesma::PjesniciPjesme;
sf::Text InfoPjesma::textPjesnici;
sf::Font InfoPjesma::font;
int InfoPjesma::PaddingVertical;
int InfoPjesma::PaddingHorizontal;
sf::RectangleShape InfoPjesma::CoverUpMain;
sf::RectangleShape InfoPjesma::CoverUpMainTwo;
sf::RectangleShape InfoPjesma::CoverUpSecondary;
sf::Texture InfoPjesma::Cover;
sf::Sprite InfoPjesma::CoverRender;
float InfoPjesma::rateNaslov = -0.25;
float InfoPjesma::ratePjesnici = -0.25;

void InfoPjesma::SetPjesma(std::string naslov, std::string pjesnici, sf::Font &font)
{
	InfoPjesma::PaddingVertical = 20;
	InfoPjesma::PaddingHorizontal = 20;
	InfoPjesma::NaslovPjesme = naslov;
	InfoPjesma::PjesniciPjesme = pjesnici;
	InfoPjesma::font = font;

	InfoPjesma::dimenzijaPjesma = sf::Vector2f(500, 1000);
	InfoPjesma::pozicijaPjesma = sf::Vector2f(0, 0);
	InfoPjesma::PrimarnaBoja = sf::Color(30, 30, 30);

	InfoPjesma::CoverUpMain.setSize(sf::Vector2f(InfoPjesma::PaddingHorizontal, 1000));
	InfoPjesma::CoverUpMain.setFillColor(sf::Color(30, 30, 30));
	InfoPjesma::CoverUpMain.setPosition(sf::Vector2f(500 - InfoPjesma::PaddingHorizontal, 0));

	InfoPjesma::CoverUpMainTwo.setSize(sf::Vector2f(InfoPjesma::PaddingHorizontal, 1000));
	InfoPjesma::CoverUpMainTwo.setFillColor(sf::Color(30, 30, 30));
	InfoPjesma::CoverUpMainTwo.setPosition(sf::Vector2f(0, 0));

	InfoPjesma::CoverUpSecondary.setSize(sf::Vector2f(4000, 900));
	InfoPjesma::CoverUpSecondary.setFillColor(sf::Color::Black);
	InfoPjesma::CoverUpSecondary.setPosition(sf::Vector2f(500, 0));

	InfoPjesma::textNaslov.setFont(InfoPjesma::font);
	InfoPjesma::textNaslov.setString(InfoPjesma::NaslovPjesme);
	std::cout << InfoPjesma::textNaslov.getGlobalBounds().width;

	InfoPjesma::textPjesnici.setFont(InfoPjesma::font);
	InfoPjesma::textPjesnici.setString(InfoPjesma::PjesniciPjesme);

	InfoPjesma::textNaslov.setPosition(
		InfoPjesma::pozicijaPjesma.x + InfoPjesma::PaddingHorizontal,
		InfoPjesma::pozicijaPjesma.y + InfoPjesma::PaddingVertical + 500
		);

	InfoPjesma::textPjesnici.setFillColor(sf::Color::White);

	InfoPjesma::textPjesnici.setPosition(
		InfoPjesma::pozicijaPjesma.x + InfoPjesma::PaddingHorizontal,
		InfoPjesma::pozicijaPjesma.y + InfoPjesma::PaddingVertical + 500 + InfoPjesma::textNaslov.getGlobalBounds().height + 20
	);

	InfoPjesma::textNaslov.setCharacterSize(36);
	InfoPjesma::textNaslov.setOutlineThickness(1);
	InfoPjesma::textNaslov.setOutlineColor(sf::Color::White);
	InfoPjesma::textPjesnici.setCharacterSize(28);

	InfoPjesma::textNaslov.setFillColor(sf::Color::White);

	InfoPjesma::pozadinaPjesma.setSize(InfoPjesma::dimenzijaPjesma);
	InfoPjesma::pozadinaPjesma.setPosition(InfoPjesma::pozicijaPjesma);
	InfoPjesma::pozadinaPjesma.setFillColor(InfoPjesma::PrimarnaBoja);

}

void InfoPjesma::RenderPjesma(sf::RenderWindow &window)
{
	window.draw(InfoPjesma::pozadinaPjesma);
	window.draw(InfoPjesma::textNaslov);
	window.draw(InfoPjesma::textPjesnici);
	window.draw(InfoPjesma::CoverUpMain);
	window.draw(InfoPjesma::CoverUpMainTwo);
	window.draw(InfoPjesma::CoverUpSecondary);
	window.draw(InfoPjesma::CoverRender);

	
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
		
		InfoPjesma::textNaslov.move(sf::Vector2f(InfoPjesma::rateNaslov, 0));
		std::cout << InfoPjesma::textNaslov.getPosition().x << "\n";
		if (InfoPjesma::textNaslov.getPosition().x == InfoPjesma::PaddingHorizontal + 1)
		{
			InfoPjesma::rateNaslov = -0.001;
		}
		else if (InfoPjesma::textNaslov.getPosition().x < InfoPjesma::PaddingHorizontal)
		{
			InfoPjesma::rateNaslov = -0.25;
		}
		if (InfoPjesma::textNaslov.getPosition().x <= -(InfoPjesma::textNaslov.getGlobalBounds().width + 10))
		{
			InfoPjesma::textNaslov.setPosition(sf::Vector2f(500 - InfoPjesma::PaddingHorizontal, 500 + InfoPjesma::PaddingVertical));
		}

	}

	if (InfoPjesma::textPjesnici.getGlobalBounds().width > 500 - InfoPjesma::PaddingHorizontal * 2)
	{
		InfoPjesma::textPjesnici.move(sf::Vector2f(InfoPjesma::ratePjesnici, 0));
		std::cout << InfoPjesma::textPjesnici.getPosition().x << "\n";
		if (InfoPjesma::textPjesnici.getPosition().x == InfoPjesma::PaddingHorizontal + 1)
		{
			InfoPjesma::ratePjesnici = -0.001;
		}
		else if (InfoPjesma::textPjesnici.getPosition().x < InfoPjesma::PaddingHorizontal)
		{
			InfoPjesma::ratePjesnici = -0.25;
		}
		if (InfoPjesma::textPjesnici.getPosition().x <= -(InfoPjesma::textPjesnici.getGlobalBounds().width + 10))
		{
			InfoPjesma::textPjesnici.setPosition(sf::Vector2f(500 - InfoPjesma::PaddingHorizontal, 500 + InfoPjesma::PaddingVertical + InfoPjesma::textNaslov.getGlobalBounds().height + 20));
		}
	}
}
