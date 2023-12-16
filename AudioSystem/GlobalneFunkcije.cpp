#include "GlobalneFunkcije.h"

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