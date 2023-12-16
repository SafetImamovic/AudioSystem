#include "ElementarneKomponente.h"

bool ElementarneKomponente::Hover(sf::RenderWindow& window, sf::RectangleShape oblik)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float tipkaPosX = oblik.getPosition().x;
	float tipkaPosY = oblik.getPosition().y;

	float tipkaXPosSirina = oblik.getPosition().x + oblik.getLocalBounds().width;
	float tipkaYPosVisina = oblik.getPosition().y + oblik.getLocalBounds().height;

	if (mouseX < tipkaXPosSirina && mouseX > tipkaPosX && mouseY < tipkaYPosVisina && mouseY > tipkaPosY)
		return true;
	return false;
}

void ElementarneKomponente::SetID(std::string ID)
{
	this->ID = ID;
}

std::string ElementarneKomponente::GetID()
{
	return this->ID;
}
