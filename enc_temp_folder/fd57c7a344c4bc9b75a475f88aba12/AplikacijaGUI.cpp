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
	

	this->PostaviNizPjesmi();
	this->player.SetGlasnoca(1);
	this->InfoPjesmaKonfiguracija();
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
		this->fontEmoji,
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
	
	ProvjeriHoverZaSveTipke(*this->window, InfoPjesma::Tipke, this->PrimarnaBoja, this->SekundarnaBoja);

	ProvjeriHoverZaSveTextBoxove(*this->window, InfoPjesma::TextBoxovi, this->PrimarnaBoja, this->SekundarnaBoja);
	
}

void AplikacijaGUI::ProvjeriClickZaSveElemente()
{
	
	ProvjeriClickZaSveTipke(*this->window, InfoPjesma::Tipke, this->PrimarnaBoja, this->SekundarnaBoja);

	std::string temp = ProvjeriClickZaSveTipke(*this->window, this->kontrole.Tipke, this->PrimarnaBoja, this->AkcenatBoja);

	TextBox::JE_OZNACEN = ProvjeriClickZaSveTextBoxove(*this->window, InfoPjesma::TextBoxovi, this->PrimarnaBoja, this->AkcenatBoja);

	if (Tipka::PRITISNUT == "PustiPauziraj")//ovdje se za sad pozivaju sve audio funkcije
	{
		player.pustiPauza();
	}
	else if (Tipka::PRITISNUT == "SkipPrije")
		player.premotajUnazad();
	else if (Tipka::PRITISNUT == "SkipNaprijed")
		player.premotajUnaprijed();
	else if (Tipka::PRITISNUT == "Prije")
		player.staraPjesma();
	else if (Tipka::PRITISNUT == "Poslije")
		player.novaPjesma();
	else if (Tipka::PRITISNUT == "Mute")
	{
		this->Mute();
	}
		

	float tempp = this->kontrole.UpdatePozicijaSimbolaWindowGlasnoca(*this->window);
	
	player.SetGlasnoca(tempp);
	//std::cout << tempp;

	float temppp = this->kontrole.UpdatePozicijaSimbolaWindow(*this->window);
	//std::cout << temppp;

	if(temppp > 0 && temppp < 1)
		player.SetPozicija(temppp * this->player.GetTrajanjePjesme());
	

	this->UpdateGlasnocaBar();
	ProvjeriClickZaSveTipke(*this->window, InfoPjesma::Tipke, this->PrimarnaBoja, this->AkcenatBoja);
}

void AplikacijaGUI::RenderSveElemente()
{
	InfoPjesma::RenderPjesma(*this->window);
	InfoPjesma::RenderList(*this->window);
	InfoPjesma::RenderDesno(*this->window);
	InfoPjesma::RenderListDesno(*this->window);
	DrawToSveTipke(*this->window, InfoPjesma::Tipke);
	//for (int i = 0; i < this->TextBoxovi.size(); i++)
	//{
	//	this->TextBoxovi.at(i).DrawTo(*this->window);
	//}
	

	this->kontrole.RenderPozadina(*this->window);
	DrawToSveTipke(*this->window, this->kontrole.Tipke);
	this->kontrole.RenderVrijeme(*this->window, this->player.GetSekunde(), this->player.GetTrajanjePjesme(), this->PrimarnaBoja);
	this->kontrole.RenderScroll(*this->window);
	this->kontrole.RenderGlasnoca(*this->window);
	DrawToSviTextBoxovi(*this->window, InfoPjesma::TextBoxovi);
	
}

void AplikacijaGUI::ResetPrimarneBoje()
{
	ResetPrimarneBojeSveTipke(*this->window, this->kontrole.Tipke, this->PrimarnaBoja);
	ResetPrimarneBojeSveTipke(*this->window, InfoPjesma::Tipke, this->PrimarnaBoja);
	ResetPrimarneBojeSviTextBoxovi(*this->window, InfoPjesma::TextBoxovi, this->PrimarnaBoja);
}

void AplikacijaGUI::GetOdgovarajuciTextBoxText()
{
	for (int i = 0; i < this->TextBoxovi.size(); i++)
	{
		if (this->TextBoxovi.at(i).JeOznacen())
		{
			//std::cout << this->TextBoxovi.at(i).GetText() << std::endl;//getText metoda vraca string koji je korinsik otkucao u textbox
		}
		
	}
	
}

void AplikacijaGUI::UpdateScrollBar()
{
	float ProcenatPjesme = (static_cast<float>(player.GetMiliSekunde()) / 1000) / player.GetTrajanjePjesme();
	//std::cout << "Procenat Pjesme\t" << ProcenatPjesme << "\n";
	//std::cout << player.GetMiliSekunde() << std::endl;
	//std::cout << ProcenatPjesme << "%" << std::endl;
	if (ProcenatPjesme == 0)
		return;
	this->kontrole.UpdatePozicijaSimbola(ProcenatPjesme);
}

