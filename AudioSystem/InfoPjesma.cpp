﻿#include "InfoPjesma.h"

int InfoPjesma::sirinaWindow = 1920;
int InfoPjesma::visinaWindow = 1000;
sf::RectangleShape InfoPjesma::pozadinaLista;
sf::RectangleShape InfoPjesma::pozadinaPjesma;
sf::Vector2f InfoPjesma::pozicijaLista;
sf::Vector2f InfoPjesma::pozicijaPjesma;
sf::Vector2f InfoPjesma::dimenzijeLista;
sf::Vector2f InfoPjesma::dimenzijaPjesma;
sf::Color InfoPjesma::PrimarnaBoja;
std::string InfoPjesma::NaslovPjesme;
sf::Text InfoPjesma::textNaslov;
std::string InfoPjesma::PjesniciPjesme;
sf::Text InfoPjesma::textPjesnici;
std::string InfoPjesma::NaslovListe;
sf::Text InfoPjesma::textNaslovListe;
std::string InfoPjesma::KreatorListe;
sf::Text InfoPjesma::textKreatroListe;
sf::Font InfoPjesma::font;
sf::Font InfoPjesma::fontEmoji;
int InfoPjesma::PaddingVertical;
int InfoPjesma::PaddingHorizontal;
int InfoPjesma::PaddingVerticalPlayLista;
int InfoPjesma::PaddingHorizontalPlayLista;
sf::RectangleShape InfoPjesma::CoverUpMain;
sf::RectangleShape InfoPjesma::CoverUpMainTwo;
sf::RectangleShape InfoPjesma::CoverUpSecondary;
sf::RectangleShape InfoPjesma::CoverUpListaUp;
sf::RectangleShape InfoPjesma::CoverUpListaDown;
sf::Texture InfoPjesma::Cover;
sf::Sprite InfoPjesma::CoverRender;
float InfoPjesma::rateNaslov = -0.25;
float InfoPjesma::ratePjesnici = -0.25;
std::wstring InfoPjesma::VrstaListe;
sf::Text InfoPjesma::textVrstaListe;
sf::Text InfoPjesma::textSimbolVrsta;
std::vector<Tipka> InfoPjesma::Tipke;
std::vector<TextBox> InfoPjesma::TextBoxovi;
std::vector<sf::RectangleShape> InfoPjesma::PozadinePjesma;
sf::RectangleShape InfoPjesma::PozadinaAlbum;
sf::RectangleShape InfoPjesma::PozadinaPlaylist;
std::vector<sf::RectangleShape> InfoPjesma::PozadineListi;
sf::RectangleShape InfoPjesma::CoverUpDesno;
sf::Text InfoPjesma::PlayListNaslov;


