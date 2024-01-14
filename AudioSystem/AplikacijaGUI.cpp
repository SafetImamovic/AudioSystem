#include "AplikacijaGUI.h"
#include <iostream>
#include "GlobalneFunkcije.h"
//----------------------private----------------------------------//

void AplikacijaGUI::MoveUp()
{
	sf::Vector2f moveRate(0, -40);

	if (this->IPRMain.size() == 0)
		return;

	if (this->IPRMain.at(this->IPRMain.size() - 1).GlavnaPozadina.getPosition().y > InfoPjesma::visinaWindow - 200)
	{
		for (int i = 0; i < this->IPRMain.size(); i++)
		{
			this->IPRMain.at(i).GlavnaPozadina.move(moveRate);

			this->IPRMain.at(i).ID_Cover_Ime_Pozadina.move(moveRate);

			this->IPRMain.at(i).ID.move(moveRate);
			this->IPRMain.at(i).CoverRender.move(moveRate);
			this->IPRMain.at(i).Ime.move(moveRate);

			this->IPRMain.at(i).Autor_Pozadina.move(moveRate);

			this->IPRMain.at(i).ImeAutora.move(moveRate);

			this->IPRMain.at(i).Trajanje_Add_Like_Pozadina.move(moveRate);

			this->IPRMain.at(i).TrajanjePjesme.move(moveRate);
			this->IPRMain.at(i).DodajPjesmuUPlaylist.move(moveRate);
			this->IPRMain.at(i).Like.move(moveRate);
		}
	}
}

void AplikacijaGUI::MoveDown()
{
	sf::Vector2f moveRate(0, 40);

	if (this->IPRMain.size() == 0)
		return;

	if (this->IPRMain.at(0).GlavnaPozadina.getPosition().y < 180)
	{
		for (int i = 0; i < this->IPRMain.size(); i++)
		{
			this->IPRMain.at(i).GlavnaPozadina.move(moveRate);
			this->IPRMain.at(i).ID_Cover_Ime_Pozadina.move(moveRate);
			this->IPRMain.at(i).ID.move(moveRate);
			this->IPRMain.at(i).CoverRender.move(moveRate);
			this->IPRMain.at(i).Ime.move(moveRate);
			this->IPRMain.at(i).Autor_Pozadina.move(moveRate);

			this->IPRMain.at(i).ImeAutora.move(moveRate);

			this->IPRMain.at(i).Trajanje_Add_Like_Pozadina.move(moveRate);
			this->IPRMain.at(i).TrajanjePjesme.move(moveRate);
			this->IPRMain.at(i).DodajPjesmuUPlaylist.move(moveRate);
			this->IPRMain.at(i).Like.move(moveRate);
		}
	}

}

