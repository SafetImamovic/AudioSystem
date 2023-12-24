#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "ElementarneKomponente.h"

class Tipka : public ElementarneKomponente
{
private:

	sf::Text text;
public:
	sf::RectangleShape tipka;
	Tipka() = default;
	void SetTipka(std::string ID, std::wstring text, sf::Vector2f velicina, int karakterVelicina, sf::Color bojaText, sf::Color bojaPozadine, sf::Font& font, sf::Vector2f pozicija, sf::Vector2f textPozicija);
	void PromijeniBojuPozadine(sf::Color boja);
	void PromijeniBojuTexta(sf::Color boja);
	void SetPozicija(sf::Vector2f pozicija);
	void DrawTo(sf::RenderWindow& window);
	void SetTextUTF16(std::wstring text);
	void SetTextPozicija(sf::Vector2f pozicija);
	std::wstring GetTextUTF16();
	sf::Text& GetText();
	void PromijeniKarakter(std::wstring promjena);

};
