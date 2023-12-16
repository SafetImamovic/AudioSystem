#include "GlobalneFunkcije.h"

void DrawToSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke)
//iscrtava na prozor
{
	for (int i = 0; i < Tipke.size(); i++)
		Tipke.at(i).DrawTo(window);
}

std::string ProvjeriClickZaSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja, sf::Color AkcenatBoja)
{
	for (int i = 0; i < Tipke.size(); i++)
	{
		if (Tipke.at(i).Hover(window, Tipke.at(i).tipka))
		{
			Tipke.at(i).PromijeniBojuPozadine(AkcenatBoja);
			return Tipke.at(i).GetID();
		}
		else
		{
			Tipke.at(i).PromijeniBojuPozadine(PrimarnaBoja);
		}
	}
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