void InfoPjesma::SetPjesma(std::string naslov, std::string pjesnici, sf::Font &font, sf::Font &fontEmoji)
{
	InfoPjesma::PaddingVertical = 20;
	InfoPjesma::PaddingHorizontal = 20;
	InfoPjesma::NaslovPjesme = naslov;
	InfoPjesma::PjesniciPjesme = pjesnici;
	InfoPjesma::font = font;
	InfoPjesma::fontEmoji = fontEmoji;

	InfoPjesma::dimenzijaPjesma = sf::Vector2f(500, 1000);
	InfoPjesma::pozicijaPjesma = sf::Vector2f(0, 0);
	InfoPjesma::PrimarnaBoja = sf::Color(sf::Color::Black);

	InfoPjesma::CoverUpMain.setSize(sf::Vector2f(InfoPjesma::PaddingHorizontal, 1000));
	InfoPjesma::CoverUpMain.setFillColor(sf::Color::Black);
	InfoPjesma::CoverUpMain.setPosition(sf::Vector2f(500 - InfoPjesma::PaddingHorizontal, 0));

	InfoPjesma::CoverUpMainTwo.setSize(sf::Vector2f(InfoPjesma::PaddingHorizontal, 1000));
	InfoPjesma::CoverUpMainTwo.setFillColor(sf::Color(sf::Color::Black));
	InfoPjesma::CoverUpMainTwo.setPosition(sf::Vector2f(0, 0));

	InfoPjesma::CoverUpSecondary.setSize(sf::Vector2f(4000, 900));
	InfoPjesma::CoverUpSecondary.setFillColor(sf::Color::Black);
	InfoPjesma::CoverUpSecondary.setPosition(sf::Vector2f(500, 0));

	InfoPjesma::textNaslov.setFont(InfoPjesma::font);
	InfoPjesma::textNaslov.setString(InfoPjesma::NaslovPjesme);
	//std::cout << InfoPjesma::textNaslov.getGlobalBounds().width;

	InfoPjesma::textPjesnici.setFont(InfoPjesma::font);
	InfoPjesma::textPjesnici.setString(InfoPjesma::PjesniciPjesme);

	InfoPjesma::textNaslov.setPosition(
		InfoPjesma::pozicijaPjesma.x + InfoPjesma::PaddingHorizontal + 2,
		InfoPjesma::pozicijaPjesma.y + InfoPjesma::PaddingVertical + 500
		);

	InfoPjesma::textPjesnici.setFillColor(sf::Color::White);

	InfoPjesma::textPjesnici.setPosition(
		InfoPjesma::pozicijaPjesma.x + InfoPjesma::PaddingHorizontal,
		InfoPjesma::pozicijaPjesma.y + InfoPjesma::PaddingVertical + 500 + InfoPjesma::textNaslov.getGlobalBounds().height + 20
	);

	InfoPjesma::textNaslov.setCharacterSize(36);
	InfoPjesma::textNaslov.setOutlineThickness(1);
	InfoPjesma::textNaslov.setOutlineColor(sf::Color::White);
	InfoPjesma::textPjesnici.setCharacterSize(28);

	InfoPjesma::textNaslov.setFillColor(sf::Color::White);

	InfoPjesma::pozadinaPjesma.setSize(InfoPjesma::dimenzijaPjesma);
	InfoPjesma::pozadinaPjesma.setPosition(InfoPjesma::pozicijaPjesma);
	InfoPjesma::pozadinaPjesma.setFillColor(InfoPjesma::PrimarnaBoja);

}

void InfoPjesma::RenderPjesma(sf::RenderWindow &window)
{
	window.draw(InfoPjesma::pozadinaPjesma);
	window.draw(InfoPjesma::textNaslov);
	window.draw(InfoPjesma::textPjesnici);
	window.draw(InfoPjesma::CoverUpMain);
	window.draw(InfoPjesma::CoverUpMainTwo);
	window.draw(InfoPjesma::CoverUpSecondary);
	window.draw(InfoPjesma::CoverRender);
	
}

