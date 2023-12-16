#pragma once

#include <vector>
#include "ElementarneKomponente.h"
#include "TextBox.h"
#include "Tipka.h"

class Kontrole : public ElementarneKomponente
{
private:
	int visinaTipke = 100, sirinaTipke = 100, pocetnaKoordinataX, pocetnaKoordinataY;
	sf::VideoMode videoMode;
	sf::Font font;
	sf::Color PrimarnaBoja, SekundarnaBoja, AkcenatBoja;
	sf::RectangleShape ScrollPozadina;
	sf::Text ScrollSimbol;
	sf::RectangleShape ScrollBar;
public:

	std::vector<Tipka> Tipke;		//vektor koja cuva sve tipke
	void SetKontrole(sf::VideoMode &videoMode, sf::Font &font, sf::Color PirmarnaBoja, sf::Color SekundrnaBoja, sf::Color AkcenatBoja);

	
	void InicijalizacijaScroll();
	void InicijalizacijaTipki();
	void UpdatePozicijaSimbola(sf::RenderWindow& window);

	void RenderScroll(sf::RenderWindow &window);
};
