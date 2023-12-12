#include "AplikacijaGUI.h"
#include "muzikaTest.h"

int main()
{
    sf::Color PrimarnaBoja = sf::Color(30, 30, 30);
    sf::Color SekundarnaBoja = sf::Color(60, 60, 60);
    sf::Color AkcenatBoja = sf::Color::Red;

    sf::Font font;
    font.loadFromFile("seguisym.ttf");

    AplikacijaGUI AudioSystemGUI(font, PrimarnaBoja, SekundarnaBoja, AkcenatBoja);

    while (AudioSystemGUI.getWindowIsOpen()) //petlja u kojoj se odvijaju akcije aplikacije dok je prozor otvoren
    {
        //update
        AudioSystemGUI.UpdateGUI();

        //render
        AudioSystemGUI.RenderGUI();
    }


    //AudioPlayer player;
    //player.Pokreni();
    
    return 0;
}