void InfoPjesma::SetList(std::string naslov, std::string kreator, std::vector<std::string>& PjesmeZaSad, bool VrstaListeBool, sf::RenderWindow& window)
{
	InfoPjesma::PaddingVerticalPlayLista = 20;
	InfoPjesma::PaddingHorizontalPlayLista = 20;

	InfoPjesma::dimenzijeLista = sf::Vector2f(1920 - 500 - 300, 1000 - 60 - 50);
	InfoPjesma::pozicijaLista = sf::Vector2f(500, 0);

	InfoPjesma::pozadinaLista.setSize(InfoPjesma::dimenzijeLista);
	InfoPjesma::pozadinaLista.setPosition(InfoPjesma::pozicijaLista);
	InfoPjesma::pozadinaLista.setFillColor(sf::Color(10, 10, 10));

	InfoPjesma::NaslovListe = naslov;
	InfoPjesma::KreatorListe = kreator;

	InfoPjesma::textNaslovListe.setFont(InfoPjesma::font);
	InfoPjesma::textKreatroListe.setFont(InfoPjesma::font);
	InfoPjesma::textVrstaListe.setFont(InfoPjesma::font);
	InfoPjesma::textSimbolVrsta.setFont(InfoPjesma::fontEmoji);

	InfoPjesma::textNaslovListe.setString(naslov);
	InfoPjesma::textKreatroListe.setString(kreator);
	if (VrstaListeBool == true)//true je album, false je playlista
	{
		InfoPjesma::textVrstaListe.setString("Album");
		InfoPjesma::textSimbolVrsta.setString(L"\uE958");
	}
	else
	{
		InfoPjesma::textVrstaListe.setString("PlayLista");
		InfoPjesma::textSimbolVrsta.setString(L"\uE90B");//
	}

	InfoPjesma::textNaslovListe.setFillColor(sf::Color::White);
	InfoPjesma::textKreatroListe.setFillColor(sf::Color::White);
	InfoPjesma::textVrstaListe.setFillColor(sf::Color::White);
	InfoPjesma::textSimbolVrsta.setFillColor(sf::Color::White);

	InfoPjesma::textNaslovListe.setCharacterSize(36);
	InfoPjesma::textNaslovListe.setOutlineThickness(1);
	InfoPjesma::textNaslovListe.setOutlineColor(sf::Color::White);
	InfoPjesma::textKreatroListe.setCharacterSize(28);
	InfoPjesma::textVrstaListe.setCharacterSize(16);
	InfoPjesma::textSimbolVrsta.setCharacterSize(20);

	InfoPjesma::textNaslovListe.setPosition(sf::Vector2f(500 + InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista));
	InfoPjesma::textKreatroListe.setPosition(sf::Vector2f(500 + InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista + InfoPjesma::textNaslovListe.getGlobalBounds().height + 20));
	InfoPjesma::textVrstaListe.setPosition(sf::Vector2f(500 + 1920 - 500 - 300 - InfoPjesma::textVrstaListe.getGlobalBounds().width - InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista));
	InfoPjesma::textSimbolVrsta.setPosition(sf::Vector2f(500 + 1920 - 500 - 300 + 14 - InfoPjesma::textVrstaListe.getGlobalBounds().width - InfoPjesma::PaddingHorizontalPlayLista - InfoPjesma::textVrstaListe.getGlobalBounds().width, InfoPjesma::PaddingVerticalPlayLista));

	Tipka Play, Shuffle, Pretraga;

	Play.SetTipka(
		"ListaPlay",
		L"\uE768",
		{ 60, 60 },
		24,
		sf::Color::White,
		sf::Color(10, 10, 10),
		InfoPjesma::fontEmoji,
		{ 520, 140 },
		{ 18, 18 }
	);

	Shuffle.SetTipka(
		"ListaPlay",
		L"\uE8B1",
		{ 60, 60 },
		24,
		sf::Color::White,
		sf::Color(10, 10, 10),
		InfoPjesma::fontEmoji,
		{ 580, 140 },
		{ 18, 18 }
	);

	Pretraga.SetTipka(
		"ListaPretraga",
		L"\uE094",
		{ 60, 60 },
		24,
		sf::Color::White,
		sf::Color(10, 10, 10),
		InfoPjesma::fontEmoji,
		{ 1920 - 300 - 20 - 60, 140 },
		{ 18, 18 }
	);

	InfoPjesma::Tipke.push_back(Play);
	InfoPjesma::Tipke.push_back(Shuffle);
	InfoPjesma::Tipke.push_back(Pretraga);

	InfoPjesma::SetTextBox();

	InfoPjesma::PozadinePjesma = InfoPjesma::RenderSvePjesme(PjesmeZaSad, window);
	InfoPjesma::PostaviCoverUpLista();
}

void InfoPjesma::RenderList(sf::RenderWindow& window)
{
	window.draw(InfoPjesma::pozadinaLista);
	for (const sf::RectangleShape pozadina : InfoPjesma::PozadinePjesma)
	{
		window.draw(pozadina);
	}
	window.draw(InfoPjesma::CoverUpListaUp);
	window.draw(InfoPjesma::textNaslovListe);
	window.draw(InfoPjesma::textKreatroListe);
	window.draw(InfoPjesma::textVrstaListe);
	window.draw(InfoPjesma::textSimbolVrsta);
}

void InfoPjesma::SetTextBox()
{
	TextBox MainPretragaListe;
	MainPretragaListe.SetSve(
		"SearchMain",
		24,
		sf::Color::White,
		sf::Color(30, 30, 30),
		false,
		InfoPjesma::font,
		{ 640, 140 },
		{16,16},
		{1920 - 500 - 20 - 20 - 300 - 120 - 60, 60}
	);


	InfoPjesma::TextBoxovi.push_back(MainPretragaListe);
}

