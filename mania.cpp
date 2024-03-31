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
gstd::string SkinLocation = "Skins/- mayu (orbs)/";

void start_music(musicHandler &master){
    master.loadMusic("audio.ogg");
    master.playMusic();
    master.loadManiaSfx();
    master.playManiaSfx(0);
}



int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL");

    auto graphics = std::thread(graphicsHandler(), std::ref(window));
    window.setFramerateLimit(this->frameRate);
    while (window.isOpen()){
    
        
    }

    return 0;
}