void AplikacijaGUI::UpdateGlasnocaBar()
{
	float ProcenatGlasnoce = this->player.GetGlasnoca();
	//std::cout << "Glasnoca	" << this->player.GetGlasnoca() << "\n";
	//std::cout << "ProcenatGlasnoce   " << ProcenatGlasnoce << std::endl;
	this->kontrole.UpdatePozicijaSimbolaGlasnoca(ProcenatGlasnoce, *this->window);
}

void AplikacijaGUI::PromijeniRezoluciju(int height, int width)
{
	sf::VideoMode newVid(1920, 1080);
	this->window->create(newVid, "Audio System", sf::Style::Close | sf::Style::Titlebar);
}

void AplikacijaGUI::Mute()
{
	if (this->player.GetGlasnoca() < 0 || this->player.GetGlasnoca() > 1)
		return;

	if (this->player.GetGlasnoca() != 0)
	{
		this->TempGlasnoca = this->player.GetGlasnoca();
		//std::cout << this->TempGlasnoca << std::endl;

		this->player.SetGlasnoca(0.00);
		this->kontrole.UpdatePozicijaSimbolaGlasnoca(0, *this->window);
	}
	else
	{
		//std::cout << "Jest jednaka nuli\n";
		this->player.SetGlasnoca(this->TempGlasnoca);
		this->kontrole.UpdatePozicijaSimbolaGlasnoca(this->TempGlasnoca, *this->window);
	}
}

void AplikacijaGUI::InfoPjesmaKonfiguracija()
{
	InfoPjesma::SetPjesma("Don't Get Too Close (Virtual Riot Remix)", "Skrillex & Bibi Bourelly & Sonny Moore & Virtual Riot", this->font, this->fontEmoji);
	InfoPjesma::Cover.loadFromFile("Covers/Skrillex, Bibi Bourelly, & Sonny Moore - Don't Get Too Close (Virtual Riot Remix).jpg");
	InfoPjesma::CoverRender.setTexture(InfoPjesma::Cover);
	std::vector<std::string> pjesmeZaSad;


	for(int i = 0; i < 20; i++)
		pjesmeZaSad.push_back("nice");
	

	InfoPjesma::SetList("Naslov Liste", "Kreator Liste", pjesmeZaSad, false, *this->window);
	InfoPjesma::PostaviPozadineDesno();
	InfoPjesma::SetListeDesno(pjesmeZaSad, *this->window);

}

void AplikacijaGUI::UpdateInfoPjesma()
{
	InfoPjesma::Update();
}

void AplikacijaGUI::UpdateStanjeTipke()
{
	if (this->player.GetMiliSekunde() == 0)//cudan nacin mora se promijenit
		this->kontrole.PromijeniKarakter("PustiPauziraj", L"\uE768");
	else
		this->kontrole.PromijeniKarakter("PustiPauziraj", L"\uE769");

	if (this->player.GetGlasnoca() == 0)
		this->kontrole.PromijeniKarakter("Mute", L"\uE74F");
	else
		this->kontrole.PromijeniKarakter("Mute", L"\uE767"); // E006

	//uslov za like dole
}

void AplikacijaGUI::UpdateOtipkano()
{
	for (int i = 0; i < this->TextBoxovi.size(); i++)
	{
		this->TextBoxovi.at(i).OtipkanoNa(this->event);//kada je tekst otkucan poziva metodu objekta za ovaj textbox
		//koja zapravo ispisuje tekst na prozoru
	}

	for (int i = 0; i < InfoPjesma::TextBoxovi.size(); i++)
	{
		InfoPjesma::TextBoxovi.at(i).OtipkanoNa(this->event);//kada je tekst otkucan poziva metodu objekta za ovaj textbox
		//koja zapravo ispisuje tekst na prozoru
	}
}

void AplikacijaGUI::LCtrlObrisi()
{
	for (int i = 0; i < this->TextBoxovi.size(); i++)
	{
		if (this->TextBoxovi.at(i).JeOznacen())
		{
			this->TextBoxovi.at(i).Clear();
		}
	}

	for (int i = 0; i < InfoPjesma::TextBoxovi.size(); i++)
	{
		if (InfoPjesma::TextBoxovi.at(i).JeOznacen())
		{
			InfoPjesma::TextBoxovi.at(i).Clear();
		}
	}
}