std::vector<sf::RectangleShape> InfoPjesma::RenderSvePjesme(std::vector<std::string>& PjesmeZaSad, sf::RenderWindow &window)//za sad vektor samo stringova
{
	std::vector<sf::RectangleShape> Pozadine;
	int x = 520;
	int y = 240;

	for (const std::string& text : PjesmeZaSad)
	{
		sf::RectangleShape pozadinaPjesma;
		sf::Text imePjesme;

		imePjesme.setFont(InfoPjesma::font);

		pozadinaPjesma.setFillColor(sf::Color(45,45,45));
		imePjesme.setFillColor(sf::Color::White);

		pozadinaPjesma.setSize(sf::Vector2f(1920 - 520 - 300 - 20, 50));

		pozadinaPjesma.setPosition(sf::Vector2f(x, y));
		imePjesme.setPosition(sf::Vector2f(x, y));


		y += 50 + 10;
		Pozadine.push_back(pozadinaPjesma);
	}
	return Pozadine;
}


void InfoPjesma::Update()
{

	if (InfoPjesma::textNaslov.getGlobalBounds().width > 500 - InfoPjesma::PaddingHorizontal * 2)
	{
		
		InfoPjesma::textNaslov.move(sf::Vector2f(InfoPjesma::rateNaslov, 0));
		//std::cout << InfoPjesma::textNaslov.getPosition().x << "\n";
		if (InfoPjesma::textNaslov.getPosition().x == InfoPjesma::PaddingHorizontal + 1)
		{
			InfoPjesma::rateNaslov = -0.001;
		}
		else if (InfoPjesma::textNaslov.getPosition().x < InfoPjesma::PaddingHorizontal)
		{
			InfoPjesma::rateNaslov = -0.25;
		}
		if (InfoPjesma::textNaslov.getPosition().x <= -(InfoPjesma::textNaslov.getGlobalBounds().width + 10))
		{
			InfoPjesma::textNaslov.setPosition(sf::Vector2f(500 - InfoPjesma::PaddingHorizontal, 500 + InfoPjesma::PaddingVertical));
		}

	}

	if (InfoPjesma::textPjesnici.getGlobalBounds().width > 500 - InfoPjesma::PaddingHorizontal * 2)
	{
		InfoPjesma::textPjesnici.move(sf::Vector2f(InfoPjesma::ratePjesnici, 0));
		//std::cout << InfoPjesma::textPjesnici.getPosition().x << "\n";
		if (InfoPjesma::textPjesnici.getPosition().x == InfoPjesma::PaddingHorizontal + 1)
		{
			InfoPjesma::ratePjesnici = -0.001;
		}
		else if (InfoPjesma::textPjesnici.getPosition().x < InfoPjesma::PaddingHorizontal)
		{
			InfoPjesma::ratePjesnici = -0.25;
		}
		if (InfoPjesma::textPjesnici.getPosition().x <= -(InfoPjesma::textPjesnici.getGlobalBounds().width + 10))
		{
			InfoPjesma::textPjesnici.setPosition(sf::Vector2f(500 - InfoPjesma::PaddingHorizontal, 500 + InfoPjesma::PaddingVertical + InfoPjesma::textNaslov.getGlobalBounds().height + 20));
		}
	}
}

void InfoPjesma::PostaviCoverUpLista()
{
	InfoPjesma::CoverUpListaUp.setFillColor(sf::Color(10, 10, 10));
	InfoPjesma::CoverUpListaDown.setFillColor(sf::Color(10, 10, 10));

	InfoPjesma::CoverUpListaUp.setSize(sf::Vector2f(InfoPjesma::sirinaWindow - 500 - 300, 220));
	InfoPjesma::CoverUpListaUp.setPosition(sf::Vector2f(500, 0));
}

void InfoPjesma::SetListeDesno(std::vector<std::string> ListeZaSad, sf::RenderWindow& window)
{
	InfoPjesma::PozadineListi = InfoPjesma::RenderSveListe(ListeZaSad, window);
}

