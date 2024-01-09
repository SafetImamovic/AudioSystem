#include "InfoPjesma.h"

int InfoPjesma::sirinaWindow;
int InfoPjesma::visinaWindow;
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
std::string InfoPjesma::DatumObjave;
sf::Text InfoPjesma::textDatumObjave;
std::string InfoPjesma::RecordLabel;
sf::Text InfoPjesma::textRecordLabel;
std::wstring InfoPjesma::NaslovListe;
sf::Text InfoPjesma::textNaslovListe;
std::wstring InfoPjesma::KreatorListe;
sf::Text InfoPjesma::textKreatroListe;
sf::Font InfoPjesma::font, InfoPjesma::fontBold, InfoPjesma::fontBoldest;
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
sf::Vector2f InfoPjesma::VelicinaLijevo = sf::Vector2f(400, InfoPjesma::visinaWindow);
int InfoPjesma::BaznaRezolucijaSlike = 400;
int InfoPjesma::NaslovFontSize = 32;
int InfoPjesma::NaslovFontSize2 = 20;
int InfoPjesma::NaslovFontSize3 = 16;
int InfoPjesma::InfoPjesmaRender::BrojPjesama = 0;

void InfoPjesma::SetPjesma(std::string naslov, std::string pjesnici, sf::Font& font, sf::Font& fontBold, sf::Font& fontBoldest, sf::Font &fontEmoji)
{

	float Proporcija = InfoPjesma::VelicinaLijevo.x / InfoPjesma::BaznaRezolucijaSlike;
	InfoPjesma::CoverRender.setScale(Proporcija, Proporcija);

	InfoPjesma::PaddingVertical = 15;
	InfoPjesma::PaddingHorizontal = 15;
	InfoPjesma::NaslovPjesme = naslov;
	InfoPjesma::PjesniciPjesme = pjesnici;
	InfoPjesma::font = font;
	InfoPjesma::fontBold = fontBold;
	InfoPjesma::fontBoldest = fontBoldest;
	InfoPjesma::fontEmoji = fontEmoji;

	InfoPjesma::dimenzijaPjesma = sf::Vector2f(InfoPjesma::VelicinaLijevo.x, InfoPjesma::visinaWindow);
	InfoPjesma::pozicijaPjesma = sf::Vector2f(0, 0);
	InfoPjesma::PrimarnaBoja = sf::Color(sf::Color::Black);

	InfoPjesma::CoverUpMain.setSize(sf::Vector2f(InfoPjesma::PaddingHorizontal, InfoPjesma::visinaWindow));
	InfoPjesma::CoverUpMain.setFillColor(sf::Color::Black);
	InfoPjesma::CoverUpMain.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x - InfoPjesma::PaddingHorizontal, 0));

	InfoPjesma::CoverUpMainTwo.setSize(sf::Vector2f(InfoPjesma::PaddingHorizontal, InfoPjesma::visinaWindow));
	InfoPjesma::CoverUpMainTwo.setFillColor(sf::Color(sf::Color::Black));
	InfoPjesma::CoverUpMainTwo.setPosition(sf::Vector2f(0, 0));

	InfoPjesma::CoverUpSecondary.setSize(sf::Vector2f(4000, 4000));
	InfoPjesma::CoverUpSecondary.setFillColor(sf::Color::Black);
	InfoPjesma::CoverUpSecondary.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x, 0));

	InfoPjesma::textNaslov.setFont(InfoPjesma::fontBoldest);
	InfoPjesma::textNaslov.setString(InfoPjesma::NaslovPjesme);

	InfoPjesma::textPjesnici.setFont(InfoPjesma::fontBold);
	InfoPjesma::textPjesnici.setString(InfoPjesma::PjesniciPjesme);
	InfoPjesma::textPjesnici.setFillColor(sf::Color::White);

	InfoPjesma::textPjesnici.setPosition(
		InfoPjesma::pozicijaPjesma.x + InfoPjesma::PaddingHorizontal,
		InfoPjesma::pozicijaPjesma.y + InfoPjesma::PaddingVertical + InfoPjesma::VelicinaLijevo.x + 26 + 20
	);

	InfoPjesma::textNaslov.setCharacterSize(InfoPjesma::NaslovFontSize);
	//InfoPjesma::textNaslov.setOutlineThickness(0.2);
	//InfoPjesma::textNaslov.setOutlineColor(sf::Color::White);

	

	InfoPjesma::textPjesnici.setCharacterSize(InfoPjesma::NaslovFontSize2);

	InfoPjesma::textNaslov.setFillColor(sf::Color::White);

	InfoPjesma::pozadinaPjesma.setSize(InfoPjesma::dimenzijaPjesma);
	InfoPjesma::pozadinaPjesma.setPosition(InfoPjesma::pozicijaPjesma);
	InfoPjesma::pozadinaPjesma.setFillColor(InfoPjesma::PrimarnaBoja);

	InfoPjesma::textDatumObjave.setFont(InfoPjesma::font);
	InfoPjesma::textDatumObjave.setFillColor(sf::Color(255, 255, 255, 128));
	InfoPjesma::textDatumObjave.setCharacterSize(InfoPjesma::NaslovFontSize3);

	InfoPjesma::textDatumObjave.setString("Nice");
	InfoPjesma::textRecordLabel.setString("Nice");

	InfoPjesma::textRecordLabel.setFont(InfoPjesma::font);
	InfoPjesma::textRecordLabel.setFillColor(sf::Color(255, 255, 255, 128));
	InfoPjesma::textRecordLabel.setCharacterSize(InfoPjesma::NaslovFontSize3);

	InfoPjesma::textDatumObjave.setPosition(sf::Vector2f(InfoPjesma::PaddingHorizontal, InfoPjesma::VelicinaLijevo.x + 100));
	InfoPjesma::textRecordLabel.setPosition(sf::Vector2f(InfoPjesma::PaddingHorizontal, InfoPjesma::VelicinaLijevo.x + 120));
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

	window.draw(InfoPjesma::textDatumObjave);
	window.draw(InfoPjesma::textRecordLabel);
	
}

