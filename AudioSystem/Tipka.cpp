#include "Tipka.h"

void Tipka::SetTipka(std::string text, sf::Vector2f velicina, int karakterVelicina, sf::Color bojaText, sf::Color bojaPozadine)
{
	this->text.setString(text);
	this->text.setFillColor(bojaText);
	this->text.setCharacterSize(karakterVelicina);

	this->tipka.setSize(velicina);
	this->tipka.setFillColor(bojaPozadine);
}

void Tipka::SetFont(sf::Font& font)
{
	this->text.setFont(font);
}

void Tipka::PromijeniBojuPozadine(sf::Color boja)
{
	this->tipka.setFillColor(boja);
}

void Tipka::PromijeniBojuTexta(sf::Color boja)
{
	this->text.setFillColor(boja);
}

void Tipka::SetPozicija(sf::Vector2f pozicija)
{
	this->tipka.setPosition(pozicija);

	float xPos = (pozicija.x + this->tipka.getLocalBounds().width / 2.5) - (this->text.getLocalBounds().width / 2);
	float yPos = (pozicija.y + this->tipka.getLocalBounds().height / 4) - (this->text.getLocalBounds().height / 2);
	this->text.setPosition({xPos, yPos});
}

void Tipka::DrawTo(sf::RenderWindow& window)
{
	window.draw(this->tipka);
	window.draw(this->text);
}

bool Tipka::Hover(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float tipkaPosX = this->tipka.getPosition().x;
	float tipkaPosY = this->tipka.getPosition().y;

	float tipkaXPosSirina = this->tipka.getPosition().x + this->tipka.getLocalBounds().width;
	float tipkaYPosVisina = this->tipka.getPosition().y + this->tipka.getLocalBounds().height;

	if (mouseX < tipkaXPosSirina && mouseX > tipkaPosX && mouseY < tipkaYPosVisina && mouseY > tipkaPosY)
	{
		return true;
	}
	return false;
}