#pragma once
#include "ElementarneKomponente.h"
#include "Tipka.h"
#include "TextBox.h"
#include "PlayList.h"
#include <string>



class InfoPjesma : public ElementarneKomponente
{
public:
	struct InfoPjesmaRender : public ElementarneKomponente //ovo je strukt za render pjesme koja ce se nalazit u centru GUI-a, skupina pjesama
	{
		static int BrojPjesama;
		int Visina = 40;
		int paddingHorizontal = 10;
		int paddingVertical = 8;
		sf::Color PrimarnaBoja = sf::Color(10, 10, 10);
		sf::Font font;
		sf::Font fontEmoji;
		std::string lokacijaSlike;
		std::string lokacijaPjesme;

		int intID;
		sf::Texture Cover;
		sf::Sprite CoverRender;

		sf::Text ID;
		sf::Text Ime;
		sf::Text ImeAutora;
		sf::Text TrajanjePjesme;
		sf::Text DodajPjesmuUPlaylist;
		sf::Text Like;

		std::vector<Tipka> Tipke;

		sf::RectangleShape GlavnaPozadina;
		sf::RectangleShape ID_Cover_Ime_Pozadina;
		sf::RectangleShape Autor_Pozadina;
		sf::RectangleShape Trajanje_Add_Like_Pozadina;

		void SetInfoPjesmaRender(const Pjesma& pjesma, std::string lokacijaSlike, sf::Font& font, sf::Font& fontEmoji)
		{
			this->GlavnaPozadina.setFillColor(this->PrimarnaBoja);
			this->ID_Cover_Ime_Pozadina.setFillColor(this->PrimarnaBoja);
			this->Autor_Pozadina.setFillColor(this->PrimarnaBoja);
			this->Trajanje_Add_Like_Pozadina.setFillColor(this->PrimarnaBoja);

			this->lokacijaPjesme = pjesma.getLokacijaPjesme();

			this->lokacijaSlike = lokacijaSlike;
			intID = pjesma.getID_Pjesme();
			InfoPjesmaRender::BrojPjesama++;
			std::cout << "Broj Pjesama = " << InfoPjesmaRender::BrojPjesama << "\n";
			std::cout << "Slika: " << pjesma.getLokacijaPjesme() << "\n";
			this->SetFont(font, fontEmoji);
			this->FixPozicija(400, InfoPjesma::sirinaWindow - 400 - 300);

			this->ID.setString(std::to_string(pjesma.getID_Pjesme()));

			sf::Texture Cover;
			Cover.loadFromFile(lokacijaSlike);

			this->CoverRender.setTexture(Cover);

			this->Ime.setString(pjesma.getIme());
			this->ImeAutora.setString(pjesma.getImeAutora());
			this->TrajanjePjesme.setString("3:30");
			this->DodajPjesmuUPlaylist.setString("+");

			if(!pjesma.getDaLiJeLajkana())
				this->Like.setString(L"\uE006");
			else
				this->Like.setString(L"\uE00B");

			this->LoadCover();
		}

		void SetFont(sf::Font& font, sf::Font& fontEmoji)
		{
			this->ID.setFont(font);
			this->Ime.setFont(font);
			this->ImeAutora.setFont(font);
			this->TrajanjePjesme.setFont(font);
			this->DodajPjesmuUPlaylist.setFont(font);
			this->Like.setFont(fontEmoji);

			this->ID.setFillColor(sf::Color(127, 127, 127));
			this->Ime.setOutlineColor(sf::Color::White);
			this->Ime.setOutlineThickness(0.25);

			this->ID.setCharacterSize(16);
			this->Ime.setCharacterSize(16);
			this->ImeAutora.setCharacterSize(16);
			this->TrajanjePjesme.setCharacterSize(16);
			this->DodajPjesmuUPlaylist.setCharacterSize(16);
			this->Like.setCharacterSize(16);
		}

		void Render(sf::RenderWindow& window, std::string lokacijaSlike)
		{
			window.draw(this->GlavnaPozadina);
			window.draw(this->ID_Cover_Ime_Pozadina);
			window.draw(this->ID);
			window.draw(this->CoverRender);
			window.draw(this->Ime);
			window.draw(this->Autor_Pozadina);
			window.draw(this->ImeAutora);
			window.draw(this->Trajanje_Add_Like_Pozadina);
			window.draw(this->TrajanjePjesme);
			window.draw(this->DodajPjesmuUPlaylist);
			window.draw(this->Like);
		}

