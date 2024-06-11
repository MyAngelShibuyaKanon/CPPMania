#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "SoLoud/include/soloud.h"
#include "SoLoud/include/soloud_wav.h"
#include <string>
#include "note.h"
#include "note.cpp"
#include "longNote.h"
#include "longNote.cpp"
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
int screenHeight = 1440;
int screenWidth = 2560;
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
    objects.numNotes = 0;
    objects.numLongNotes = 0;

    //setup graphics
    sf::RenderWindow maniaWindow(sf::VideoMode(screenWidth, screenHeight), "Gyahaha");
    maniaWindow.setFramerateLimit(165);
    maniaWindow.setKeyRepeatEnabled(false);
    objects.tempTexture.loadFromFile("/home/quertzy/Documents/GitHub/CppMania/note8.png");
    objects.longNoteTailTexture.loadFromFile("/home/quertzy/Documents/GitHub/CppMania/noteT.png");

    graphicsHandler fabulous;
    fabulous.genPlayfield(4);
    fabulous.loadJudgements();
    //audio stuff
    musicHandler composer;
    

    while (maniaWindow.isOpen()){

        sf::Event event;
        dt = deltaClock.restart().asSeconds();
        velocity = (1440 - 436 + (178 * 1.7 * 0)) / ((noteSpeedConst / 29) / 1000) * dt;
        
        playTime = composer.getMusicPlayTime(composer.handlerToMusic);
        
        
        while (maniaWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                maniaWindow.close();

            if (event.type == sf::Event::KeyPressed){
                if (event.key.scancode == sf::Keyboard::Scan::A){
                    composer.playManiaSfx(0);
                    objects.checkJudgment(0, playTime);
                    }

                if (event.key.scancode == sf::Keyboard::Scan::S){
                    composer.playManiaSfx(1);
                    objects.checkJudgment(1, playTime);
                    }

                if (event.key.scancode == sf::Keyboard::Scan::K){
                    composer.playManiaSfx(1);
                    objects.checkJudgment(2, playTime);
                    }

                if (event.key.scancode == sf::Keyboard::Scan::L){
                    composer.playManiaSfx(0);
                    objects.checkJudgment(3, playTime);
                    }
                }
        }
        
        //game logic
            while(!objects.bufferednote.empty()) {
            if (objects.checkTopNoteFromBuffer(playTime) == true){
                objects.spawnNote(fabulous, velocity);
            }else{
                break;
            }}

        //rendering magic
        maniaWindow.clear(sf::Color::Black);
        
        fabulous.renderPlayfield(maniaWindow);

        for(int i = 0; i < objects.notes.size() ; i++){
            objects.notes[i].update(maniaWindow, velocity);
            }

        for(int i = 0; i < objects.longNotes.size() ; i++){
           objects.longNotes[i].update(maniaWindow, velocity);
           }
        objects.clearNotes(playTime);
        fabulous.updateJudgement(playTime, objects.judgementScores, maniaWindow);
        
        std::cout << playTime << "\n";
        maniaWindow.display();
    }
}