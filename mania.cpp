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
void moveNotes(objectManager& obj,graphicsHandler& graphicsHandler, float offsetY);
void drawNotes(objectManager& obj, graphicsHandler& graphicsManager, sf::RenderTarget& window);
void start_music(musicHandler &master){
    master.loadMusic("audio.ogg");
    master.playMusic();
    master.loadManiaSfx();
    master.playManiaSfx(0);
}


int main(){
    double dt;
    float velocity;
    double playTime;
    musicHandler master;
    sf::Clock deltaClockLogic;
    objectManager obj;
    graphicsHandler graphicsManager;
    parseMap(obj);
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    start_music(master);

    for (int i = 0; i < obj.bufferednote.size(); i++){
            std::cout << obj.bufferednote[i].type << "  " << obj.bufferednote[i].toBeHit << std::endl;
        }

    while (window.isOpen()){
        playTime = master.getMusicPlayTime(master.handlerToMusic);
        dt = deltaClockLogic.restart().asSeconds();
        velocity = HitPos / ((noteSpeedConst / 28) / 1000) * dt;

        if(obj.checkTopNoteFromBuffer(playTime)){
            
            obj.spawnNote(obj.bufferednote.front(), graphicsManager, obj);
            //std::cout << dt << std::endl;
        }


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
        //std::cout << "b" << std::endl;
        if (obj.notes.empty()) {moveNotes(obj, graphicsManager, velocity);}
        //std::cout << "a" << std::endl;
        window.clear(sf::Color(0,0,0,255));
        //std::cout << "a" << std::endl;
        drawNotes(obj, graphicsManager, window);
        window.display();
    }

    return 0;
}

void moveNotes(objectManager& obj,graphicsHandler& graphicsManager, float offsetY){
    std::cout << "a" << std::endl;
    for (int i; obj.notes.size(); i++){
        //std::cout << obj.notes[i].timeToHit << std::endl;
        obj.moveNote(obj.notes[i], offsetY);
        int x = obj.notes[i].sprite.getPosition().x;
        std::cout << x << std::endl;
    }
}
void drawNotes(objectManager& obj, graphicsHandler& graphicsManager, sf::RenderTarget& window){
    for (int i; i < obj.notes.size(); i++){
        graphicsManager.renderNote(window, obj.notes[i]);
    }
}