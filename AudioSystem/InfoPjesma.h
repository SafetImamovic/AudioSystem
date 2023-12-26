#pragma once
#include "ElementarneKomponente.h"
#include "Tipka.h"
#include "TextBox.h"
#include <string>
class InfoPjesma : public ElementarneKomponente
{
private:
	
public:
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
	static std::string NaslovListe;
	static sf::Text textNaslovListe;
	static std::string KreatorListe;
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


	InfoPjesma() = default;
	static void SetPjesma(std::string naslov, std::string pjesnici, sf::Font &font, sf::Font& fontEmoji);
	static void RenderPjesma(sf::RenderWindow& window);
	static void SetList(std::string naslov, std::string kreator, std::vector<std::string> &PjesmeZaSad, bool VrstaListeBool, sf::RenderWindow& window);
	static void SetListeDesno(std::vector<std::string> ListeZaSad, sf::RenderWindow& window);
	static void RenderList(sf::RenderWindow& window);
	static void RenderListDesno(sf::RenderWindow& window);
	static void SetTextBox();
	static std::vector<sf::RectangleShape> RenderSvePjesme(std::vector<std::string>& PjesmeZaSad, sf::RenderWindow& window);
	static std::vector<sf::RectangleShape> RenderSveListe(std::vector<std::string>& ListeZaSasd, sf::RenderWindow& window);
	static void PostaviCoverUpLista();
	static void Update();
	static void MoveUp(std::string id);
	static void MoveDown(std::string id);
	static void PostaviPozadineDesno();
	static void RenderDesno(sf::RenderWindow &window);
	static void ResizeCenter();
};

