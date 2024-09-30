#include <string>
#include <iostream>
#include "musicHandler.h"

musicHandler::musicHandler(std::string songPath) {
    this -> gSoLoud.init();
    this -> loadMusic(songPath);
    this -> loadManiaSfx();
    this -> playMusic();
}

void musicHandler::playManiaSfx(int posInVector){
    this -> gSoLoud.play(this->soundEffects[posInVector]);
    
}
void musicHandler::playMusic(){
    this -> handlerToMusic = this -> gSoLoud.play(this -> mainMusic);
}   

void musicHandler::loadMusic(std::string pathToFile){
    this -> mainMusic.load(pathToFile.c_str());
}

void musicHandler::purge(){
    this -> gSoLoud.deinit();
}

void musicHandler::loadManiaSfx(){
    this -> soundEffects.push_back(sfx);   
    this -> soundEffects.push_back(sfx);
    this -> soundEffects[0].load("Skins/- mayu (orbs)/soft-hitnormal.ogg");
    this -> soundEffects[1].load("Skins/- mayu (orbs)/soft-hitclap.ogg");
}

double musicHandler::getMusicPlayTime(SoLoud::handle handler){
    double musicPlayPosition = this->gSoLoud.getStreamPosition(handler);
    double musicPlayTime = this->gSoLoud.getStreamTime(handler);

    return musicPlayTime;
}