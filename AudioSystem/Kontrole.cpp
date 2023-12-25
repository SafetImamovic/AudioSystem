#include "Kontrole.h"

void Kontrole::InicijalizacijaTipki()
{
	this->GlobalnaPozadina.setFillColor(sf::Color(30, 30, 30));
	this->GlobalnaPozadina.setPosition(0, this->videoMode.height - 110);
	this->GlobalnaPozadina.setSize(sf::Vector2f(this->videoMode.width, 200));
	
	Tipka TipkaPoslije, TipkaPrije, TipkaPustiPauziraj, TipkaLoop, TipkaMute, TipkaSkipNaprijed, TipkaSkipPrije, TipkaLike, TipkaShuffle;
	sf::Vector2f velicinaTipke = sf::Vector2f(this->visinaTipke, this->visinaTipke);

	this->pocetnaKoordinataXTipke = (this->videoMode.width / 2) - (this->sirinaTipke * 4 / 2);
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke;
	//racuna donju granicu prozora



	TipkaLike.SetTipka(
		"Like",
		L"\uE006\uE00B",
		velicinaTipke,
		24,
		sf::Color::White,
		PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(0, pocetnaKoordinataY),
		{ 18, 18 }
	);

	TipkaShuffle.SetTipka(
		"Shuffle",
		L"\uE8B1",
		velicinaTipke,
		24,
		sf::Color::White,
		PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(this->pocetnaKoordinataXTipke - this->sirinaTipke, pocetnaKoordinataY),
		{ 18, 18 }
	);

	TipkaPrije.SetTipka(
		"Prije",
		L"\uE892",
		velicinaTipke,
		24,
		sf::Color::White,
		PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(this->pocetnaKoordinataXTipke, pocetnaKoordinataY),
		{ 18, 18 }
	);

	/*
	TipkaSkipPrije.SetTipka(
		"SkipPrije",
		L"⬅",
		velicinaTipke,
		24,
		sf::Color::White,
		PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(this->pocetnaKoordinataXTipke + this->sirinaTipke, pocetnaKoordinataY),
		{ 20, 14 }
	);
	*/

	TipkaPustiPauziraj.SetTipka(
		"PustiPauziraj",
		L"\uE768",
		velicinaTipke,
		26,
		sf::Color::White,
		PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(this->pocetnaKoordinataXTipke + this->sirinaTipke * 1, pocetnaKoordinataY),
		{ 17, 17 }
	);

	/*
	TipkaSkipNaprijed.SetTipka(
		"SkipNaprijed",
		L"➡",
		velicinaTipke,
		24,
		sf::Color::White,
		PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(this->pocetnaKoordinataXTipke + this->sirinaTipke*3, pocetnaKoordinataY),
		{ 20, 14 }
	);
	*/

	TipkaPoslije.SetTipka(
		"Poslije",
		L"\uE893",
		velicinaTipke,
		24,
		sf::Color::White,
		this->PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(this->pocetnaKoordinataXTipke + 2 * this->sirinaTipke, pocetnaKoordinataY),
		{ 18, 18 }
	);

	TipkaLoop.SetTipka(
		"Loop",
		L"\uE8EE",
		velicinaTipke,
		24,
		sf::Color::White,
		PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(this->pocetnaKoordinataXTipke + 3 * this->sirinaTipke, pocetnaKoordinataY),
		{ 18, 18 }
	);

	TipkaMute.SetTipka(
		"Mute",
		L"\uE767",
		velicinaTipke,
		24,
		sf::Color::White,
		PrimarnaBoja,
		this->fontEmoji,
		sf::Vector2f(this->videoMode.width - 200 - 120, pocetnaKoordinataY),
		{ 18, 18 }
	);

	this->Tipke.push_back(TipkaPoslije);
	this->Tipke.push_back(TipkaPrije);
	this->Tipke.push_back(TipkaPustiPauziraj);
	this->Tipke.push_back(TipkaLoop);
	this->Tipke.push_back(TipkaMute);
	this->Tipke.push_back(TipkaSkipNaprijed);
	this->Tipke.push_back(TipkaSkipPrije);
	this->Tipke.push_back(TipkaLike);
	this->Tipke.push_back(TipkaShuffle);
}