void AplikacijaGUI::InicijalizacijaVarijabli()
{
	this->like = false;
	this->window = nullptr; //dobra praksa da se pointer inicijalizira sa nullptr. incicijalizirmao prozor kao pointer jer zelimo da ga alociramo na heap
	//i fleksibilnija je kontrola

	this->videoMode.height = 600; //visina prozora koja se smijesta unutar this->videoMode
	this->videoMode.width = 1920; //sirina prozora koja se smijesta unutar this->videoMode
	InfoPjesma::visinaWindow = this->videoMode.height;
	InfoPjesma::sirinaWindow = this->videoMode.width;

	PlayLista svePjesme("Sve Pjesme", "6.1.2024", true, true, "Moja Mama");
	this->pSvePjesme = &svePjesme;

	std::vector<Pjesma> pjesme = this->pSvePjesme->ucitajPjesmeIzDatoteke("PjesmeData.txt");
	this->pSvePjesme->setPjesme(pjesme);
	
	this->KreirajPlayListu("Sve Pjesme", "09.01.2024", false, false, "Me");
	this->KreirajPlayListu("Quest For Fire", "09.01.2024", false, false, "Me");
	this->KreirajPlayListu("Save Yourself", "09.01.2024", false, false, "Me");




	//-------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------
	this->PlayListe.at(1) + pjesme.at(20);
	this->PlayListe.at(1) + pjesme.at(54);
	this->PlayListe.at(1) + pjesme.at(55);
	this->PlayListe.at(1) + pjesme.at(56);
	this->PlayListe.at(1) + pjesme.at(14);
	this->PlayListe.at(1) + pjesme.at(57);
	
	this->PlayListe.at(1) + pjesme.at(58);
	this->PlayListe.at(1) + pjesme.at(59);
	this->PlayListe.at(1) + pjesme.at(60);
	this->PlayListe.at(1) + pjesme.at(61);
	this->PlayListe.at(1) + pjesme.at(62);
	this->PlayListe.at(1) + pjesme.at(63);
	this->PlayListe.at(1) + pjesme.at(64);
	this->PlayListe.at(1) + pjesme.at(65);

	//-------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------





	std::cout << "this->PlayListe.at(0).getPjesme().size(): " << this->PlayListe.at(0).getPjesme().size() << "\n";
	
	for (int i = 0; i < this->pSvePjesme->getPjesme().size(); i++)
	{
		this->PlayListe.at(0) + this->pSvePjesme->getPjesme().at(i);
	}
	
	std::cout << "this->PlayListe.at(0).getPjesme().size(): " << this->PlayListe.at(0).getPjesme().size() << "\n";
	std::cout << "Track: \n"; this->PlayListe.at(0).getPjesme().at(0).getInfo();


	this->LoadPjesmeRender(this->PlayListe.at(0).getPjesme());
	this->LoadPlaylisteRender();
	
	this->player.setNiz(this->PlayListe.at(0), 0.5f);

	//-----------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------

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
		this->fontBoldest,
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
		if (this->IPRMain.at(i).GlavnaPozadina.getPosition().y < this->videoMode.height - 160 
			&& this->IPRMain.at(i).GlavnaPozadina.getPosition().y > 160)
		{
			if (this->IPRMain.at(i).Hover(*this->window, this->IPRMain.at(i).GlavnaPozadina))
				this->IPRMain.at(i).PromijeniBojuPozadine(sf::Color::Black);
			else
				this->IPRMain.at(i).PromijeniBojuPozadine(sf::Color(10, 10, 10));
		}
	}

	for (int i = 0; i < this->PRMain.size(); i++)
	{
		if (this->PRMain.at(i).Hover(*this->window, this->PRMain.at(i).GlavnaPozadina))
			this->PRMain.at(i).GlavnaPozadina.setFillColor((sf::Color(10, 10, 10)));
		else
			this->PRMain.at(i).GlavnaPozadina.setFillColor((sf::Color::Black));
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
	else if (Tipka::PRITISNUT == "Like")
	{
		this->LikeTrackHook();
		std::cout << "Like!\n";
	}

	float tempp = this->kontrole.UpdatePozicijaSimbolaWindowGlasnoca(*this->window);

	float tempBrzina = this->kontrole.UpdatePozicijaSimbolaWindowPlaybackBrzina(*this->window);
	
	player.SetGlasnoca(tempp);
	//std::cout << tempp;
	//if(tempBrzina > 0 && tempBrzina < 1)// 0 -> 0.25 i 1 -> 2 => 2x + 0.25 1.75x + 0.25 
	//	player.setPitch(1.75 * tempBrzina + 0.25);

	std::cout << "Temp brzina: " << tempBrzina << "\n";
	player.setProcenatBrzine(tempBrzina);
	if (tempBrzina > 0 && tempBrzina <= 1.0/8 + (1.0 / 16))
	{
		player.setPitch(0.25f);
	}
	else if (tempBrzina > 1.0/8 + (1.0 / 16) && tempBrzina <= 2.0/8 + (1.0 / 16))
	{
		player.setPitch(0.5f);
	}
	else if (tempBrzina > 2.0/8 + (1.0 / 16) && tempBrzina <= 3.0 /8 + (1.0 / 16))
	{
		player.setPitch(0.75f);
	}
	else if (tempBrzina > 3.0 /8 + (1.0 / 16) && tempBrzina <= 4.0 /8 + (1.0 / 16))
	{
		player.setPitch(1.0f);
	}
	else if (tempBrzina > 4.0 / 8 + (1.0 / 16) && tempBrzina <= 5.0 / 8 + (1.0 / 16))
	{
		player.setPitch(1.25f);
	}
	else if (tempBrzina > 5.0 / 8 + (1.0 / 16) && tempBrzina <= 6.0 / 8 + (1.0 / 16))
	{
		player.setPitch(1.5f);
	}
	else if (tempBrzina > 6.0 / 8 + (1.0 / 16) && tempBrzina <= 7.0 / 8 + (1.0 / 16))
	{
		player.setPitch(1.75f);
	}
	else if (tempBrzina > 7.0 / 8 + (1.0 / 16) && tempBrzina <= 8.0 / 8)
	{
		player.setPitch(2.0f);
	}
		

	float temppp = this->kontrole.UpdatePozicijaSimbolaWindow(*this->window);
	//std::cout << temppp;

	if(temppp > 0 && temppp < 1)
		player.SetPozicija(temppp * this->player.GetTrajanjePjesme());
	

	this->UpdateGlasnocaBar();

	this->UpdatePlaybackBrzina();
	ProvjeriClickZaSveTipke(*this->window, InfoPjesma::Tipke, this->PrimarnaBoja, this->AkcenatBoja);

	for (int i = 0; i < this->IPRMain.size(); i++)
	{
		if (this->IPRMain.at(i).Hover(*this->window, this->IPRMain.at(i).GlavnaPozadina))
		{
			if (this->IPRMain.at(i).GlavnaPozadina.getPosition().y < this->videoMode.height - 160
				&& this->IPRMain.at(i).GlavnaPozadina.getPosition().y > 160)
			{
				this->IPRMain.at(i).PromijeniBojuPozadine(this->AkcenatBoja);
				//this->player.unesiIme(this->IPRMain.at(i).lokacijaPjesme);
				this->player.setTrenutniIndexPjesme(this->IPRMain.at(i).intID - 1);/////////
				//TREBA NAPRAVITI FUNKCIJU
				this->player.trenutnaPjesma();
				//std::cout << "Pozvana!\n";

				this->UpdateImePjesme();
			}
		}
		else
		{
			this->IPRMain.at(i).PromijeniBojuPozadine(sf::Color(10, 10, 10));

		}
	}

	for (int i = 0; i < this->PRMain.size(); i++)
	{
		if (this->PRMain.at(i).Hover(*this->window, this->PRMain.at(i).GlavnaPozadina))
		{
			this->PRMain.at(i).GlavnaPozadina.setFillColor(this->AkcenatBoja);
			if (InfoPjesma::Trenutna_Playlista != i)
				this->SwitchPlaylist(i);

				InfoPjesma::Trenutna_Playlista = i;
		}
		else
			this->PRMain.at(i).GlavnaPozadina.setFillColor((sf::Color::Black));
	}
}