void InfoPjesma::SetList(std::wstring naslov, std::wstring kreator, std::vector<Pjesma>& Pjesme, bool VrstaListeBool, sf::RenderWindow& window)
{
	InfoPjesma::PaddingVerticalPlayLista = 15;
	InfoPjesma::PaddingHorizontalPlayLista = 15;
  
	InfoPjesma::dimenzijeLista = sf::Vector2f(InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300, InfoPjesma::visinaWindow - 60 - 50);
	InfoPjesma::pozicijaLista = sf::Vector2f(InfoPjesma::VelicinaLijevo.x, 0);

	InfoPjesma::pozadinaLista.setSize(InfoPjesma::dimenzijeLista);
	InfoPjesma::pozadinaLista.setPosition(InfoPjesma::pozicijaLista);
	InfoPjesma::pozadinaLista.setFillColor(sf::Color(10, 10, 10));

	InfoPjesma::NaslovListe = naslov;
	InfoPjesma::KreatorListe = kreator;

	InfoPjesma::textNaslovListe.setFont(InfoPjesma::fontBoldest);
	InfoPjesma::textKreatroListe.setFont(InfoPjesma::fontBold);
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
		InfoPjesma::textVrstaListe.setString("Playlista");
		InfoPjesma::textSimbolVrsta.setString(L"\uE90B");//
	}

	InfoPjesma::textNaslovListe.setFillColor(sf::Color::White);
	InfoPjesma::textKreatroListe.setFillColor(sf::Color::White);
	InfoPjesma::textVrstaListe.setFillColor(sf::Color::White);
	InfoPjesma::textSimbolVrsta.setFillColor(sf::Color::White);

	InfoPjesma::textNaslovListe.setCharacterSize(InfoPjesma::NaslovFontSize);
	InfoPjesma::textKreatroListe.setCharacterSize(InfoPjesma::NaslovFontSize2);
	InfoPjesma::textVrstaListe.setCharacterSize(InfoPjesma::NaslovFontSize3);
	InfoPjesma::textSimbolVrsta.setCharacterSize(InfoPjesma::NaslovFontSize2);

	InfoPjesma::textNaslovListe.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista));



	InfoPjesma::textKreatroListe.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista + InfoPjesma::textNaslovListe.getGlobalBounds().height + - 10));
	InfoPjesma::textVrstaListe.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300 - InfoPjesma::textVrstaListe.getGlobalBounds().width - InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista));
	InfoPjesma::textSimbolVrsta.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300 + 14 - InfoPjesma::textVrstaListe.getGlobalBounds().width - InfoPjesma::PaddingHorizontalPlayLista - InfoPjesma::textVrstaListe.getGlobalBounds().width + 20, InfoPjesma::PaddingVerticalPlayLista));

	Tipka Play, Shuffle, Pretraga;

	Play.SetTipka(
		"ListaPlay",
		L"\uE768",
		{ 60, 60 },
		24,
		sf::Color::White,
		sf::Color(10, 10, 10),
		InfoPjesma::fontEmoji,
		sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingHorizontal, 120),
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
		sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingHorizontal + 60, 120),
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
		sf::Vector2f(InfoPjesma::sirinaWindow - 300 -InfoPjesma::PaddingHorizontal - 60, 120),
		{ 18, 18 }
	);

	InfoPjesma::Tipke.push_back(Play);
	InfoPjesma::Tipke.push_back(Shuffle);
	InfoPjesma::Tipke.push_back(Pretraga);

	InfoPjesma::SetTextBox();

	InfoPjesma::RenderSvePjesme(Pjesme, window);
	InfoPjesma::PostaviCoverUpLista();
}