		void FixPozicija(int lijeviOffset, int sirinaCentar)
		{
			this->LoadCover();
			int spacing = (sirinaCentar - 20 - 40 - 120) / 3;

			this->GlavnaPozadina.setPosition(sf::Vector2f(
				lijeviOffset,
				200 + (50 * (this->intID - 1)) - 5
			));

			this->GlavnaPozadina.setSize(sf::Vector2f(
				sirinaCentar,
				this->Visina + 10
			));


			this->ID_Cover_Ime_Pozadina.setPosition(sf::Vector2f(
				lijeviOffset,
				200 + (50 * (this->intID - 1)) - 5
			));

			this->ID_Cover_Ime_Pozadina.setSize(sf::Vector2f(
				sirinaCentar,
				this->Visina + 10
			));


			this->Autor_Pozadina.setPosition(sf::Vector2f(
				lijeviOffset + (spacing * 1.5),
				200 + (50 * (this->intID - 1)) - 5
			));

			this->Autor_Pozadina.setSize(sf::Vector2f(
				sirinaCentar - (spacing * 1.5),
				this->Visina + 10
			));


			this->Trajanje_Add_Like_Pozadina.setPosition(sf::Vector2f(
				lijeviOffset + sirinaCentar - 120,
				200 + (50 * (this->intID - 1)) - 5
			));

			this->Trajanje_Add_Like_Pozadina.setSize(sf::Vector2f(
				sirinaCentar - sirinaCentar + 120,
				this->Visina + 10
			));


			if(this->intID < 10)
				this->ID.setPosition(lijeviOffset + this->paddingHorizontal, 200 + paddingVertical + (50 * (this->intID - 1)));
			else
				this->ID.setPosition(lijeviOffset + this->paddingHorizontal - 6, 200 + paddingVertical + (50 * (this->intID - 1)));

			this->CoverRender.setPosition(lijeviOffset + this->paddingHorizontal + 20, 200 + (50 * (this->intID - 1)));
			this->CoverRender.setScale({ 0.1, 0.1 });

			this->Ime.setPosition(lijeviOffset + 2*this->paddingHorizontal + (spacing * 0) + 60, 200 + paddingVertical + (50 * (this->intID - 1)));
			this->ImeAutora.setPosition(lijeviOffset + this->paddingHorizontal + (spacing * 1.5), 200 + paddingVertical + (50 * (this->intID - 1)));
			this->TrajanjePjesme.setPosition(lijeviOffset + this->paddingHorizontal + sirinaCentar - 120, 200 + paddingVertical + (50 * (this->intID - 1)));
			this->DodajPjesmuUPlaylist.setPosition(lijeviOffset + this->paddingHorizontal + sirinaCentar - 80, 200 + paddingVertical + (50 * (this->intID - 1)));
			this->Like.setPosition(lijeviOffset + this->paddingHorizontal + sirinaCentar - 40, 200 + paddingVertical + (50 * (this->intID - 1)) + 2);
		}

		void PromijeniBojuPozadine(sf::Color boja)
		{
			this->GlavnaPozadina.setFillColor(boja);
			this->ID_Cover_Ime_Pozadina.setFillColor(boja);
			this->Autor_Pozadina.setFillColor(boja);
			this->Trajanje_Add_Like_Pozadina.setFillColor(boja);
		}

		void LoadCover()
		{
			this->Cover.loadFromFile(this->lokacijaSlike);
			this->CoverRender.setTexture(this->Cover);
		}
	};

	static sf::RectangleShape pozadinaLista;
	static sf::RectangleShape pozadinaPjesma;
	static sf::Vector2f pozicijaLista;
	static sf::Vector2f pozicijaPjesma;
	static sf::Vector2f dimenzijeLista;
	static sf::Vector2f dimenzijaPjesma;
	static sf::Color PrimarnaBoja;
	static int sirinaWindow;
	static int visinaWindow;
	static std::string NaslovPjesme;
	static sf::Text textNaslov;
	static std::string PjesniciPjesme;
	static sf::Text textPjesnici;
	static std::wstring NaslovListe;
	static sf::Text textNaslovListe;
	static std::wstring KreatorListe;
	static sf::Text textKreatroListe;
	static sf::Font font;
	static sf::Font fontEmoji;
	static int PaddingVertical;
	static int PaddingHorizontal;
	static int PaddingVerticalPlayLista;
	static int PaddingHorizontalPlayLista;
	static sf::RectangleShape CoverUpMain;
	static sf::RectangleShape CoverUpMainTwo;
	static sf::RectangleShape CoverUpSecondary;
	static sf::Texture Cover;
	static sf::Sprite CoverRender;
	static float rateNaslov;
	static float ratePjesnici;
	static std::wstring VrstaListe;
	static sf::Text textVrstaListe;
	static sf::Text textSimbolVrsta;
	static std::vector<Tipka> Tipke;
	static std::vector<TextBox> TextBoxovi;
	static std::vector<sf::RectangleShape> PozadinePjesma;
	static std::vector<sf::RectangleShape> PozadineListi;
	static sf::RectangleShape CoverUpListaUp;
	static sf::RectangleShape CoverUpListaDown;
	static sf::RectangleShape PozadinaAlbum;
	static sf::RectangleShape PozadinaPlaylist;
	static sf::RectangleShape CoverUpDesno;
	static sf::Text PlayListNaslov;
	static sf::Vector2f VelicinaLijevo;
	static int BaznaRezolucijaSlike;
	static int NaslovFontSize;
	static int NaslovFontSize2;
	static int NaslovFontSize3;


	InfoPjesma() = default;
	static void SetPjesma(std::string naslov, std::string pjesnici, sf::Font &font, sf::Font& fontEmoji);
	static void RenderPjesma(sf::RenderWindow& window);
	static void SetList(std::wstring naslov, std::wstring kreator, std::vector<Pjesma>& Pjesme, bool VrstaListeBool, sf::RenderWindow& window);
	static void SetListeDesno(std::vector<std::string> ListeZaSad, sf::RenderWindow& window);
	static void RenderList(sf::RenderWindow& window);
	static void RenderListDesno(sf::RenderWindow& window);
	static void SetTextBox();
	static void RenderSvePjesme(std::vector<Pjesma> &Pjesme, sf::RenderWindow& window);
	static std::vector<sf::RectangleShape> RenderSveListe(std::vector<std::string>& ListeZaSasd, sf::RenderWindow& window);
	static void PostaviCoverUpLista();
	static void Update();
	static void PostaviPozadineDesno();
	static void RenderDesno(sf::RenderWindow &window);
	static void ResizeCenter();
};

