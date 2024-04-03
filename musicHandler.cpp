#include "SoLoud/include/soloud_wav.h"
#include <string>
#include <iostream>

void musicHandler::playManiaSfx(int posInVector){
    this -> gSoLoud.play(this->soundEffects[posInVector].sound);
    std::cout << this -> soundEffects[posInVector].sound.getLength() << std::endl;
}
void musicHandler::playMusic(){
    this -> handlerToMusic = this -> gSoLoud.play(mainMusic);
    
}   

void musicHandler::loadMusic(std::string pathToFile){
    this -> mainMusic.load(pathToFile.c_str());
}

void musicHandler::purge(){
    this -> gSoLoud.deinit();
}

void musicHandler::loadManiaSfx(){
    sfxNode sfx;
    this -> soundEffects.push_back(sfx);   
    this -> soundEffects.push_back(sfx);
    this -> soundEffects[0].sound.load("Skins/- mayu (orbs)/soft-hitnormal.ogg");
    this -> soundEffects[1].sound.load("Skins/- mayu (orbs)/soft-hitclap.ogg");
}

double musicHandler::getMusicPlayTime(SoLoud::handle handler){
    double musicPlayPosition = this->gSoLoud.getStreamPosition(handler);
    double musicPlayTime = this->gSoLoud.getStreamTime(handler);

    //std::cout << "Stream Position: " << musicPlayPosition << std::endl;
    //std::cout << "Stream Time: " << musicPlayTime << std::endl;

    return musicPlayTime;
}