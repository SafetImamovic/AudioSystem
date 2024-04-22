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
	this->text.setOutlineColor(sf::Color::White);
	this->text.setOutlineThickness(0.3);
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

std::wstring Tipka::GetTextUTF16()
{
	return this->text.getString();
}

sf::Text& Tipka::GetText()
{
	return this->text;
}

void Tipka::PromijeniKarakter(std::wstring promjena)
{
	this->text.setString(promjena);

	//std::cout << (std::string)this->text.getString();
}

sf::RectangleShape& Tipka::getPozadina()
{
	return this->tipka;
}

sf::Text Tipka::getTextElement()
{
	return this->text;
}

