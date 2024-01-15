# Enumeracija

SFML koristi svoje vec ugrađene enumeracije kako bi oznacio razlicite vrste dogadaja,
tipova fonda, i drugih atributa.

Jedan od primjera je **sf::Font::Style** koji se koristi za odeđivanje fonta:

<code-block lang="c++">
sf::Font font;
font.loadFromFile("font.ttf");

sf::Text text;
text.setFont(font);
text.setStyle(sf::Text::Bold);

</code-block>


Jos jedan od primjera bi bio **sf::Event** koji se bavi eventovima na GUI:

<code-block lang="c++">
while (window.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::Closed:
        //Primjer zatvaranja
    break;
    case sf::Event::KeyPressed:
        // Pritisnuta je tipka na tipkovnici
    break;
    }
}
</code-block>
