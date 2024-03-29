#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "SoLoud/include/soloud.h"
#include "SoLoud/include/soloud_wav.h"
#include <iostream>

SoLoud::Soloud gSoloud; // SoLoud engine
SoLoud::Wav gWave;      // One wave file


int main()
{
    sf::Clock deltaClock;
    float dt;
    gSoloud.init();
    gWave.load("audio.ogg");
    gSoloud.play(gWave);
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::Texture texture1;
    sf::Texture texture2;
    texture1.loadFromFile("Skins/- mayu (orbs)/Orbs/note1.png");
    texture2.loadFromFile("Skins/- mayu (orbs)/Orbs/note2.png");
    window.setFramerateLimit(60);
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite sprite3;
    sf::Sprite sprite4;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    sprite3.setTexture(texture2);
    sprite4.setTexture(texture1);
    float velocity;
    sprite1.setPosition(0, 0);
    sprite2.setPosition(200, 0);
    sprite3.setPosition(400, 0);
    sprite4.setPosition(600, 0);
    while (window.isOpen())
    {
        dt = deltaClock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sprite1.getPosition().y > 800){
            sprite1.setPosition(0, 0);
            sprite2.setPosition(200, 0);
            sprite3.setPosition(400, 0);
            sprite4.setPosition(600, 0);
        }
        velocity = 800 * dt;
        window.clear(sf::Color::Black);
        sprite1.move(0, velocity);
        sprite2.move(0, velocity);
        sprite3.move(0, velocity);
        sprite4.move(0, velocity);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);
        window.display();
    }
    gSoloud.deinit();
    return 0;
}