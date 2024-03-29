#include "SoLoud/include/soloud_wav.h"
#include <string>
#include <iostream>

void musicHandler::playManiaSfx(int posInVector){
    this -> gSoLoud.play(this->soundEffects[posInVector].sound);
    std::cout << this -> soundEffects[posInVector].sound.getLength() << std::endl;
}
void musicHandler::playMusic(){
    this -> gSoLoud.play(mainMusic);
    
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