void Kontrole::InicijalizacijaScroll()
{
	this->sirinaScroll = this->videoMode.width - 150 - 40;
	int scrollBarInnerVisina = 2;
	int scrollBarInnerSirina = this->sirinaScroll;
	int pocetnaKoordinataX = 20;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke - this->visinaScroll;

	this->ScrollPozadina.setSize(sf::Vector2f(this->sirinaScroll, this->visinaScroll));
	this->ScrollPozadina.setFillColor(sf::Color(30, 30, 30));
	this->ScrollPozadina.setPosition(sf::Vector2f(pocetnaKoordinataX, pocetnaKoordinataY));

	this->ScrollBar.setSize(sf::Vector2f(scrollBarInnerSirina, scrollBarInnerVisina));
	this->ScrollBar.setFillColor(sf::Color::Black);
	this->ScrollBar.setPosition(sf::Vector2f(pocetnaKoordinataX,
		pocetnaKoordinataY + this->visinaScroll / 2 - scrollBarInnerVisina / 2));

	this->ScrollBarFollow.setSize(sf::Vector2f(0, scrollBarInnerVisina));//zavisi od save fajla gdje je stala pjesma zadnji put(prvi element Vector2f)
	this->ScrollBarFollow.setFillColor(sf::Color::White);
	this->ScrollBarFollow.setPosition(sf::Vector2f(pocetnaKoordinataX,
		pocetnaKoordinataY + this->visinaScroll / 2 - scrollBarInnerVisina / 2));

	this->ScrollSimbol.setFont(this->font);
	this->ScrollSimbol.setString(L"⚫");
	this->ScrollSimbol.setCharacterSize(16);

}

void Kontrole::InicijalizacijaGlasnoca()
{
	int glasnocaBarInnerVisina = 2;
	int glasnocaBarInnerSirina = this->sirinaGlasnoca;

	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke;

	this->GlasnocaPozadina.setSize(sf::Vector2f(this->sirinaGlasnoca, this->visinaGlasnoca));
	this->GlasnocaPozadina.setFillColor(sf::Color(30, 30, 30));
	this->GlasnocaPozadina.setPosition(sf::Vector2f(this->videoMode.width - this->sirinaGlasnoca - this->sirinaTipke, pocetnaKoordinataY));

	this->GlasnocaBar.setSize(sf::Vector2f(glasnocaBarInnerSirina, glasnocaBarInnerVisina));
	this->GlasnocaBar.setFillColor(sf::Color::Black);
	this->GlasnocaBar.setPosition(sf::Vector2f(this->videoMode.width - this->sirinaGlasnoca - this->sirinaTipke,
		pocetnaKoordinataY + this->visinaGlasnoca / 2 - glasnocaBarInnerVisina / 2));

	this->GlasnocaBarFollow.setSize(sf::Vector2f(glasnocaBarInnerSirina, glasnocaBarInnerVisina));
	this->GlasnocaBarFollow.setFillColor(sf::Color::White);
	this->GlasnocaBarFollow.setPosition(sf::Vector2f(this->videoMode.width - this->sirinaGlasnoca - this->sirinaTipke,
		pocetnaKoordinataY + this->visinaGlasnoca / 2 - glasnocaBarInnerVisina / 2));

	this->GlasnocaSimbol.setFont(this->font);
	this->GlasnocaSimbol.setString(L"⚫");
	this->GlasnocaSimbol.setCharacterSize(16);

	this->GlasnocaProcenatPozadina.setSize(sf::Vector2f(this->sirinaTipke, this->visinaTipke));
	this->GlasnocaProcenatPozadina.setFillColor(sf::Color(30, 30, 30));
	this->GlasnocaProcenatPozadina.setPosition(this->videoMode.width - this->sirinaTipke, pocetnaKoordinataY);

	this->GlasnocaProcenat.setFont(this->font);
	this->GlasnocaProcenat.setString("100%");
	this->GlasnocaProcenat.setCharacterSize(16);
	this->GlasnocaProcenat.setFillColor(sf::Color::White);
	this->GlasnocaProcenat.setPosition(this->videoMode.width - this->sirinaTipke + 13, pocetnaKoordinataY + 18);

}

float Kontrole::UpdatePozicijaSimbolaWindow(sf::RenderWindow &window)
{
	int scrollBarInnerVisina = 4;
	int scrollBarInnerSirina = this->sirinaScroll - 50;
	float pocetnaKoordinataX = 20;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke - this->visinaScroll;
	
	if (this->Hover(window, this->ScrollPozadina))
	{
		std::cout << ((sf::Mouse::getPosition(window).x - pocetnaKoordinataX) / this->sirinaScroll) << "\n";
		return ((sf::Mouse::getPosition(window).x - pocetnaKoordinataX) / this->sirinaScroll);
	}
	
}

float Kontrole::UpdatePozicijaSimbolaWindowGlasnoca(sf::RenderWindow& window)
{
	float pocetnaKoordinataX = this->videoMode.width - this->sirinaGlasnoca - this->sirinaTipke;
	//std::cout << "nice\n";
	int glasnocaBarInnerVisina = 2;
	float pocetnaKoordinataYGlasnoca = this->videoMode.height - this->visinaTipke + this->visinaTipke/4;
	if (this->Hover(window, this->GlasnocaPozadina))
	{

		std::cout << sf::Mouse::getPosition(window).x - (pocetnaKoordinataX) / this->sirinaGlasnoca << "\n";
		return (sf::Mouse::getPosition(window).x - (pocetnaKoordinataX)) / this->sirinaGlasnoca;
	}
}

