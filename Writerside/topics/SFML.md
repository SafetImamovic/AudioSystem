# SFML

## Šta je SFML?

**Simple and Fast Multimedia Library**  [Oficijalna Stranica](https://www.sfml-dev.org/)
je biblioteka koja pruža jednostavan interfejs za različite komponente računara, kako bi se olakšao razvoj 
igara i multimedijalnih aplikacija. 



<procedure title="Sastoji se od pet modula:" id="">
    <step><code>Sistem (System)</code></step>
    <step><code>Prozor (Window)</code></step>
    <step><code>Grafika (Graphics)</code></step>
    <step><code>Audio (Audio)</code></step>
    <step><code>Mreža (Network)</code></step>
</procedure>



## Zašto SFML?

Odlučeno je da se za projekat koristi **GUI** pristup umjesto Konzolnog pristupa jer omogučava kompleksnije i 
fleksibilnije korištenje aplikacije. Jedan od primjera je da aplikacija može biti interaktivna putem miša.

## Instalacija SFML
Instalacija SFML-a je opisana na [Oficijalnoj Stranici](https://www.sfml-dev.org/download/sfml/2.6.1/)
na kojoj je potrebno preuzeti odgovarajuću biblioteku za odgovarajući sistem. 
Pošto je za projekat odlučeno koristiti Visual Studio kao IDE, potrebno je preuzeti:
<shortcut>Visual C++ 17 (2022) - 64-bit SFML</shortcut>

> Zatim je potrebno otpakovati arhivu.


## Postavljanje SFML
Postupak postavljanja biblioteke za Visual Studio je detaljno opsian [Ovdje](https://www.sfml-dev.org/tutorials/2.6/start-vc.php)


<procedure title="Procedura Postavljanja" id="procedura_postavljanja">
    <step>Kao prvi korak potrebno je napraviti prazan ili konzolni C++ projekat u Visual Studio, 
odlučeno je napraviti prazan projekat u koji je dodan <shortcut>main.cpp</shortcut> file.</step>
    <step>Pošto su postavke i putanje jednake za <shortcut>Debug</shortcut> i <shortcut>Release</shortcut> označeno je <shortcut>All Configurations</shortcut> da se postave postavke globalno.</step>
    <step>
    <note>
    <p>
        Tokom postavke putanje je korišten Macro <shortcut>$(ProjectDir)\External</shortcut> jer omogučava fleksibilnost relokacije projekta.
    </p>
</note>
</step>
    <step>Za Release konfiguraciju je dodana <shortcut>SFML_STATIC</shortcut> preprocesor komanda:</step>
    <step>
        Nakon instalacije i postavljanja SFML može se testirati da li je korektno postavljena biblioteka tako što se pokreće kod koji otvara prozor i iscrtava zelenu kružnicu:

<code-block lang="c++">
    <![CDATA[

    #include <SFML/Graphics.hpp>

    int main()
    {
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
    
        return 0;
    }
    ]]>
</code-block>

</step>
</procedure>