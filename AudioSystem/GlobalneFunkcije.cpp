#include "GlobalneFunkcije.h"

bool ProvjeriHoverRegija(sf::RenderWindow& window, sf::Vector2f offset, sf::Vector2f regija)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float tipkaPosX = offset.x;
	float tipkaPosY = offset.y;

	float tipkaXPosSirina = regija.x + offset.x;
	float tipkaYPosVisina = regija.y;

	if (mouseX < tipkaXPosSirina && mouseX > tipkaPosX && mouseY < tipkaYPosVisina && mouseY > tipkaPosY)
		return true;
	return false;
}

void DrawToSviTextBoxovi(sf::RenderWindow& window, std::vector<TextBox>& TextBoxovi)
{
	for (int i = 0; i < TextBoxovi.size(); i++)
		TextBoxovi.at(i).DrawTo(window);
}

bool ProvjeriClickZaSveTextBoxove(sf::RenderWindow& window, std::vector<TextBox>& TextBoxovi, sf::Color PrimarnaBoja, sf::Color AkcenatBoja)
{
	for (int i = 0; i < TextBoxovi.size(); i++)
	{
		if (TextBoxovi.at(i).Hover(window, TextBoxovi.at(i).backgroundShape))
		{
			TextBoxovi.at(i).SetOznacen(true);
			return true;
		}
		else
		{
			TextBoxovi.at(i).SetOznacen(false);
			return false;
		}
	}
}

void ResetPrimarneBojeSviTextBoxovi(sf::RenderWindow& window, std::vector<TextBox>& TextBoxovi, sf::Color PrimarnaBoja)
{
	for (int i = 0; i < TextBoxovi.size(); i++)
	{
		TextBoxovi.at(i).PromijeniBojuPozadine(PrimarnaBoja);
	}
}

void ProvjeriHoverZaSveTextBoxove(sf::RenderWindow& window, std::vector<TextBox>& TextBoxovi, sf::Color PrimarnaBoja, sf::Color SekundarnaBoja)
{
	for (int i = 0; i < TextBoxovi.size(); i++)
	{
		if (TextBoxovi.at(i).Hover(window, TextBoxovi.at(i).backgroundShape))
		{
			TextBoxovi.at(i).backgroundShape.setFillColor(SekundarnaBoja);
		}
		else
		{
			TextBoxovi.at(i).backgroundShape.setFillColor(PrimarnaBoja);
		}
	}
}



void DrawToSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke)
//iscrtava na prozor
{
	for (int i = 0; i < Tipke.size(); i++)
		Tipke.at(i).DrawTo(window);
}



std::string ProvjeriClickZaSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja, sf::Color AkcenatBoja)
{
	bool hover = false;
	for (int i = 0; i < Tipke.size(); i++)
	{
		if (Tipke.at(i).Hover(window, Tipke.at(i).tipka))
		{
			hover = true;
			Tipke.at(i).PromijeniBojuPozadine(AkcenatBoja);
			Tipka::PRITISNUT = Tipke.at(i).GetID();
		}
		else
		{
			Tipke.at(i).PromijeniBojuPozadine(PrimarnaBoja);
		}
	}
	if (hover == false)
		Tipka::PRITISNUT = "";

	return "";
}

void ResetPrimarneBojeSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja)
{
	for (int i = 0; i < Tipke.size(); i++)
	{
		Tipke.at(i).PromijeniBojuPozadine(PrimarnaBoja);
	}
}

void ProvjeriHoverZaSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja ,sf::Color SekundarnaBoja)
{
	for (int i = 0; i < Tipke.size(); i++)
	{
		if (Tipke.at(i).Hover(window, Tipke.at(i).tipka))
		{
			Tipke.at(i).tipka.setFillColor(SekundarnaBoja);
		}
		else
		{
			Tipke.at(i).tipka.setFillColor(PrimarnaBoja);
		}
	}
}

std::string formatTime(int seconds) {
	int hours = seconds / 3600;
	int minutes = (seconds % 3600) / 60;
	int remainingSeconds = seconds % 60;

	std::ostringstream formattedTime;
	formattedTime << std::setfill('0') << std::setw(2) << hours << ":"
		<< std::setfill('0') << std::setw(2) << minutes << ":"
		<< std::setfill('0') << std::setw(2) << remainingSeconds;

	return formattedTime.str();
}