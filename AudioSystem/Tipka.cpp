#include "Tipka.h"

void Tipka::SetTipka(std::string ID, std::wstring text, sf::Vector2f velicina, int karakterVelicina, sf::Color bojaText, sf::Color bojaPozadine, sf::Font& font, sf::Vector2f pozicija, sf::Vector2f textPozicija)
{
	this->SetID(ID);
	this->text.setString(text);
	this->text.setFillColor(bojaText);
	this->text.setCharacterSize(karakterVelicina);
	this->text.setFont(font);
	this->SetPozicija(pozicija);
	this->tipka.setSize(velicina);
	this->tipka.setFillColor(bojaPozadine);
	this->SetTextPozicija(textPozicija);
	
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
//
{
	this->tipka.setPosition(pozicija);
	this->text.setPosition(pozicija);
}

void Tipka::DrawTo(sf::RenderWindow& window)
//iscrtava na prozor
{
	window.draw(this->tipka);
	window.draw(this->text);
}

void Tipka::SetTextUTF16(std::wstring text)
//metoda koja postavlja wstring unutar texta sto omogucava printanje UTF-16 karaktera
{
	this->text.setString(text);
}

void Tipka::SetTextPozicija(sf::Vector2f pozicija)
{
	this->text.move(pozicija);
}

