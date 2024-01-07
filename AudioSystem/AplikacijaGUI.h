#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ShlObj.h>
#include "SkuPjesama.h"
#include "muzikaTest.h"
#include "TextBox.h"
#include "Tipka.h"
#include "Kontrole.h"
#include "InfoPjesma.h"
#include "Pjesma.h"
#include "PlayList.h"
#include <string>
#include <vector>
#include <memory>


/*
	Klasa koja je odgovorna za GUI
*/

class AplikacijaGUI
{
private:
	sf::RenderWindow* window; //sf::RenderWindow definise prozor za GUI
	sf::Event event; //event je objekat koji moze da poprimi vrijednost ili vrstu eventa koji se je desio unutar prozora,
    //cak i van prozora ako je tako definisano
	sf::VideoMode videoMode; //zadaje rezoluciju prozoru
	sf::Vector2i mousePozProzor; //cuva poziciju misa relativnu prozoru (koordinate)
	sf::Font font, fontEmoji;
	Tipka PromijeniRezolucijuToggleTEST;
	sf::Color PrimarnaBoja, SekundarnaBoja, AkcenatBoja;
	float TempGlasnoca;
	Kontrole kontrole;
	AudioPlayer player;
	InfoPjesma infoPjesma;
	PlayLista* pSvePjesme;
	std::vector<std::string> NizPjesmi;
	std::vector<InfoPjesma::InfoPjesmaRender> IPRMain;
	void MoveUp();
	void MoveDown();
	//elementi aplikacije
	//tok definiranja, logike i iscrtavanja elemenata na prozor je sljedeci:
	//1. deklaracija elementa ovdje
	//2. inicijalizacija elementa koja ce se na kraju pozvat u konstruktoru (u ovom slucaju se karakteristike elementa definiraju unutar private
	// metode InicijalizacijaElemenata() pa se ona poziva unutar konstruktora)
	//3. osvjezavanje elemenata ili "update" logike elemenata npr. u zavisnoti od events kao klikanje na element itd.
	//na kraju se uvijek poziva u funkciji UpdateGUI(); moze se prije definirati logika unutar neke druge metode pa onda ona pozvati u UpdateGUI()
	//4. iscrtavanje ili render na ekran koja se na kraju poziva u RenderGUI(); moze imati svoju metodu kao i prije
	//Bitno je znati da render ima svoj redoslijed npr. ako je neki element koji je zadnji pozvan, on ce se iscrtati na vrhu svih koji 
	// su bili pozvani prije njega 
	//unutar metode posebne za element je potrebno pozvat this->window->draw(this->(element))

	sf::RectangleShape rect; //pravougaonik

	void InicijalizacijaVarijabli();
	void InicijalizacijaProzora();
	void InicijalizacijaElemenata();
	void ProvjeriHoverZaSveElemente();
	void ProvjeriClickZaSveElemente();
	void RenderSveElemente();
	void ResetPrimarneBoje();
	void GetOdgovarajuciTextBoxText();
	void UpdateScrollBar();
	void UpdateGlasnocaBar();
	void PromijeniRezoluciju(int height, int width);
	void Mute();
	void InfoPjesmaKonfiguracija();
	void UpdateInfoPjesma();
	void UpdateStanjeTipke();
	void UpdateOtipkano();
	void LCtrlObrisi();
	void Scroll();
	void PostaviNizPjesmi();
	void UpdateImePjesme();
	void ResizeWindowEvent();
	void PromjenaRezolucijaStaticInfoPjesma();
	void CreateShorcut();


public:
	AplikacijaGUI(sf::Font& font, sf::Font& fontEmoji, sf::Color PrimarnaBoja, sf::Color SekundarnaBoja, sf::Color AkcenatBoja);
	~AplikacijaGUI();

	void UpdateRect();
	void UpdatePozicijaMisa();
	void UpdatePollEvents();
	void UpdateGUI();

	void RenderRect();
	void RenderGUI();

	const bool getWindowIsOpen() const;
};