void AplikacijaGUI::RenderSveElemente()
{
	InfoPjesma::RenderPjesma(*this->window);
	
	InfoPjesma::RenderDesno(*this->window);
	
	
	InfoPjesma::pozadinaPjesma.setSize(sf::Vector2f(InfoPjesma::VelicinaLijevo.x, this->videoMode.height));
	window->draw(InfoPjesma::pozadinaLista);
	for (InfoPjesma::InfoPjesmaRender& pjesma : this->IPRMain)
	{
		pjesma.Render(*this->window, "");
	}

	

	InfoPjesma::RenderList(*this->window);
	InfoPjesma::RenderListDesno(*this->window);
	
	for (InfoPjesma::InfoPlaylisteRender& playlista : this->PRMain)
	{
		playlista.Render(*this->window, "");
	}

	DrawToSveTipke(*this->window, InfoPjesma::Tipke);

	

	InfoPjesma::dimenzijeLista = sf::Vector2f(InfoPjesma::sirinaWindow - InfoPjesma::VelicinaLijevo.x - 300, InfoPjesma::visinaWindow - 60 - 50);
	InfoPjesma::pozicijaLista = sf::Vector2f(InfoPjesma::VelicinaLijevo.x, 0);

	InfoPjesma::pozadinaLista.setSize(InfoPjesma::dimenzijeLista);
	InfoPjesma::pozadinaLista.setPosition(InfoPjesma::pozicijaLista);

	


	//for (int i = 0; i < this->TextBoxovi.size(); i++)
	//{
	//	this->TextBoxovi.at(i).DrawTo(*this->window);
	//}
	
	

	this->kontrole.RenderPozadina(*this->window);
	DrawToSveTipke(*this->window, this->kontrole.Tipke);
	this->kontrole.RenderVrijeme(*this->window, this->player.GetSekunde(), this->player.GetTrajanjePjesme(), this->PrimarnaBoja);
	this->kontrole.RenderScroll(*this->window);
	this->kontrole.RenderGlasnoca(*this->window);
	this->kontrole.RenderPlaybackBrzina(*this->window);
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

	this->UpdatePlaybackBrzina();
}

