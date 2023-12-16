#include "AplikacijaGUI.h"
#include <iostream>
#include "GlobalneFunkcije.h"
//----------------------private----------------------------------//

void AplikacijaGUI::InicijalizacijaVarijabli()
{
	this->window = nullptr; //dobra praksa da se pointer inicijalizira sa nullptr. incicijalizirmao prozor kao pointer jer zelimo da ga alociramo na heap
	//i fleksibilnija je kontrola

	this->videoMode.height = 1000; //visina prozora koja se smijesta unutar this->videoMode
	this->videoMode.width = 1920; //sirina prozora koja se smijesta unutar this->videoMode

	this->player.setNiz();

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
	kontrole.SetKontrole(
		this->videoMode, 
		this->font,
		this->PrimarnaBoja,
		this->SekundarnaBoja,
		this->AkcenatBoja
	);

	this->rect.setSize(sf::Vector2f(100.f, 100.f));
	this->rect.setFillColor(sf::Color::Cyan);

	TextBox textbox1, textbox2;
	textbox1.SetSve(
		"Prvi",
		20,
		sf::Color::White,
		PrimarnaBoja,
		false,
		this->font,
		sf::Vector2f(200, 50),
		sf::Vector2f(20, 15),
		sf::Vector2f(1000, 50)
	);

	textbox2.SetSve(
		"Drugi",
		20,
		sf::Color::White, 
		PrimarnaBoja, 
		false, 
		this->font, 
		sf::Vector2f(200, 250), 
		sf::Vector2f(20, 15), 
		sf::Vector2f(1000, 50)
	);

	
	//void Tipka::SetTipka(std::wstring text, sf::Vector2f velicina, int karakterVelicina, sf::Color bojaText, sf::Color bojaPozadine, sf::Font & font)
	
	//L ispred string-a je wstring koji podrzava UTF-16 karaktere, ima funkcija u Tipka klasi u vezi ovoga "SetTextUTF16(std::wstring text)"

	

	//TipkaPoslije.SetTipka(L"▷▷", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, {580, 600}, {6, 10});
	//TipkaPrije.SetTipka(L"◁◁", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, { 500, 600 }, { 4, 10 });
	//TipkaPustiPauziraj.SetTipka(L"▶◼", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, { 540, 600 }, { 4, 10 });
	//TipkaLoop.SetTipka(L"⟳", { 40, 40 }, 24, sf::Color::White, this->PrimarnaBoja, this->font, { 620, 600 }, { 9, 3 });

	this->TextBoxovi.push_back(textbox1);
	this->TextBoxovi.push_back(textbox2);

	this->PromijeniRezolucijuToggleTEST.SetTipka(
		"Toggle_Rez",
		L"Toggle",
		sf::Vector2f(100, 100),
		20,
		sf::Color(255,255,255),
		this->PrimarnaBoja,
		this->font,
		{0,0},
		{0,0}
	);
	

	//IPAK JE NALBOLJA PRAKSA NAPRAVITI ODVOJENU KLASU ZA PLAYER!
}

void AplikacijaGUI::ProvjeriHoverZaSveElemente()
{
	ProvjeriHoverZaSveTipke(*this->window, this->kontrole.Tipke, this->PrimarnaBoja, this->SekundarnaBoja);
	
	for(int i = 0; i < this->TextBoxovi.size(); i++)
	{
		if (this->TextBoxovi.at(i).Hover(*this->window, this->TextBoxovi.at(i).backgroundShape))
		{
			this->TextBoxovi.at(i).backgroundShape.setFillColor(SekundarnaBoja);
		}
		else
		{
			this->TextBoxovi.at(i).backgroundShape.setFillColor(PrimarnaBoja);
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
	
	std::string temp = ProvjeriClickZaSveTipke(*this->window, this->kontrole.Tipke, this->PrimarnaBoja, this->AkcenatBoja);
	std::cout << Tipka::PRITISNUT << std::endl;

	if (Tipka::PRITISNUT == "PustiPauziraj")//ovdje se za sad pozivaju sve audio funkcije
		player.pustiPauza();
	else if (Tipka::PRITISNUT == "Prije")
		player.staraPjesma();
	else if (Tipka::PRITISNUT == "Poslije")
		player.novaPjesma();

	float tempp = this->kontrole.UpdatePozicijaSimbolaWindow(*this->window);
	std::cout << tempp;

	player.SetGlasnoca(tempp);

	bool hover = false;

	if (this->PromijeniRezolucijuToggleTEST.Hover(*this->window, PromijeniRezolucijuToggleTEST.tipka))
	{
		this->PromijeniRezolucijuToggleTEST.PromijeniBojuPozadine(AkcenatBoja);
		
		Tipka::PRITISNUT = PromijeniRezolucijuToggleTEST.GetID();
		std::cout << Tipka::PRITISNUT;
	}
	else
		this->PromijeniRezolucijuToggleTEST.PromijeniBojuPozadine(PrimarnaBoja);

	if (hover == false)
		Tipka::PRITISNUT = "";

	if (Tipka::PRITISNUT == "Toggle_Rez")
		this->PromijeniRezoluciju(1080, 1920);

}

void AplikacijaGUI::RenderSveElemente()
{
	for (int i = 0; i < this->TextBoxovi.size(); i++)
	{
		this->TextBoxovi.at(i).DrawTo(*this->window);
	}

	DrawToSveTipke(*this->window, this->kontrole.Tipke);
	this->kontrole.RenderScroll(*this->window);
	this->kontrole.RenderGlasnoca(*this->window);
}

void AplikacijaGUI::ResetPrimarneBoje()
{
	ResetPrimarneBojeSveTipke(*this->window, this->kontrole.Tipke, this->PrimarnaBoja);
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

void AplikacijaGUI::UpdateScrollBar()
{
	float ProcenatPjesme = player.GetSekunde() / player.GetTrajanjePjesme();
	//std::cout << ProcenatPjesme << "%" << std::endl;
	this->kontrole.UpdatePozicijaSimbola(ProcenatPjesme);
}

void AplikacijaGUI::PromijeniRezoluciju(int height, int width)
{
	sf::VideoMode newVid(1920, 1080);
	this->window->create(newVid, "Audio System", sf::Style::Close | sf::Style::Titlebar);
}



//------------------end of private-------------------------------//

AplikacijaGUI::AplikacijaGUI(sf::Font& font, sf::Color PrimarnaBoja, sf::Color SekundarnaBoja, sf::Color AkcenatBoja)
//konstruktor poziva privatne metode koje inicijaliziraju varijable i prozor
{
	this->font = font;
	this->PrimarnaBoja = PrimarnaBoja;
	this->SekundarnaBoja = SekundarnaBoja;
	this->AkcenatBoja = AkcenatBoja;
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
	this->UpdateScrollBar();
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
	this->PromijeniRezolucijuToggleTEST.DrawTo(*this->window);
	this->kontrole.RenderVrijeme(*this->window, this->player.GetSekunde(), this->player.GetTrajanjePjesme(), this->PrimarnaBoja);

	this->window->display(); //ovo je indikator da je frame zavrsen sa crtanjem
    //izmedju window.clear() i window.display() crtamo prozor tj. elemente unutar prozora
}

const bool AplikacijaGUI::getWindowIsOpen() const //metoda koja vraca da li je prozor otvoren
{
	return this->window->isOpen();
}