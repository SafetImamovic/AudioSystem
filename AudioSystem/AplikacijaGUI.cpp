#include "AplikacijaGUI.h"
#include <iostream>
//----------------------private----------------------------------//

void AplikacijaGUI::InicijalizacijaVarijabli()
{
	this->window = nullptr; //dobra praksa da se pointer inicijalizira sa nullptr. incicijalizirmao prozor kao pointer jer zelimo da ga alociramo na heap
	//i fleksibilnija je kontrola

	this->videoMode.height = 720; //visina prozora koja se smijesta unutar this->videoMode
	this->videoMode.width = 1280; //sirina prozora koja se smijesta unutar this->videoMode

	
}

void AplikacijaGUI::InicijalizacijaProzora()
{
	this->window = new sf::RenderWindow(this->videoMode, "Audio System", sf::Style::Close | sf::Style::Titlebar);
	//rezolucijom zadanom preko VideoMode konstruktora, naziv prozora je zadan
	//drugim parametrom, treci parametar moze da primi bitwise argumente koji definisu da se prozor moze zatvoriti
	//i da je prikazan naslov prozora
	//Prozor takodjer sluzi kao Listener razlicitih eventova, unutar sebe ima mnogo callback funckija koje slusaju
	//razlicite interakcije npr. pomjeranje misa, kucanje itd.

	this->window->setFramerateLimit(240); //stavlja frame cap of 240fps, frame cap je toliko velik ukoliko neko ima monitor od 240hz
	//ukoliko neko ima monitor od 360hz ili vise onda :p
}

void AplikacijaGUI::InicijalizacijaElemenata()
{
	this->rect.setSize(sf::Vector2f(100.f, 100.f));
	this->rect.setFillColor(sf::Color::Cyan);

	this->textbox1.SetSve(20, sf::Color::White, sf::Color(30, 30, 30), true, this->font, sf::Vector2f(200, 50), sf::Vector2f(20, 15), sf::Vector2f(1000, 50));
	this->tipka1.SetTipka("nice", { 200, 50 }, 20, sf::Color(255, 255, 255, 255), sf::Color(30, 30, 30));
	this->tipka1.SetPozicija({ 200, 400 });
	this->tipka1.SetFont(this->font);
}

//------------------end of private-------------------------------//

AplikacijaGUI::AplikacijaGUI(sf::Font& font) //konstruktor poziva privatne metode koje inicijaliziraju varijable i prozor
{
	this->font = font;
	this->InicijalizacijaVarijabli();
	this->InicijalizacijaProzora();
	this->InicijalizacijaElemenata();
}

AplikacijaGUI::~AplikacijaGUI()
{
	delete this->window; //destruktor de-alocira dinamicki alociran prozor
}



void AplikacijaGUI::UpdateRect()
{

}

void AplikacijaGUI::UpdatePozicijaMisa()
{
	this->mousePozProzor = sf::Mouse::getPosition(*this->window); //vraca poziciju misa (koord.) relativno prozoru
}

void AplikacijaGUI::UpdatePollEvents() //ova metoda osvjezava eventove, npr. interakcija sa prozorom od strane korisinka
{

	while (this->window->pollEvent(this->event))//dok cita eventove smijesta vrijednost i vrstu unutar varijable event
	{
		switch (this->event.type)//provjerava koja je vrsta eventa
		{
		case sf::Event::Closed://ako korisnik pritisne close button aplikacije
			this->window->close();//onda se prozor zatvori
			break;
		case sf::Event::TextEntered:
			this->textbox1.OtipkanoNa(this->event);//kada je tekst otkucan poziva metodu objekta za ovaj textbox
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Enter)
				std::cout << this->textbox1.GetText() << std::endl;
			break;
		case sf::Event::MouseMoved:
			if (this->tipka1.Hover(*this->window))
			{
				this->tipka1.PromijeniBojuPozadine(sf::Color::White);
			}
			else
			{
				this->tipka1.PromijeniBojuPozadine(sf::Color(30, 30, 30));
			}
			break;
		default:
			break;
		}
	}
}

void AplikacijaGUI::UpdateGUI() //metoda koja osvjezi "update-je" logiku vezanu za GUI prije nego sto se frame renderuje
{
	this->UpdatePollEvents();//poziva metodu koja prate eventove
	this->UpdatePozicijaMisa();
	this->UpdateRect();
}

void AplikacijaGUI::RenderRect()
{
	this->window->draw(this->rect);
}

void AplikacijaGUI::RenderGUI() //renderuje objekte, elemente aplikacije
{
	this->window->clear(); //clear-a stari frame

	//--------ovdje krece pozivanje metoda koje iscrtavaju elemente----------

	this->textbox1.DrawTo(*this->window);
	this->tipka1.DrawTo(*this->window);

	//--------ovdje zavrsava pozivanje metoda koje iscrtavaju elemente-------

	this->window->display(); //ovo je indikator da je frame zavrsen sa crtanjem
    //izmedju window.clear() i window.display() crtamo prozor tj. elemente unutar prozora
}

const bool AplikacijaGUI::getWindowIsOpen() const //metoda koja vraca da li je prozor otvoren
{
	return this->window->isOpen();
}