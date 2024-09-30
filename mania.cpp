#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "graphicsHandler.h"
#include "objectManager.h"
#include "musicHandler.h"

#include "map_parser.cpp"

#include <string>
#include <iostream> 
#include <vector>
#include <unistd.h>


const double noteSpeedConst = 11485;
int songPosition;
int noteSpeed;
int keys;
int mainMusicHandle;
int HitPos = 436;
int columnWidth = 132;
int playWidth = columnWidth * 4;
float dt;
double playTime;
double velocity;
sf::Clock deltaClock;

void mania::maniaStart(){

    //parse beatmap and objects
    objectManager objects;
    parseMap(objects, mapPath);
    objects.numNotes = 0;
    objects.numLongNotes = 0;

    //setup graphics
    sf::RenderWindow maniaWindow(sf::VideoMode(screenWidth, screenHeight, 32), "Gyahaha", sf::Style::Fullscreen);
    maniaWindow.setFramerateLimit(165);
    maniaWindow.setKeyRepeatEnabled(false);
    objects.tempTexture.loadFromFile("Skins/- mayu (orbs)/Orbs/note8.png");
    objects.longNoteTailTexture.loadFromFile("Skins/- mayu (orbs)/Orbs/noteT.png");
    objects.longNoteBodyTexture.loadFromFile("Skins/- mayu (orbs)/Orbs/noteL.png");

    graphicsHandler fabulous;
    fabulous.genPlayfield(4);
    fabulous.loadJudgements();
    //audio stuff
    musicHandler composer(songPath);
    

    while (maniaWindow.isOpen()){

        sf::Event event;
        dt = deltaClock.restart().asSeconds();
        velocity = (1440 - 140 + 132 + 150) / ((noteSpeedConst / 30) / 1000) * dt;
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
                objects.spawnNote(fabulous, velocity, dt);
            }else{
                break;
            }}

        //rendering magic
        maniaWindow.clear(sf::Color::Black);
        
        fabulous.renderPlayfield(maniaWindow);


        objects.clearNotes(playTime);
        
        for(int i = 0; i < objects.notes.size() ; i++){
            objects.notes[i].update(maniaWindow, velocity);
            }

        for(int i = 0; i < objects.longNotes.size() ; i++){
           objects.longNotes[i].update(maniaWindow, velocity, playTime, objects.longNoteBodyTexture);
           }
        
        fabulous.updateJudgement(playTime, objects.judgementScores, maniaWindow);
        
        maniaWindow.display();
    }
}