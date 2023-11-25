#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

/*
	Klasa odgovorna za textbox, znaci mjesto gdje korisnik moze da kuca tekst
*/

class TextBox
{
private:
	sf::Text textbox;
	std::ostringstream text;
	bool jeOznacen = false;
	bool imaLimit = false;
	int Limit;

public:
	TextBox() = default;
	TextBox(int velicina, sf::Color boja, bool oznacen);
};