void AplikacijaGUI::UpdateGlasnocaBar()
{
	float ProcenatGlasnoce = this->player.GetGlasnoca();
	//std::cout << "Glasnoca	" << this->player.GetGlasnoca() << "\n";
	//std::cout << "ProcenatGlasnoce   " << ProcenatGlasnoce << std::endl;
	this->kontrole.UpdatePozicijaSimbolaGlasnoca(ProcenatGlasnoce, *this->window);

}

void AplikacijaGUI::UpdatePlaybackBrzina()
{
	double ProcenatPlaybackBrzina = this->player.getProcenatBrzine();
	//std::cout << "FUnkcija: " << ProcenatPlaybackBrzina << "\n";
	this->kontrole.UpdatePozicijaSimbolaPlaybackBrzina(ProcenatPlaybackBrzina, this->player.getPitch());
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
	InfoPjesma::SetPjesma("Don't Get Too Close (Virtual Riot Remix)", "Knock2", this->font, this->fontBold, this->fontBoldest, this->fontEmoji);
	InfoPjesma::Cover.loadFromFile("Covers/Skrillex with Bobby Raps - Leave Me Like This.jpg");
	InfoPjesma::CoverRender.setTexture(InfoPjesma::Cover);
	std::vector<std::string> pjesmeZaSad;


	//for(int i = 0; i < 20; i++)
	//	pjesmeZaSad.push_back("nice");
	
	std::vector<Pjesma> Pjesme = this->pSvePjesme->getPjesme();
	Pjesme.resize(this->pSvePjesme->getPjesme().size());

	InfoPjesma::SetList(L"Sve Pjesme Trenutno u Bazi", L":P", Pjesme, false, *this->window);
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
	if (ProvjeriHoverRegija(*this->window, { 400, 200 }, sf::Vector2f(this->videoMode.width - InfoPjesma::VelicinaLijevo.x - 300, this->videoMode.height - 110)))
	{
		//std::cout << "Nice" << "\n";
		if (this->event.mouseWheel.delta == -1)
		{
			this->MoveUp();
		}
		else if (this->event.mouseWheel.delta == 1)
		{
			this->MoveDown();
		}
	}
	
		//std::cout << "X" << "\n";
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
	InfoPjesma::textNaslov.setString(this->player.getPjesmaObjekat().getImePjesme());
	InfoPjesma::Cover.loadFromFile(this->player.getPjesmaObjekat().getLokacijaSlike());
	InfoPjesma::textPjesnici.setString(this->player.getPjesmaObjekat().getImeAutora());
	InfoPjesma::textDatumObjave.setString(this->player.getPjesmaObjekat().getDatumObjave());
	InfoPjesma::textRecordLabel.setString(this->player.getPjesmaObjekat().getRecordLabel());

	if (this->player.DaLiJeNovaPjesma(this->player.GetImePjesmePath()))
	{
		//std::cout << "Called!" << std::endl;
		InfoPjesma::textNaslov.setPosition(
			InfoPjesma::PaddingHorizontal + 1,
			
			InfoPjesma::PaddingVertical + InfoPjesma::VelicinaLijevo.x

		);
		InfoPjesma::rateNaslov = -0.001;

		InfoPjesma::textPjesnici.setPosition(
			InfoPjesma::PaddingHorizontal + 1,
			InfoPjesma::pozicijaPjesma.y + InfoPjesma::PaddingVertical + InfoPjesma::VelicinaLijevo.x + 26 + 20
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
	//std::cout << this->videoMode.height << "\n";
	this->videoMode.height = vidljivaPovrsina.height;
	this->videoMode.width = vidljivaPovrsina.width;
	this->window->setView(sf::View(vidljivaPovrsina));
	this->kontrole.SetRezolucija(this->videoMode);
	//std::cout << this->videoMode.width << "\n";
	this->PromjenaRezolucijaStaticInfoPjesma();
	//InfoPjesma::CoverRender.setScale(0.8f, 0.8f);

}

void AplikacijaGUI::PromjenaRezolucijaStaticInfoPjesma()
{
	InfoPjesma::visinaWindow = this->videoMode.height;
	InfoPjesma::sirinaWindow = this->videoMode.width;
	for (int i = 0; i < this->IPRMain.size(); i++)
	{
		this->IPRMain.at(i).FixPozicija(400, this->videoMode.width - 400 - 300, i + 1);
	}

	for (int i = 0; i < this->PRMain.size(); i++)
	{
		this->PRMain.at(i).FixPozicija(this->videoMode.width - 300, 100, i + 1);
	}
		
	//InfoPjesma::VelicinaLijevo = sf::Vector2f(300, InfoPjesma::visinaWindow);
	//InfoPjesma::BaznaRezolucijaSlike = 300;
	
	//InfoPjesma::ResizeCenter();

}

void AplikacijaGUI::CreateShorcut()
{
	
}

//Metoda koja kreira playlistu, stavlja je na glavni vektor skoro svih playlisti i vraca index playliste u vektoru
int AplikacijaGUI::KreirajPlayListu(const std::string& ime, const std::string& datumKreiranja,
	bool ponoviSkupPjesama, bool shuffle, std::string kreator)
{
	PlayLista p(ime, datumKreiranja, ponoviSkupPjesama, shuffle, kreator);
	this->PlayListe.push_back(p);
	return this->PlayListe.size() - 1;
}

void AplikacijaGUI::LikeTrackHook()
{
	std::cout << "ovo oznacava like " << this->PlayListe.at(0).getPjesme().at(0).getDaLiJeLajkana() << "\n";

	if(this->PlayListe.at(0).getPjesme().at(0).getDaLiJeLajkana() == false)
		this->PlayListe.at(0).getPjesme().at(0).DaLiJeLajkana = true;
	else
		this->PlayListe.at(0).getPjesme().at(0).DaLiJeLajkana = false;

}

bool AplikacijaGUI::jeSubstring(const std::string& glavniString, const std::string& trazeniString)
{
	auto it = std::search(
		glavniString.begin(), glavniString.end(),
		trazeniString.begin(), trazeniString.end(),
		[](char ch1, char ch2) {
			return std::tolower(ch1) == std::tolower(ch2);
		}
	);

	return it != glavniString.end();
}

bool AplikacijaGUI::searchSong(const Pjesma& pjesma)
{
	//
	//std::cout << InfoPjesma::TextBoxovi.at(0).GetText() << "\n";
	//

	return AplikacijaGUI::jeSubstring(pjesma.getImePjesme(), InfoPjesma::TextBoxovi.at(0).GetText())
		|| AplikacijaGUI::jeSubstring(pjesma.getImeAutora(), InfoPjesma::TextBoxovi.at(0).GetText());
}

void AplikacijaGUI::LoadPjesmeRender(std::vector<Pjesma> &Pjesme)
{
	for (int i = 0; i < Pjesme.size(); i++)
	{
		InfoPjesma::InfoPjesmaRender temp;
		temp.SetInfoPjesmaRender(Pjesme.at(i), Pjesme.at(i).getLokacijaSlike(), this->font, this->fontBold, this->fontEmoji, i + 1);
		this->IPRMain.push_back(temp);
	}
	for (int i = 0; i < Pjesme.size(); i++)
		this->IPRMain.at(i).LoadCover();
}


void AplikacijaGUI::LoadPlaylisteRender()
{
	for (int i = 0; i < this->PlayListe.size(); i++)
	{
		InfoPjesma::InfoPlaylisteRender temp;
		temp.SetInfoPlaylisteRender(this->PlayListe.at(i), this->font, this->fontBold, i + 1);
		this->PRMain.push_back(temp);
	}
}


int AplikacijaGUI::BulkSearch()
{
	std::vector<Pjesma> Pjesme = this->PlayListe.at(InfoPjesma::Trenutna_Playlista).getPjesme();
	std::vector<Pjesma> PronadjenePjesme;

	Pjesme.resize(this->PlayListe.at(0).getPjesme().size());

	for (const auto& pjesma : Pjesme)
	{
		if (AplikacijaGUI::searchSong(pjesma))
			PronadjenePjesme.push_back(pjesma);
	}
	this->IPRMain.clear();
	for (const auto& pjesma : PronadjenePjesme)
	{
		
		std::cout << pjesma.getImePjesme() << ", " << pjesma.getImeAutora() << "\n";
	}
	this->LoadPjesmeRender(PronadjenePjesme);
	
	

	return 0;
}

void AplikacijaGUI::SwitchPlaylist(int index)
{
	InfoPjesma::textNaslovListe.setString(this->PlayListe.at(index).getIme());
	InfoPjesma::textKreatroListe.setString(this->PlayListe.at(index).getImeKreatora());
	std::vector<Pjesma> pjesme = this->PlayListe.at(index).getPjesme();

	pjesme.resize(this->PlayListe.at(index).getPjesme().size());
	std::cout << this->PRMain.at(index).intID << "\n";
	this->IPRMain.clear();
	this->LoadPjesmeRender(pjesme);
}

//------------------end of private-------------------------------//

AplikacijaGUI::AplikacijaGUI(sf::Font& font, sf::Font& fontBold, sf::Font& fontBoldest, sf::Font& fontEmoji, sf::Color PrimarnaBoja, sf::Color SekundarnaBoja, sf::Color AkcenatBoja)
//konstruktor poziva privatne metode koje inicijaliziraju varijable i prozor
{
	this->font = font;
	this->fontBold = fontBold;
	this->fontBoldest = fontBoldest;
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
			{
				this->BulkSearch();
			}

			if (this->event.key.code == sf::Keyboard::Tab)
			{
				InfoPjesma::TextBoxovi.at(0).SetOznacen(true);
				TextBox::JE_OZNACEN = true;
				
			}
				
				
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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					this->MoveUp();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					this->MoveDown();
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


	this->UpdatePlaybackBrzina();

	
	this->UpdateStanjeTipke();
	this->Scroll();
	this->UpdateImePjesme();
	//--------------------------------------------
	this->kontrole.PromijeniLikeTipku(this->PlayListe.at(0).getPjesme().at(0).getDaLiJeLajkana());
	
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