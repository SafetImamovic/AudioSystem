#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

//definira ascii vrijednost specijalnih tipki
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

/*
	Klasa odgovorna za textbox, znaci mjesto gdje korisnik moze da kuca tekst
*/

class TextBox
{
private:
	sf::Text textbox;
	sf::RectangleShape backgroundShape;
	std::ostringstream text;
	bool jeOznacen = false;
	bool imaLimit = false;
	int Limit;

	void InputLogika(int karakterIstipkan);
	void IzbrisiZadnjiKarakter();


public:
	TextBox() = default;

	void SetTextBox(int velicina, sf::Color boja, bool oznacen);
	void SetFont(sf::Font& font);
	void SetPosition(sf::Vector2f pozicija);
	void SetLimit(bool ImaIliNema);
	void SetLimit(bool ImaIliNema, int Limit);
	void SetOznacen(bool oznacen);
	void SetBackground(sf::Color boja, sf::Vector2f velicina);
	void SetPozadinaPozicija(sf::Vector2f pozicija);
	void SetSve(int velicinaTeksta, sf::Color bojaTeksta, sf::Color bojaPozadine, bool oznacen, sf::Font& font, sf::Vector2f pozicija, sf::Vector2f padding, sf::Vector2f velicinaPozadine);
	std::string GetText();

	void DrawTo(sf::RenderWindow& window);
	void OtipkanoNa(sf::Event input);
};
