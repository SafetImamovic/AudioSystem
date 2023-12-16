#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Tipka
{
private:
	sf::RectangleShape tipka;
	sf::Text text;

public:
	Tipka() = default;
	void SetTipka(std::string text, sf::Vector2f velicina, int karakterVelicina, sf::Color bojaText, sf::Color bojaPozadine);
	void SetFont(sf::Font& font);//posto sfml nema default fontova, moramo manuelno proslijedit font po referenci
	void PromijeniBojuPozadine(sf::Color boja);
	void PromijeniBojuTexta(sf::Color boja);
	void SetPozicija(sf::Vector2f pozicija);
	void DrawTo(sf::RenderWindow& window);
	bool Hover(sf::RenderWindow& window);
};

