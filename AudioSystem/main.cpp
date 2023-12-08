#include <SFML/Graphics.hpp>
#include "muzikaTest.h"
int main()
{
    AudioPlayer player;
    player.Pokreni();
    
    /*
    sf::Music music;

    // Postavite putanju do zvuènog fajla
    const std::string filePath = "Breskvica-Dogolekoze";

    // Uèitajte zvuèni fajl
    if (!music.openFromFile(filePath)) {
        std::cerr << "Error opening sound file." << std::endl;
        return 1;
    }

    // Postavite vreme reprodukcije u sekundama
    float startTimeInSeconds = 10.0f;
    music.setPlayingOffset(sf::seconds(startTimeInSeconds));

    // Reprodukcija zvuka
    music.play();

    // Saèekajte dok se reprodukcija ne završi
    while (music.getStatus() == sf::Music::Playing) {
        sf::sleep(sf::milliseconds(100));
    }

    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    */
    return 0;
}