void InfoPjesma::RenderList(sf::RenderWindow& window)
{
	InfoPjesma::CoverUpListaUp.setSize(sf::Vector2f(InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300, 180));
	InfoPjesma::CoverUpListaUp.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x, 0));
	window.draw(InfoPjesma::CoverUpListaUp);

	
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
		sf::Vector2f(InfoPjesma::VelicinaLijevo.x + 120 + InfoPjesma::PaddingHorizontal, 120),
		{16,16},
		sf::Vector2f(InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - InfoPjesma::PaddingVertical - InfoPjesma::PaddingHorizontal - 300 - 120 - 40, 60)
	);


	InfoPjesma::TextBoxovi.push_back(MainPretragaListe);
}

void InfoPjesma::RenderSvePjesme(std::vector<Pjesma> &Pjesme, sf::RenderWindow& window)//za sad vektor samo stringova
{
	int x = InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingVertical;
	int y = 240;

	for (const Pjesma &pjesma : Pjesme)
	{
		sf::RectangleShape pozadinaPjesma;
		sf::Text imePjesme;

		imePjesme.setFont(InfoPjesma::font);

		pozadinaPjesma.setFillColor(sf::Color(45,45,45));
		imePjesme.setFillColor(sf::Color::White);

		pozadinaPjesma.setSize(sf::Vector2f(InfoPjesma::sirinaWindow - x - 300 - 20, 50));

		pozadinaPjesma.setPosition(sf::Vector2f(x, y));
		imePjesme.setPosition(sf::Vector2f(x, y));


		y += 50 + 10;
	}
}


void InfoPjesma::Update()
{
	//std::cout << "move\n";
	//InfoPjesma::textNaslov.move(sf::Vector2f(InfoPjesma::rateNaslov, 0));
	InfoPjesma::PozadinaPlaylist.setPosition(sf::Vector2f(InfoPjesma::sirinaWindow - 300, 0));
	if (InfoPjesma::textNaslov.getGlobalBounds().width > InfoPjesma::VelicinaLijevo.x - InfoPjesma::PaddingHorizontal * 2)
	{
		//std::cout << "velicina lijevo " << InfoPjesma::VelicinaLijevo.x << ", global bounds x " << InfoPjesma::textNaslov.getGlobalBounds().width << "\n";
		
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
			InfoPjesma::textNaslov.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x - InfoPjesma::PaddingHorizontal, InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingVertical));
		}

	}

	if (InfoPjesma::textPjesnici.getGlobalBounds().width > InfoPjesma::VelicinaLijevo.x - InfoPjesma::PaddingHorizontal * 2)
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
			InfoPjesma::textPjesnici.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x - InfoPjesma::PaddingHorizontal, 
				InfoPjesma::pozicijaPjesma.y + InfoPjesma::PaddingVertical + InfoPjesma::VelicinaLijevo.x + 26 + 20
				));
		}
	}

	InfoPjesma::ResizeCenter();

}

