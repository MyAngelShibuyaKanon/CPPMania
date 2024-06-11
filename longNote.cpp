#include <SFML/Graphics.hpp>
#include "objectManager.h"
#include "objectManager.cpp"
#pragma once

void longNote::initNote(sf::Texture& noteHeadTexture,sf::Texture& noteTailTexture, sf::Texture& noteBodyTexture, int noteTime, int endTime, int noteLane, int index, float velocity){
    this -> timeToHit = noteTime; 
    this -> endTime = endTime;
    this -> index = index;
    this -> noteLane = noteLane;

    int x;
    float duration = (endTime - this->timeToHit);
    std::cout << velocity<< "\n";
    std::cout << "starttime: " << this->timeToHit<< "\n";
    std::cout << "endtime: " << this->endTime << "\n";
    std::cout << "duration: " << duration << "\n";
    std::cout << "offset: " << (duration / 1000) * (velocity) * 165 << "\n";
    switch (noteLane){
        case 0:
            x = ((2560 / 2)) - (2 * ((2560 / 3) / 4) );
            break;
        case 1:
            x = ((2560 / 2)) - (1 * ((2560 / 3) / 4) );
            break;
        case 2:
            x = ((2560 / 2));
            break;
        case 3:
            x = ((2560 / 2)) + (1 * ((2560 / 3) / 4));
            break;
    }
    //std::cout << x << "\n";
    this -> spriteHead.setTexture(noteHeadTexture);
    this -> spriteHead.setPosition(x, 0);
    this -> spriteTail.setTexture(noteTailTexture);
    this -> spriteHead.setScale(1.7, 1.7);
    this -> spriteTail.setScale(1.7, 1.7);
    float tailYOffset = (duration / 1000) * (velocity * 165);
    this -> spriteTail.setPosition(x, 0);
    this -> spriteTail.move(0, -tailYOffset);
    
} 

void longNote::render(sf::RenderTarget& window){
    window.draw(this->spriteHead);
    window.draw(this->spriteTail);
}

void longNote::move(double OffsetPosX, double OffsetPosY){
    this -> spriteHead.move(OffsetPosX, OffsetPosY);
    this -> spriteTail.move(OffsetPosX, OffsetPosY);
}

void longNote::update(sf::RenderTarget& window, double velocity){
    this->move(0, velocity);
    this->render(window);
}