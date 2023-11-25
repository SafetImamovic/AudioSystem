#include "TextBox.h"

TextBox::TextBox(int velicina, sf::Color boja, bool oznacen)
{
	this->textbox.setCharacterSize(velicina);
	this->textbox.setColor(boja);
	this->jeOznacen = oznacen;
}
