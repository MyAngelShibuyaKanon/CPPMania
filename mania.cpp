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
#include <thread>
#include "map_parser.cpp"
#include <unistd.h>
#include "objectManager.h"
#include "objectManager.cpp"
#include "graphicsHandler.h"
#include "graphicsHandler.cpp"

const double noteSpeedConst = 11485;
int songPosition;
int noteSpeed;
int keys;
int mainMusicHandle;
int HitPos = 436;
int screenHeight = 720;
int screenWidth = 1080;
int columnWidth = 132;
int playWidth = columnWidth * 4;
float dt;
double playTime;
double velocity;
std::string beatmap = "a.osu";
std::string SkinLocation = "Skins/- mayu (orbs)/";
sf::Clock deltaClock;

int main(){

    //parse beatmap and objects
    objectManager objects;
    parseMap(objects);

    //setup graphics
    sf::RenderWindow maniaWindow(sf::VideoMode(screenWidth, screenHeight), "Gyahaha");
    maniaWindow.setFramerateLimit(60);
    maniaWindow.setKeyRepeatEnabled(false);
    objects.tempTexture.loadFromFile("/home/quertzy/Documents/GitHub/CppMania/note8.png");

    graphicsHandler fabulous;

    //audio stuff
    musicHandler composer;
    

    while (maniaWindow.isOpen()){

        sf::Event event;
        dt = deltaClock.restart().asSeconds();
        velocity = HitPos / ((noteSpeedConst / 29) / 1000) * dt;
        
        playTime = composer.getMusicPlayTime(composer.handlerToMusic);
        
        
        while (maniaWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                maniaWindow.close();

            if (event.type == sf::Event::KeyPressed){
                if (event.key.scancode == sf::Keyboard::Scan::A){
                    composer.playManiaSfx(0);
                    }

                if (event.key.scancode == sf::Keyboard::Scan::S){
                    composer.playManiaSfx(1);
                    }

                if (event.key.scancode == sf::Keyboard::Scan::K){
                    composer.playManiaSfx(1);
                    }

                if (event.key.scancode == sf::Keyboard::Scan::L){
                    composer.playManiaSfx(0);
                    }
                }
        }
        
        //game logic
            while(true) {
            if (objects.checkTopNoteFromBuffer(playTime) == true){
                objects.spawnNote(fabulous);
            }else{
                break;
            }}

        
            
        

        //rendering magic
        maniaWindow.clear(sf::Color(0,0,0,255));
        for(int i = 0; i < objects.notes.size() ; i++){
            objects.checkOutOfBoundNotes(i);
            objects.notes[i].update(maniaWindow, velocity);
            }
        std::cout << playTime * 1000 << "\n";
        maniaWindow.display();
    }
}