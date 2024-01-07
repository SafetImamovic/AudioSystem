#include "AplikacijaGUI.h"
#include <iostream>
#include "GlobalneFunkcije.h"
//----------------------private----------------------------------//

void AplikacijaGUI::InicijalizacijaVarijabli()
{
	this->window = nullptr; //dobra praksa da se pointer inicijalizira sa nullptr. incicijalizirmao prozor kao pointer jer zelimo da ga alociramo na heap
	//i fleksibilnija je kontrola

	this->videoMode.height = 600; //visina prozora koja se smijesta unutar this->videoMode
	this->videoMode.width = 1920; //sirina prozora koja se smijesta unutar this->videoMode
	InfoPjesma::visinaWindow = this->videoMode.height;
	InfoPjesma::sirinaWindow = this->videoMode.width;

	
	this->CreateShorcut();

	PlayLista svePjesme("Sve Pjesme", "6.1.2024", true, true, "Moja Mama");
	this->pSvePjesme = &svePjesme;


	std::vector<Pjesma> pjesme = this->pSvePjesme->ucitajPjesmeIzDatoteke("PjesmeData.txt");
	this->pSvePjesme->setPjesme(pjesme);
	//for (const Pjesma& pjesma : pjesme)
	//{
	//	pjesma.getInfo();
	//}


	//this->IPR.SetInfoPjesmaRender(pjesme.at(0), this->font, this->fontEmoji);
	//this->IPR2.SetInfoPjesmaRender(pjesme.at(1), this->font, this->fontEmoji);


	for (const Pjesma& pjesma : pjesme)
	{
		InfoPjesma::InfoPjesmaRender temp;
		temp.SetInfoPjesmaRender(pjesma, pjesma.getLokacijaSlike(), this->font, this->fontEmoji);
		this->IPRMain.push_back(temp);
		
	}

	for(int i = 0; i < pjesme.size(); i++)
		this->IPRMain.at(i).LoadCover();
	
	


	this->player.setNiz(svePjesme, 0.5f);

	//this->PostaviNizPjesmi();

	
	this->InfoPjesmaKonfiguracija();

}

void AplikacijaGUI::InicijalizacijaProzora()
{
	this->window = new sf::RenderWindow(this->videoMode, "Audio System", sf::Style::Default);
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

	
	//void Tipka::SetTipka(std::wstring text, sf::Vector2f velicina, int karakterVelicina, sf::Color bojaText, sf::Color bojaPozadine, sf::Font & font)
	
	//L ispred string-a je wstring koji podrzava UTF-16 karaktere, ima funkcija u Tipka klasi u vezi ovoga "SetTextUTF16(std::wstring text)"

	

	//TipkaPoslije.SetTipka(L"▷▷", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, {580, 600}, {6, 10});
	//TipkaPrije.SetTipka(L"◁◁", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, { 500, 600 }, { 4, 10 });
	//TipkaPustiPauziraj.SetTipka(L"▶◼", { 40, 40 }, 16, sf::Color::White, this->PrimarnaBoja, this->font, { 540, 600 }, { 4, 10 });
	//TipkaLoop.SetTipka(L"⟳", { 40, 40 }, 24, sf::Color::White, this->PrimarnaBoja, this->font, { 620, 600 }, { 9, 3 });

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

	for (int i = 0; i < this->IPRMain.size(); i++)
	{
		if (this->IPRMain.at(i).Hover(*this->window, this->IPRMain.at(i).GlavnaPozadina))
			this->IPRMain.at(i).PromijeniBojuPozadine(sf::Color::Black);
		else
			this->IPRMain.at(i).PromijeniBojuPozadine(sf::Color(10,10,10));
	}
	
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

	for (int i = 0; i < this->IPRMain.size(); i++)
	{
		if (this->IPRMain.at(i).Hover(*this->window, this->IPRMain.at(i).GlavnaPozadina))
		{
			this->IPRMain.at(i).PromijeniBojuPozadine(this->AkcenatBoja);
			
			//this->player.unesiIme(this->IPRMain.at(i).lokacijaPjesme);
			this->player.setTrenutniIndexPjesme(this->IPRMain.at(i).intID - 1);
			//TREBA NAPRAVITI FUNKCIJU
			this->player.trenutnaPjesma();
			std::cout << "Pozvana!\n";
			
			this->UpdateImePjesme();
		}
		else
		{
			this->IPRMain.at(i).PromijeniBojuPozadine(sf::Color(10, 10, 10));

		}
	}
}

