#include <SFML/Graphics.hpp>
#include "objectManager.h"
#include "objectManager.cpp"
#pragma once

void note::initNote(sf::Texture& noteTexture, int noteTime, int noteLane, int index){
    this -> sprite.setTexture(noteTexture);
    this -> sprite.setPosition(0, 0);
    this -> sprite.setScale(1.7, 1.7);
    this -> timeToHit = noteTime;
    this -> noteLane = noteLane;
    switch (noteLane){
        case 0:
            this -> sprite.setPosition(((2560 / 2)) - (2 * ((2560 / 3) / 4) ), -150);
            break;
        case 1:
            this -> sprite.setPosition(((2560 / 2)) - (1 * ((2560 / 3) / 4) ), -150);
            break;
        case 2:
            this -> sprite.setPosition(((2560 / 2)), -150);
            break;
        case 3:
            this -> sprite.setPosition(((2560 / 2)) + (1 * ((2560 / 3) / 4) ), -150);
            break;
    }


    this -> index = index;
} 

void note::render(sf::RenderTarget& window){
    window.draw(this->sprite);
}

void note::move(double OffsetPosX, double OffsetPosY){
    this -> sprite.move(OffsetPosX, OffsetPosY);
}

float note::getPosY(){
    float posY = this -> sprite.getPosition().y;
    return posY;
}

void note::resetY(){//for tests
    this -> sprite.setPosition(this -> sprite.getPosition().x, 0);
}

void note::update(sf::RenderTarget& window, double velocity){
    this->move(0, velocity);
    this->render(window);

}