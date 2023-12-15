
#ifndef GLOBALNEFUNKCIJE_H
#define GLOBALNEFUNKCIJE_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Tipka.h"
#include <vector>

void DrawToSveTipke(sf::RenderWindow& window, std::vector<Tipka> &Tipke);
void ProvjeriClickZaSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja, sf::Color AkcenatBoja);
void ResetPrimarneBojeSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja);
void ProvjeriHoverZaSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja, sf::Color SekundarnaBoja);

#endif