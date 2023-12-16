#include "AplikacijaGUI.h"
#include "muzikaTest.h"
#include <SFML/Graphics.hpp>

int main()
{
    AudioPlayer player;
    player.Pokreni();
    
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

/*
    sf::Music music;

    // Postavite putanju do zvučnog fajla
    const std::string filePath = "Breskvica-Dogolekoze.wav";

    // Učitajte zvučni fajl
    if (!music.openFromFile(filePath)) {
        std::cerr << "Error opening sound file." << std::endl;
        return 1;
    }

    // Postavite vreme reprodukcije u sekundama
    float startTimeInSeconds = 10.0f;
    music.setPlayingOffset(sf::seconds(startTimeInSeconds));

    // Reprodukcija zvuka
    music.play();

    // Sačekajte dok se reprodukcija ne završi
    while (music.getStatus() == sf::Music::Playing) {
        sf::sleep(sf::milliseconds(100));
    }

    /*
    // Saèekajte dok se reprodukcija ne završi
    while (music.getStatus() == sf::Music::Playing) {
        sf::sleep(sf::milliseconds(100));
    }

    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    while (AudioSystemGUI.getWindowIsOpen()) //petlja u kojoj se odvijaju akcije aplikacije dok je prozor otvoren
    {
        //update
        AudioSystemGUI.UpdateGUI();

        //render
        AudioSystemGUI.RenderGUI();
    }
    
    */
    //return 0;
//}
