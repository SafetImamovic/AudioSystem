#pragma once
#include "ElementarneKomponente.h"
#include <string>
class InfoPjesma : public ElementarneKomponente
{
private:
	
public:
	static sf::RectangleShape pozadinaLista;
	static sf::RectangleShape pozadinaPjesma;
	static sf::Vector2f pozicijaLista;
	static sf::Vector2f pozicijaPjesma;
	static sf::Vector2f dimenzijeLista;
	static sf::Vector2f dimenzijaPjesma;
	static sf::Color PrimarnaBoja;
	static int sirinaWindow;
	static int visinaWindow;
	static std::string NaslovPjesme;
	static sf::Text textNaslov;
	static std::string PjesniciPjesme;
	static sf::Text textPjesnici;
	static sf::Font font;
	static int PaddingVertical;
	static int PaddingHorizontal;
	static sf::RectangleShape CoverUpMain;
	static sf::RectangleShape CoverUpMainTwo;
	static sf::RectangleShape CoverUpSecondary;
	static sf::Texture Cover;
	static sf::Sprite CoverRender;
	static float rateNaslov;
	static float ratePjesnici;

	InfoPjesma() = default;
	static void SetPjesma(std::string naslov, std::string pjesnici, sf::Font &font);
	static void RenderPjesma(sf::RenderWindow& window);
	static void SetList();
	static void RenderList(sf::RenderWindow& window);
	static void Update();
};

