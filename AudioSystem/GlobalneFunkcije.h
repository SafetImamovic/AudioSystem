
#ifndef GLOBALNEFUNKCIJE_H
#define GLOBALNEFUNKCIJE_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Tipka.h"
#include "TextBox.h"
#include <vector>
#include <sstream>
#include <iomanip>

bool ProvjeriHoverRegija(sf::RenderWindow& window, sf::Vector2f offset, sf::Vector2f regija);

void DrawToSviTextBoxovi(sf::RenderWindow& window, std::vector<TextBox>& TextBoxovi);
bool ProvjeriClickZaSveTextBoxove(sf::RenderWindow &window, std::vector<TextBox> &TextBoxovi, sf::Color PrimarnaBoja, sf::Color AkcenatBoja);
void ResetPrimarneBojeSviTextBoxovi(sf::RenderWindow& window, std::vector<TextBox>& TextBoxovi, sf::Color PrimarnaBoja);
void ProvjeriHoverZaSveTextBoxove(sf::RenderWindow& window, std::vector<TextBox>& TextBoxovi, sf::Color PrimarnaBoja, sf::Color SekundarnaBoja);

void DrawToSveTipke(sf::RenderWindow& window, std::vector<Tipka> &Tipke);
std::string ProvjeriClickZaSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja, sf::Color AkcenatBoja);
void ResetPrimarneBojeSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja);
void ProvjeriHoverZaSveTipke(sf::RenderWindow& window, std::vector<Tipka>& Tipke, sf::Color PrimarnaBoja, sf::Color SekundarnaBoja);

std::string formatTime(int seconds);

#endif