void InfoPjesma::PostaviCoverUpLista()
{
	InfoPjesma::CoverUpListaUp.setFillColor(sf::Color(10, 10, 10));
	InfoPjesma::CoverUpListaDown.setFillColor(sf::Color(10, 10, 10));

	InfoPjesma::CoverUpListaUp.setSize(sf::Vector2f(InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300, 220));
	InfoPjesma::CoverUpListaUp.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x, 0));
}

void InfoPjesma::SetListeDesno(std::vector<std::string> ListeZaSad, sf::RenderWindow& window)
{
	InfoPjesma::PozadineListi = InfoPjesma::RenderSveListe(ListeZaSad, window);
}

void InfoPjesma::RenderListDesno(sf::RenderWindow& window)
{
	InfoPjesma::CoverUpDesno.setFillColor(sf::Color::Black);
	InfoPjesma::CoverUpDesno.setSize(sf::Vector2f(300, 220));
	InfoPjesma::CoverUpDesno.setPosition(sf::Vector2f(InfoPjesma::sirinaWindow - 300, 0));

	
	InfoPjesma::PlayListNaslov.setFont(InfoPjesma::fontBoldest);
	InfoPjesma::PlayListNaslov.setFillColor(sf::Color::White);
	InfoPjesma::PlayListNaslov.setCharacterSize(InfoPjesma::NaslovFontSize);
	InfoPjesma::PlayListNaslov.setOutlineThickness(0.2);
	InfoPjesma::PlayListNaslov.setPosition(InfoPjesma::sirinaWindow - 300 + InfoPjesma::PaddingHorizontalPlayLista, 0 + InfoPjesma::PaddingVerticalPlayLista);
	InfoPjesma::PlayListNaslov.setString("Playliste");


	for (const sf::RectangleShape pozadina : InfoPjesma::PozadineListi)
	{
		window.draw(pozadina);
	}
	window.draw(InfoPjesma::CoverUpDesno);
	window.draw(InfoPjesma::PlayListNaslov);

}

std::vector<sf::RectangleShape> InfoPjesma::RenderSveListe(std::vector<std::string>& ListeZaSasd, sf::RenderWindow& window)
{
	std::vector<sf::RectangleShape> Pozadine;
	int x = InfoPjesma::sirinaWindow - 300 + 20;
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
	InfoPjesma::PozadinaPlaylist.setSize(sf::Vector2f(300, InfoPjesma::visinaWindow));
	InfoPjesma::PozadinaPlaylist.setPosition(sf::Vector2f(InfoPjesma::sirinaWindow - 300, 0));
}

void InfoPjesma::RenderDesno(sf::RenderWindow &window)
{
	window.draw(InfoPjesma::PozadinaPlaylist);
	window.draw(InfoPjesma::PozadinaAlbum);
}

void InfoPjesma::ResizeCenter()
{
	for (TextBox& textbox : InfoPjesma::TextBoxovi)
	{
		textbox.PostaviVelicinu(sf::Vector2f(InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - InfoPjesma::PaddingVertical - InfoPjesma::PaddingHorizontal - 300 - 120 -60, 60));
	}
	int x = InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingVertical;
	for (sf::RectangleShape &pozadina : InfoPjesma::PozadinePjesma)
	{
		pozadina.setSize(sf::Vector2f(InfoPjesma::sirinaWindow - x - 300 - 20, 50));
	}
	InfoPjesma::Tipke.at(2).SetPozicija(sf::Vector2f(InfoPjesma::sirinaWindow - 300 - InfoPjesma::PaddingHorizontal - 60, 120));
	InfoPjesma::Tipke.at(2).SetTextPozicija({ 18,18 });
	InfoPjesma::textNaslovListe.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista));
	InfoPjesma::textKreatroListe.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista + InfoPjesma::textNaslovListe.getGlobalBounds().height + 10));
	InfoPjesma::textVrstaListe.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300 - InfoPjesma::textVrstaListe.getGlobalBounds().width - InfoPjesma::PaddingHorizontalPlayLista, InfoPjesma::PaddingVerticalPlayLista));
	InfoPjesma::textSimbolVrsta.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x + InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300 + 14 - InfoPjesma::textVrstaListe.getGlobalBounds().width - InfoPjesma::PaddingHorizontalPlayLista - InfoPjesma::textVrstaListe.getGlobalBounds().width + 20, InfoPjesma::PaddingVerticalPlayLista));


}