#pragma once
#include "ElementarneKomponente.h"
#include <string>
class InfoPjesma : public ElementarneKomponente
{
private:
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
	static sf::Font font;
public:
	InfoPjesma() = default;
	static void SetPjesma(std::string naslov, sf::Font &font);
	static void RenderPjesma(sf::RenderWindow& window);
	static void SetList();
	static void RenderList(sf::RenderWindow& window);
};

