#include "AplikacijaGUI.h"
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