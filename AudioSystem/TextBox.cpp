#include "TextBox.h"

//----------------------Private metode---------------------------

void TextBox::InputLogika(int karakterIstipkan)
{
	if (karakterIstipkan != DELETE_KEY && karakterIstipkan != ENTER_KEY && karakterIstipkan != ESCAPE_KEY)
	{
		this->text << static_cast<char>(karakterIstipkan);//ako karakter nije ni jedan od specijalnih onda ce upisat  
	}
	else if (karakterIstipkan == DELETE_KEY)
	{
		if (text.str().length() > 0)
		{
			this->IzbrisiZadnjiKarakter();
		}
	}
	this->textbox.setString(this->text.str() + "_");// _ predstavlja kao selektor ili prateci karakter dok korisnik kuca
}

void TextBox::IzbrisiZadnjiKarakter()
{
	std::string t = this->text.str();//smjesta string verziju texta u t
	std::string noviT = "";

	for (int i = 0; i < t.length() - 1; i++)//kopira vrijednost t u noviT bez zadnjeg karaktera
	{
		noviT += t[i];
	}

	this->text.str("");//brise staru vrijednost
	this->text << noviT;//smjesta novu vrijednost bez zadnjeg karaktera

	this->textbox.setString(this->text.str());//smjesta string verziju texta unutar sf vrijednosti textboxa koji ce se iscrtat
}



//------------------end Private metode---------------------------

void TextBox::SetTextBox(int velicina, sf::Color boja, bool oznacen)
{
	this->textbox.setCharacterSize(velicina);
	this->textbox.setFillColor(boja);
	this->jeOznacen = oznacen;
	if (oznacen)
	{
		this->textbox.setString("_");
	}
	else
	{
		this->textbox.setString("");
	}
}

void TextBox::SetFont(sf::Font& font)//posto sfml nema default fontova, moramo manuelno proslijedit font po referenci
{
	this->textbox.setFont(font);
}

void TextBox::SetPosition(sf::Vector2f pozicija)//postavlja poziciju, overrida zadnju
{
	this->textbox.setPosition(pozicija);
}

void TextBox::SetLimit(bool ImaIliNema)//da li ima limit karakatera ili nema
{
	this->imaLimit = ImaIliNema;
}

void TextBox::SetLimit(bool ImaIliNema, int Limit)//overloadana funkcija u kojoj se moze proslijediti limit
{
	this->imaLimit = ImaIliNema;
	this->Limit = Limit;
}

void TextBox::SetOznacen(bool oznacen)//radi selektora _ potrebno je reci korisniku kada je selektirano polje za unos
{
	this->jeOznacen = oznacen;
	if (!oznacen)
	{
		std::string t = this->text.str();//smjesta string verziju texta u t
		std::string noviT = "";

		for (int i = 0; i < t.length(); i++)//kopira vrijednost t u noviT bez zadnjeg karaktera
		{
			noviT += t[i];
		}
		this->textbox.setString(noviT);
	}
}

std::string TextBox::GetText()//vraca string koji je korisnik oktucao i submito
{
	return this->text.str();
}

void TextBox::DrawTo(sf::RenderWindow& window)//ovoj metodi proslijedjujemo target tj prozor na kojem zelimo da se
//izvrsi render textboxa
{
	window.draw(this->textbox);
}

void TextBox::OtipkanoNa(sf::Event input)//metoda koja vrsi logiku kucanja i spremanja texta
{
	if (this->jeOznacen)//provjerava da li je textbox oznacen
	{
		int karakterOtkucan = input.text.unicode; //sprema int ascii vrijednost unijetog karaktera
		if (karakterOtkucan < 128) //samo prima standardni unicode UTF-8
		{
			if (this->imaLimit)//ako ima limit broj karaktera
			{
				if (text.str().length() <= this->Limit)//ako je text manji od limita
				{
					this->InputLogika(karakterOtkucan);
				}
				else if (text.str().length() > this->Limit && karakterOtkucan == DELETE_KEY)
				{
					this->IzbrisiZadnjiKarakter();
				}
			}
			else
			{
				InputLogika(karakterOtkucan);
			}
		}
	}
}