void InfoPjesma::MoveUp(std::string id)
{
	if (InfoPjesma::PozadinePjesma.size() == 0)
		return;
	
	if (id == "Pjesme")
	{
		if (InfoPjesma::PozadinePjesma.at(InfoPjesma::PozadinePjesma.size() - 1).getPosition().y > 1000 - 200)
		{
			for (sf::RectangleShape& shape : InfoPjesma::PozadinePjesma)
			{
				shape.move({ 0, -20 });
			}
		}
	}

	if (id == "Playliste")
	{
		if (InfoPjesma::PozadineListi.at(InfoPjesma::PozadineListi.size() - 1).getPosition().y > 1000 - 200)
		{
			for (sf::RectangleShape& shape : InfoPjesma::PozadineListi)
			{
				shape.move({ 0, -20 });
			}
		}
	}
}

void InfoPjesma::RenderListDesno(sf::RenderWindow& window)
{
	InfoPjesma::CoverUpDesno.setFillColor(sf::Color::Black);
	InfoPjesma::CoverUpDesno.setSize(sf::Vector2f(300, 220));
	InfoPjesma::CoverUpDesno.setPosition(sf::Vector2f(1920 - 300, 0));

	
	InfoPjesma::PlayListNaslov.setFont(InfoPjesma::font);
	InfoPjesma::PlayListNaslov.setFillColor(sf::Color::White);
	InfoPjesma::PlayListNaslov.setCharacterSize(36);
	InfoPjesma::PlayListNaslov.setOutlineThickness(1);
	InfoPjesma::PlayListNaslov.setOutlineColor(sf::Color::White);
	InfoPjesma::PlayListNaslov.setPosition(1920 - 300 + 20, 0 + 20);
	InfoPjesma::PlayListNaslov.setString("Playliste i \nAlbumi");


	for (const sf::RectangleShape pozadina : InfoPjesma::PozadineListi)
	{
		window.draw(pozadina);
	}
	window.draw(InfoPjesma::CoverUpDesno);
	window.draw(InfoPjesma::PlayListNaslov);

}

void InfoPjesma::MoveDown(std::string id)
{
	if (InfoPjesma::PozadinePjesma.size() == 0)
		return;

	if (id == "Pjesme")
	{
		if (InfoPjesma::PozadinePjesma.at(0).getPosition().y < 240)
		{
			for (sf::RectangleShape& shape : InfoPjesma::PozadinePjesma)
			{
				shape.move({ 0, 20 });
			}
		}
	}

	if (id == "Playliste")
	{
		if (InfoPjesma::PozadineListi.at(0).getPosition().y < 240)
		{
			for (sf::RectangleShape& shape : InfoPjesma::PozadineListi)
			{
				shape.move({ 0, 20 });
			}
		}
	}
}

std::vector<sf::RectangleShape> InfoPjesma::RenderSveListe(std::vector<std::string>& ListeZaSasd, sf::RenderWindow& window)
{
	std::vector<sf::RectangleShape> Pozadine;
	int x = 1920 - 300 + 20;
	int y = 240;

	for (const std::string& text : ListeZaSasd)
	{
		sf::RectangleShape pozadinaLista;
		sf::Text imeLista;

		imeLista.setFont(InfoPjesma::font);

		pozadinaLista.setFillColor(sf::Color(45, 45, 45));
		imeLista.setFillColor(sf::Color::White);

		pozadinaLista.setSize(sf::Vector2f(300 - 40, 50));

		pozadinaLista.setPosition(sf::Vector2f(x, y));
		imeLista.setPosition(sf::Vector2f(x, y));


		y += 50 + 10;
		Pozadine.push_back(pozadinaLista);
	}
	return Pozadine;
}

void InfoPjesma::PostaviPozadineDesno()
{
	InfoPjesma::PozadinaPlaylist.setFillColor(sf::Color::Black);
	InfoPjesma::PozadinaPlaylist.setSize(sf::Vector2f(300, InfoPjesma::visinaWindow - 55));
	InfoPjesma::PozadinaPlaylist.setPosition(sf::Vector2f(InfoPjesma::sirinaWindow - 300, 0));
}

void InfoPjesma::RenderDesno(sf::RenderWindow &window)
{
	window.draw(InfoPjesma::PozadinaPlaylist);
	window.draw(InfoPjesma::PozadinaAlbum);
}