void AplikacijaGUI::Scroll()
{
	if (ProvjeriHoverRegija(*this->window, { 500, 220 }, sf::Vector2f(1920 - 500 - 300, this->videoMode.height - 110)))
	{
		if (this->event.mouseWheel.delta == -1)
		{
			InfoPjesma::MoveUp("Pjesme");
		}
		else if (this->event.mouseWheel.delta == 1)
		{
			InfoPjesma::MoveDown("Pjesme");
		}
	}

	if (ProvjeriHoverRegija(*this->window, sf::Vector2f(1920 - 300, 0), sf::Vector2f(300, this->videoMode.height - 110)))
	{
		if (this->event.mouseWheel.delta == -1)
		{
			InfoPjesma::MoveUp("Playliste");
		}
		else if (this->event.mouseWheel.delta == 1)
		{
			InfoPjesma::MoveDown("Playliste");
		}
	}
}

void AplikacijaGUI::PostaviNizPjesmi()//test
{
	this->NizPjesmi.push_back("Pjesme/Akon - SmackThat.wav");
	this->NizPjesmi.push_back("Pjesme/Skrillex, Starrah & Four Tet - Butterflies.wav");
	this->NizPjesmi.push_back("Pjesme/Dead Man Walking.wav");
	this->NizPjesmi.push_back("Pjesme/Dua Lipa - New Rules.wav");
	this->NizPjesmi.push_back("Pjesme/Skrillex - Fuji Opener (feat. Alvin Risk).wav");
	this->NizPjesmi.push_back("Pjesme/Skrillex & Boys Noize - Fine Day Anthem.wav");
	this->NizPjesmi.push_back("Pjesme/Skrillex, Bibi Bourelly, & Sonny Moore - Don't Get Too Close (Virtual Riot Remix).wav");
	this->NizPjesmi.push_back("Pjesme/Virtual Riot - Back In Time ft. Angelika.wav");
	this->NizPjesmi.push_back("Pjesme/Zomboy & MUST DIE! - Last One Standing.wav");
	this->player.setNiz(this->NizPjesmi);
}

void AplikacijaGUI::UpdateImePjesme()
{
	//std::cout << this->player.GetImePjesmePath() << std::endl;
	std::string temp = this->player.GetImePjesmePath();
	temp.erase(temp.begin(), temp.begin() + 7);//skida prvih 7 karaktera stringa to je direktorija Pjesme/
	InfoPjesma::textNaslov.setString(temp);
	//std::cout << this->player.DaLiJeNovaPjesma(this->player.GetImePjesmePath()) << "\n";

	if (this->player.DaLiJeNovaPjesma(this->player.GetImePjesmePath()))//TREBA PROMIJENIT tako da ima funkcija koja vraca da li je nova pjesma pustena
	{
		std::cout << "Called!" << std::endl;
		InfoPjesma::textNaslov.setPosition(
			InfoPjesma::PaddingHorizontal + 1,
			
			InfoPjesma::PaddingVertical + 500
		);
		InfoPjesma::rateNaslov = -0.001;
	}
}



//------------------end of private-------------------------------//

AplikacijaGUI::AplikacijaGUI(sf::Font& font, sf::Font& fontEmoji, sf::Color PrimarnaBoja, sf::Color SekundarnaBoja, sf::Color AkcenatBoja)
//konstruktor poziva privatne metode koje inicijaliziraju varijable i prozor
{
	this->font = font;
	this->fontEmoji = fontEmoji;
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
			this->UpdateOtipkano();
			
			break;

		case sf::Event::KeyPressed:

			//std::cout << InfoPjesma::TextBoxovi.at(0).GetText() << std::endl;

			if (this->event.key.code == sf::Keyboard::Enter) //Kada korisnik pritisne enter
				this->GetOdgovarajuciTextBoxText();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
				//Poseban slucaj ako korisnik u isto vrijme pritisne ctrl i backspace onda se obrise string unutar textboxa
				this->LCtrlObrisi();
			}
			
			if (TextBox::JE_OZNACEN == false)
			{
				if (this->event.key.code == sf::Keyboard::Space)
					this->player.pustiPauza();

				if (this->event.key.code == sf::Keyboard::Right)
					this->player.premotajUnaprijed();
				if (this->event.key.code == sf::Keyboard::Left)
					this->player.premotajUnazad();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					this->player.Pojacaj(1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					this->player.Smanji();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::M))
					this->Mute();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					this->player.staraPjesma();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					this->player.novaPjesma();
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

		case sf::Event::MouseWheelMoved:
			this->Scroll();
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
	this->UpdateInfoPjesma();
	this->UpdateRect();
	this->UpdateScrollBar();
	this->UpdateGlasnocaBar();
	this->UpdateStanjeTipke();
	this->Scroll();
	this->UpdateImePjesme();
	
}

void AplikacijaGUI::RenderRect()
{
	this->window->draw(this->rect);
}

void AplikacijaGUI::RenderGUI() //renderuje objekte, elemente aplikacije
{
	this->window->clear(sf::Color(30, 30, 30)); //clear-a stari frame

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