void AplikacijaGUI::RenderSveElemente()
{
	InfoPjesma::RenderPjesma(*this->window);
	InfoPjesma::RenderList(*this->window);
	InfoPjesma::RenderDesno(*this->window);
	InfoPjesma::RenderListDesno(*this->window);
	InfoPjesma::pozadinaPjesma.setSize(sf::Vector2f(InfoPjesma::VelicinaLijevo.x, this->videoMode.height));

	for (InfoPjesma::InfoPjesmaRender& pjesma : this->IPRMain)
	{
		pjesma.Render(*this->window, "");
	}

	InfoPjesma::dimenzijeLista = sf::Vector2f(InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300, InfoPjesma::visinaWindow - 60 - 50);
	InfoPjesma::pozicijaLista = sf::Vector2f(InfoPjesma::VelicinaLijevo.x, 0);

	InfoPjesma::pozadinaLista.setSize(InfoPjesma::dimenzijeLista);
	InfoPjesma::pozadinaLista.setPosition(InfoPjesma::pozicijaLista);

	InfoPjesma::CoverUpListaUp.setSize(sf::Vector2f(InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300, 220));
	InfoPjesma::CoverUpListaUp.setPosition(sf::Vector2f(InfoPjesma::VelicinaLijevo.x, 0));

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
	InfoPjesma::SetPjesma("Don't Get Too Close (Virtual Riot Remix)", "Knock2", this->font, this->fontEmoji);
	InfoPjesma::Cover.loadFromFile("Covers/Skrillex with Bobby Raps - Leave Me Like This.jpg");
	InfoPjesma::CoverRender.setTexture(InfoPjesma::Cover);
	std::vector<std::string> pjesmeZaSad;


	//for(int i = 0; i < 20; i++)
	//	pjesmeZaSad.push_back("nice");
	
	std::vector<Pjesma> Pjesme = this->pSvePjesme->getPjesme();
	Pjesme.resize(this->pSvePjesme->getPjesme().size());

	InfoPjesma::SetList("Naslov Liste", "Kreator Liste", Pjesme, false, *this->window);
	InfoPjesma::PostaviPozadineDesno();
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
	for (int i = 0; i < InfoPjesma::TextBoxovi.size(); i++)
	{
		InfoPjesma::TextBoxovi.at(i).OtipkanoNa(this->event);//kada je tekst otkucan poziva metodu objekta za ovaj textbox
		//koja zapravo ispisuje tekst na prozoru
	}
}

void AplikacijaGUI::LCtrlObrisi()
{


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
	if (ProvjeriHoverRegija(*this->window, { 500, 220 }, sf::Vector2f(this->videoMode.width - InfoPjesma::VelicinaLijevo.x - 300, this->videoMode.height - 110)))
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

	if (ProvjeriHoverRegija(*this->window, sf::Vector2f(this->videoMode.width - 300, 0), sf::Vector2f(300, this->videoMode.height - 110)))
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
	
	//for (Pjesma& pjesma : this->pSvePjesme->getPjesme())
	//{
	//	this->NizPjesmi.push_back(pjesma.getLokacijaPjesme());
	//	std::cout << "\"" << pjesma.getLokacijaPjesme() << "\"" << std::endl;
	//}

	
	
}

void AplikacijaGUI::UpdateImePjesme()
{
	InfoPjesma::textNaslov.setString(this->player.getPjesmaObjekat().getIme());
	InfoPjesma::Cover.loadFromFile(this->player.getPjesmaObjekat().getLokacijaSlike());
	InfoPjesma::textPjesnici.setString(this->player.getPjesmaObjekat().getImeAutora());


	if (this->player.DaLiJeNovaPjesma(this->player.GetImePjesmePath()))
	{
		std::cout << "Called!" << std::endl;
		InfoPjesma::textNaslov.setPosition(
			InfoPjesma::PaddingHorizontal + 1,
			
			InfoPjesma::PaddingVertical + InfoPjesma::VelicinaLijevo.x

		);
		InfoPjesma::rateNaslov = -0.001;

		InfoPjesma::textPjesnici.setPosition(
			InfoPjesma::PaddingHorizontal + 1,
			InfoPjesma::VelicinaLijevo.x + InfoPjesma::PaddingVertical + 20 + 20
		);
		InfoPjesma::ratePjesnici = -0.001;
	}
}

void AplikacijaGUI::ResizeWindowEvent()
{
	sf::FloatRect vidljivaPovrsina(
		0,
		0,
		this->event.size.width,
		this->event.size.height
	);
	this->videoMode.height = vidljivaPovrsina.height;
	this->videoMode.width = vidljivaPovrsina.width;
	this->window->setView(sf::View(vidljivaPovrsina));
	this->kontrole.SetRezolucija(this->videoMode);
	std::cout << this->videoMode.width << "\n";
	this->PromjenaRezolucijaStaticInfoPjesma();
	//InfoPjesma::CoverRender.setScale(0.8f, 0.8f);

}

void AplikacijaGUI::PromjenaRezolucijaStaticInfoPjesma()
{
	InfoPjesma::visinaWindow = this->videoMode.height;
	InfoPjesma::sirinaWindow = this->videoMode.width;
	for(int i = 0; i < this->IPRMain.size(); i++)
		this->IPRMain.at(i).FixPozicija(400, this->videoMode.width - 400 - 300);
	//InfoPjesma::VelicinaLijevo = sf::Vector2f(300, InfoPjesma::visinaWindow);
	//InfoPjesma::BaznaRezolucijaSlike = 300;
	
	//InfoPjesma::ResizeCenter();

}

void AplikacijaGUI::CreateShorcut()
{
	
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
				{
					this->player.pustiPauza();
					float tempp = this->kontrole.UpdatePozicijaSimbolaWindowGlasnoca(*this->window);
					player.SetGlasnoca(tempp);
				}
					

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
		case sf::Event::Resized:
			this->ResizeWindowEvent();
			this->kontrole.SetRezolucijaVrijeme(*this->window);
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
	
	
	//this->IPR.Render(*this->window);
	//this->IPR2.Render(*this->window);

	


	this->window->display(); //ovo je indikator da je frame zavrsen sa crtanjem
    //izmedju window.clear() i window.display() crtamo prozor tj. elemente unutar prozora
}

const bool AplikacijaGUI::getWindowIsOpen() const //metoda koja vraca da li je prozor otvoren
{
	return this->window->isOpen();
}