void Kontrole::UpdatePozicijaSimbola(float index)
//uvijek update-uje poziciju simbola unutar scroll bara po procentu trenutne pjesme, konstantno je pozvana
{
	int scrollBarInnerVisina = 4;
	int scrollBarInnerSirina = 1000;
	int pocetnaKoordinataX = 20;

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke - this->visinaScroll;


	this->ScrollSimbol.setPosition(sf::Vector2f(static_cast<float>(- 6 + index * (this->sirinaScroll) + pocetnaKoordinataX), pocetnaKoordinataY + 15));
	this->ScrollBarFollow.setSize(sf::Vector2f(index * (this->sirinaScroll), 2));
}


void Kontrole::UpdatePozicijaSimbolaGlasnoca(float index, sf::RenderWindow &window)
//uvijek takodjer update-uje simbol unutar bara za glasnocu po procentu koji mu je uvijek poslan
{
	float pocetnaKoordinataX = this->videoMode.width - this->sirinaGlasnoca - this->sirinaTipke;
	int glasnocaBarInnerVisina = 2;
	int glasnocaBarInnerSirina = this->sirinaGlasnoca;

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke;

	if (index < 0 || index > 1)
		return;
	this->GlasnocaSimbol.setPosition(sf::Vector2f(-6 + index * (this->sirinaGlasnoca) + pocetnaKoordinataX, pocetnaKoordinataY + 5 + this->visinaGlasnoca / 4));
	this->GlasnocaBarFollow.setSize(sf::Vector2f(index * (this->sirinaGlasnoca), 2));
	this->GlasnocaProcenat.setString(std::to_string(static_cast<int>(index * 100) ) + "%");
	//this->GlasnocaProcenat.
}


void Kontrole::RenderScroll(sf::RenderWindow &window)
{
	
	window.draw(this->ScrollPozadina);
	window.draw(this->ScrollBar);
	window.draw(this->ScrollBarFollow);
	window.draw(this->ScrollSimbol);

}

void Kontrole::RenderGlasnoca(sf::RenderWindow& window)
{
	
	window.draw(this->GlasnocaPozadina);
	window.draw(this->GlasnocaBar);
	window.draw(this->GlasnocaBarFollow);
	window.draw(this->GlasnocaProcenatPozadina);
	window.draw(this->GlasnocaProcenat);
	window.draw(this->GlasnocaSimbol);
	
}

void Kontrole::SetKontrole(sf::VideoMode &videoMode, sf::Font &font, sf::Font &fontEmoji, sf::Color PirmarnaBoja, sf::Color SekundrnaBoja, sf::Color AkcenatBoja)
{
	

	this->videoMode = videoMode;
	this->font = font;
	this->fontEmoji = fontEmoji;
	this->PrimarnaBoja = PrimarnaBoja;
	this->SekundarnaBoja = SekundrnaBoja;
	this->AkcenatBoja = AkcenatBoja;

	

	this->InicijalizacijaTipki();
	this->InicijalizacijaScroll();
	this->InicijalizacijaGlasnoca();
}

void Kontrole::RenderVrijeme(sf::RenderWindow& window, float sekunde, float trajanje, sf::Color PrimarnaBoja)
{
	int pocetnaKoordinataX = 20;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke

	int pocetnaKoordinataY = this->videoMode.height - this->visinaTipke - this->visinaScroll;

	sf::RectangleShape pozadina({ 150, 50 });
	pozadina.setFillColor(PrimarnaBoja);
	sf::Text text;
	text.setCharacterSize(16);
	text.setFont(this->font);
	std::string TEXT;

	
		TEXT = formatTime(sekunde) + " / " + formatTime(trajanje);
	pozadina.setPosition(sf::Vector2f(pocetnaKoordinataX + this->sirinaScroll, pocetnaKoordinataY));
	text.setPosition(sf::Vector2f(pocetnaKoordinataX + this->sirinaScroll + 13, pocetnaKoordinataY + 14));


	text.setString(TEXT);
	window.draw(pozadina);
	window.draw(text);
}

void Kontrole::PromijeniKarakter(std::string text, std::wstring promjena)
{
	for (Tipka &tipka : Tipke)
	{
		if (tipka.GetID() == text)
			tipka.PromijeniKarakter(promjena);
	}	
}

void Kontrole::RenderPozadina(sf::RenderWindow &window)
{
	window.draw(this->GlobalnaPozadina);
}
