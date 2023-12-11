#include "AplikacijaGUI.h"
#include <iostream>
//----------------------private----------------------------------//

void AplikacijaGUI::InicijalizacijaVarijabli()
{
	this->window = nullptr; //dobra praksa da se pointer inicijalizira sa nullptr. incicijalizirmao prozor kao pointer jer zelimo da ga alociramo na heap
	//i fleksibilnija je kontrola

	this->videoMode.height = 720; //visina prozora koja se smijesta unutar this->videoMode
	this->videoMode.width = 1280; //sirina prozora koja se smijesta unutar this->videoMode

	this->PrimarnaBoja = sf::Color(30, 30, 30);
	this->SekundarnaBoja = sf::Color(100, 100, 100);
	this->AkcenatBoja = sf::Color::Red;
	
	
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
//ovo je vecinski dizajn i pozicioniranje elemenata na prozoru tako sto se instancira odgovarajuci element i nakon 
//konfigurisanja push_back-a se nazad na vektore koji sadrze njih
{
	this->rect.setSize(sf::Vector2f(100.f, 100.f));
	this->rect.setFillColor(sf::Color::Cyan);

	TextBox textbox1, textbox2;
	textbox1.SetSve(20, sf::Color::White, this->PrimarnaBoja, false, this->font, sf::Vector2f(200, 50), sf::Vector2f(20, 15), sf::Vector2f(1000, 50));

	textbox2.SetSve(20, sf::Color::White, this->PrimarnaBoja, false, this->font, sf::Vector2f(200, 250), sf::Vector2f(20, 15), sf::Vector2f(1000, 50));

	Tipka tipka1, TipkaPoslije, TipkaPrije, TipkaPustiPauziraj, TipkaLoop;
	//void Tipka::SetTipka(std::wstring text, sf::Vector2f velicina, int karakterVelicina, sf::Color bojaText, sf::Color bojaPozadine, sf::Font & font)
	tipka1.SetTipka("tipka1" , L"", {200, 50}, 20, sf::Color(255, 255, 255, 255), this->PrimarnaBoja, this->font, {200, 400}, {20, 20});
	//L ispred string-a je wstring koji podrzava UTF-16 karaktere, ima funkcija u Tipka klasi u vezi ovoga "SetTextUTF16(std::wstring text)"

	

	//TipkaPoslije.SetTipka(L"▷▷", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, {580, 600}, {6, 10});
	//TipkaPrije.SetTipka(L"◁◁", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, { 500, 600 }, { 4, 10 });
	//TipkaPustiPauziraj.SetTipka(L"▶◼", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, { 540, 600 }, { 4, 10 });
	//TipkaLoop.SetTipka(L"⟳", { 40, 40 }, 24, sf::Color::White, this->PrimarnaBoja, this->font, { 620, 600 }, { 9, 3 });

	int visina = 100, sirina = 100;
	sf::Vector2f velicinaTipke = sf::Vector2f(sirina, visina);
	int pocetnaKoordinataX, pocetnaKoordinataY = 620;

	pocetnaKoordinataX = this->videoMode.width / 2 - sirina * 4 / 2;
	//formula koja racuna horizontalni centar prozora, sirina * 4 je 4 jer imaju 4 tipke
	pocetnaKoordinataY = this->videoMode.height - visina;
	//racuna donju granicu prozora

	TipkaPoslije.SetTipka("Poslije", L"▷▷", velicinaTipke, 32, sf::Color::White, this->PrimarnaBoja, this->font, sf::Vector2f(pocetnaKoordinataX + 2 * sirina, pocetnaKoordinataY), {20, 26});
	TipkaPrije.SetTipka("Prije", L"◁◁", velicinaTipke, 32, sf::Color::White, this->PrimarnaBoja, this->font, sf::Vector2f(pocetnaKoordinataX, pocetnaKoordinataY), {20, 26});
	TipkaPustiPauziraj.SetTipka("PustiPauziraj", L"▶◼", velicinaTipke, 32, sf::Color::White, this->PrimarnaBoja, this->font, sf::Vector2f(pocetnaKoordinataX + sirina, pocetnaKoordinataY), {20, 26});
	TipkaLoop.SetTipka("Loop", L"⟳", velicinaTipke, 50, sf::Color::White, this->PrimarnaBoja, this->font, sf::Vector2f(pocetnaKoordinataX + 3 * sirina, pocetnaKoordinataY), {25, 11});



	this->TextBoxovi.push_back(textbox1);
	this->TextBoxovi.push_back(textbox2);
	this->Tipke.push_back(tipka1);
	this->Tipke.push_back(TipkaPoslije);
	this->Tipke.push_back(TipkaPrije);
	this->Tipke.push_back(TipkaPustiPauziraj);
	this->Tipke.push_back(TipkaLoop);

	//IPAK JE NALBOLJA PRAKSA NAPRAVITI ODVOJENU KLASU ZA PLAYER!
}

void AplikacijaGUI::ProvjeriHoverZaSveElemente()
{
	for (int i = 0; i < this->Tipke.size(); i++)
	{
		if (this->Tipke.at(i).Hover(*this->window, this->Tipke.at(i).tipka))//poziva metodu bool Hover(sf::RenderWindow& window) koja vraca true ako je kursor 
			//unutar dimenzija tipke relativno dimenzijama ekrana
		{
			this->Tipke.at(i).PromijeniBojuPozadine(this->SekundarnaBoja);
		}
		else
		{
			this->Tipke.at(i).PromijeniBojuPozadine(this->PrimarnaBoja);
		}
	}
	
	for(int i = 0; i < this->TextBoxovi.size(); i++)
	{
		if (this->TextBoxovi.at(i).Hover(*this->window, this->TextBoxovi.at(i).backgroundShape))
		{
			this->TextBoxovi.at(i).backgroundShape.setFillColor(this->SekundarnaBoja);
		}
		else
		{
			this->TextBoxovi.at(i).backgroundShape.setFillColor(this->PrimarnaBoja);
		}
	}
	
}

void AplikacijaGUI::ProvjeriClickZaSveElemente()
{
	for (int i = 0; i < this->TextBoxovi.size(); i++)
	{
		if (this->TextBoxovi.at(i).Hover(*this->window, this->TextBoxovi.at(i).backgroundShape))
		{
			this->TextBoxovi.at(i).SetOznacen(true);
		}
		else
		{
			this->TextBoxovi.at(i).SetOznacen(false);
		}
	}

	for (int i = 0; i < this->Tipke.size(); i++)
	{
		if (this->Tipke.at(i).Hover(*this->window, this->Tipke.at(i).tipka))
		{
			this->Tipke.at(i).PromijeniBojuPozadine(this->AkcenatBoja);
			std::cout << this->Tipke.at(i).GetID() << "\n";
		}
		else
		{
			this->Tipke.at(i).PromijeniBojuPozadine(this->PrimarnaBoja);
		}
	}
}

void AplikacijaGUI::RenderSveElemente()
{
	for (int i = 0; i < this->TextBoxovi.size(); i++)
	{
		this->TextBoxovi.at(i).DrawTo(*this->window);
	}
	for (int i = 0; i < this->Tipke.size(); i++)
	{
		this->Tipke.at(i).DrawTo(*this->window);
	}
}

void AplikacijaGUI::ResetPrimarneBoje()
{
	for (int i = 0; i < this->Tipke.size(); i++)
	{
		this->Tipke.at(i).PromijeniBojuPozadine(this->PrimarnaBoja);
	}
}

void AplikacijaGUI::GetOdgovarajuciTextBoxText()
{
	for (int i = 0; i < this->TextBoxovi.size(); i++)
	{
		if (this->TextBoxovi.at(i).JeOznacen())
		{
			std::cout << this->TextBoxovi.at(i).GetText() << std::endl;//getText metoda vraca string koji je korinsik otkucao u textbox
		}
		
	}
	
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
				break;
			for (int i = 0; i < this->TextBoxovi.size(); i++)
			{
				this->TextBoxovi.at(i).OtipkanoNa(this->event);//kada je tekst otkucan poziva metodu objekta za ovaj textbox
				//koja zapravo ispisuje tekst na prozoru
			}
			
			break;

		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Enter) //Kada korisnik pritisne enter
				this->GetOdgovarajuciTextBoxText();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
				//Poseban slucaj ako korisnik u isto vrijme pritisne ctrl i backspace onda se obrise string unutar textboxa
				for (int i = 0; i < this->TextBoxovi.size(); i++)
				{
					if (this->TextBoxovi.at(i).JeOznacen())
					{
						this->TextBoxovi.at(i).Clear();
					}
				}
			}
			break;

		case sf::Event::MouseMoved://kada se mis krece
			this->ProvjeriHoverZaSveElemente();
			break;

		case sf::Event::MouseButtonPressed:
			this->ProvjeriClickZaSveElemente();	
			break;

		case sf::Event::MouseButtonReleased:
			this->ResetPrimarneBoje();
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

	this->RenderSveElemente();

	//--------ovdje zavrsava pozivanje metoda koje iscrtavaju elemente-------

	this->window->display(); //ovo je indikator da je frame zavrsen sa crtanjem
    //izmedju window.clear() i window.display() crtamo prozor tj. elemente unutar prozora
}

const bool AplikacijaGUI::getWindowIsOpen() const //metoda koja vraca da li je prozor otvoren
{
	return this->window->isOpen();
}