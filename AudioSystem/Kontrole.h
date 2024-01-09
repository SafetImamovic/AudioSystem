#pragma once

#include <vector>
#include "ElementarneKomponente.h"
#include "TextBox.h"
#include "Tipka.h"
#include "GlobalneFunkcije.h"

class Kontrole : public ElementarneKomponente
{
private:
	int visinaTipke = 60, sirinaTipke = 60, sirinaScroll, visinaScroll = 50, visinaGlasnoca = 60, sirinaGlasnoca = 200;
	sf::VideoMode videoMode;
	sf::Font font, fontEmoji;
	sf::Color PrimarnaBoja, SekundarnaBoja, AkcenatBoja;
	sf::RectangleShape ScrollPozadina, GlasnocaPozadina, GlasnocaProcenatPozadina;
	sf::Text ScrollSimbol, GlasnocaSimbol, GlasnocaProcenat;
	sf::RectangleShape ScrollBar, GlasnocaBar, ScrollBarFollow, GlasnocaBarFollow, GlobalnaPozadina;
	int pocetnaKoordinataXTipke;
	sf::RectangleShape pozadinaVrijeme;
	sf::Text textVrijeme;

	
public:

	std::vector<Tipka> Tipke;		//vektor koja cuva sve tipke
	void SetKontrole(sf::VideoMode &videoMode, sf::Font &font, sf::Font& fontEmoji, sf::Color PirmarnaBoja, sf::Color SekundrnaBoja, sf::Color AkcenatBoja);

	
	void InicijalizacijaScroll();
	void InicijalizacijaGlasnoca();
	void InicijalizacijaTipki(bool DaLiJeLajkana);
	float UpdatePozicijaSimbolaWindow(sf::RenderWindow& window);
	float UpdatePozicijaSimbolaWindowGlasnoca(sf::RenderWindow& window);
	void UpdatePozicijaSimbola(float index);
	void UpdatePozicijaSimbolaGlasnoca(float index, sf::RenderWindow& window);
	void RenderVrijeme(sf::RenderWindow& window, float sekunde, float trajanje, sf::Color PrimarnaBoja);
	void PromijeniKarakter(std::string text, std::wstring promjena);
	void RenderPozadina(sf::RenderWindow &window);
	void SetRezolucija(sf::VideoMode &videoMode);
	void SetRezolucijaKontrole();
	void SetRezolucijaScrollBar();
	void SetRezolucijaVrijeme(sf::RenderWindow& window);
	void SetRezolucijaGlasnoca();
	void PromijeniLikeTipku(bool da);

	void RenderScroll(sf::RenderWindow &window);
	void RenderGlasnoca(sf::RenderWindow& window);
};
