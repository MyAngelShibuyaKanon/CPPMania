#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "SoLoud/include/soloud.h"
#include "SoLoud/include/soloud_wav.h"
#include <string>
#include "note.h"
#include "note.cpp"
#include <iostream> 
#include <vector>
#include "musicHandler.h"
#include "musicHandler.cpp"


const double noteSpeedConst = 13720;
int songPosition;
int noteSpeed;
int keys;
int mainMusicHandle;
int HitPos = 436;
int screenHeight = 720;
int screenWidth = 1080;
int columnWidth = 132;
int playWidth = columnWidth * 4;
std::string SkinLocation = "Skins/- mayu (orbs)/";
sf::Texture maniaStageBorderText;
sf::Sprite maniaStageBorder;
sf::Texture maniaKeyText;
sf::Sprite maniaKey1;
sf::Sprite maniaKey2;
sf::Sprite maniaKey3;
sf::Sprite maniaKey4;
sf::Texture maniaKeyPressedText;
sf::Texture note1Text;
sf::Texture note2Text;
note note1;
note note2;
note note3;
note note4;
int lane1PosX = (screenWidth / 2) - (2 * columnWidth);
int lane2PosX = (screenWidth / 2) - (1 * columnWidth);
int lane3PosX = (screenWidth / 2);
int lane4PosX = (screenWidth / 2) + (1 * columnWidth);

void start_music(musicHandler &master){
    master.loadMusic("audio.ogg");
    master.playMusic();
    master.loadManiaSfx();
    master.playManiaSfx(0);
}

void load_textures(){
    maniaKeyText.loadFromFile(SkinLocation + "Orbs/key.png");
    maniaKeyPressedText.loadFromFile(SkinLocation + "Orbs/keyD.png");
    maniaKey1.setTexture(maniaKeyText);
    maniaKey2.setTexture(maniaKeyText);
    maniaKey3.setTexture(maniaKeyText);
    maniaKey4.setTexture(maniaKeyText);
    maniaKey1.setPosition(lane1PosX, HitPos);
    maniaKey2.setPosition(lane2PosX, HitPos);
    maniaKey3.setPosition(lane3PosX, HitPos);
    maniaKey4.setPosition(lane4PosX, HitPos);
    
}

int main(){
    std::vector<note> notes;
    note1Text.loadFromFile(SkinLocation + "Orbs/note8.png");
    note2Text.loadFromFile(SkinLocation + "Orbs/note2.png");
    musicHandler master;
    start_music(master);
    load_textures();
    sf::Clock deltaClock;
    float dt;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");
    float velocity;
    for (int i = 1; i < 5; i++){
        notes.push_back(note1);
        if (i == 2 || i == 3){
            notes.back().initNote(note2Text, 2000, i);
        }
        else{
            notes.back().initNote(note1Text, 2000, i);
        }
    }


    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(120);
    while (window.isOpen())
    {
        dt = deltaClock.restart().asSeconds();
        velocity = HitPos / ((noteSpeedConst / 28) / 1000) * dt;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.scancode == sf::Keyboard::Scan::A){
                    master.playManiaSfx(0);
                    }
                if (event.key.scancode == sf::Keyboard::Scan::S){
                    master.playManiaSfx(1);
                    }
                }
        }

        if (notes[0].getPosY() > screenHeight){
            for (int i = 0; i < 4; i++){
                notes[i].resetY();
            }
        }
        window.clear(sf::Color::Black);
        notes[0].move(0, velocity);
        notes[1].move(0, velocity);
        notes[2].move(0, velocity);
        notes[3].move(0, velocity);
        notes[0].render(window);
        notes[1].render(window);
        notes[2].render(window);
        notes[3].render(window);
        window.display();

    }
    return 0;
}

