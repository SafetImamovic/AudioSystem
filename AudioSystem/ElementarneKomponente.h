#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class ElementarneKomponente
{
private:
	std::string ID;
public:
	bool Hover(sf::RenderWindow& window, sf::RectangleShape oblik);
	void SetID(std::string ID);
	std::string GetID();

};
