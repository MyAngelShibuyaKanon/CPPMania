#include "longNote.h"

#include <SFML/Graphics.hpp>
#include <iostream>

void longNote::initNote(sf::Texture& noteHeadTexture,sf::Texture& noteTailTexture, sf::Texture& noteBodyTexture, int noteTime, int endTime, int noteLane, int index, float velocity, double dt){
    this -> timeToHit = noteTime; 
    this -> endTime = endTime;
    this -> index = index;
    this -> noteLane = noteLane;
    this -> noteDone = false;
    int x;
    float duration = (endTime - this->timeToHit);
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
    this -> x = x;
    noteBodyTexture.setRepeated(true);
    float tailYOffset = (duration / 1000) * (velocity * 165);
    this -> spriteBody.setTexture(noteBodyTexture);
    this -> spriteHead.setTexture(noteHeadTexture);
    this -> noteTailTexture = noteTailTexture;
    this -> spriteTail.setTexture(noteTailTexture);
    this -> spriteTail.setPosition(-1000, -150);
    this -> spriteHead.setPosition(x, -150);
    this -> spriteBody.setPosition(x, -150);
    
    
    
    
    this -> spriteBody.setScale(1.33, -1);
    this -> spriteHead.setScale(1.7, 1.7);
    this -> spriteTail.setScale(1.33, 1);
    

    
} 

void longNote::render(sf::RenderTarget& window){
    window.draw(this->spriteBody);
    window.draw(this->spriteTail);
    
    window.draw(this->spriteHead);
}

void longNote::move(double OffsetPosX, double OffsetPosY){
    this -> spriteHead.move(OffsetPosX, OffsetPosY);
    this -> spriteTail.move(OffsetPosX, OffsetPosY);
    this -> spriteBody.move(OffsetPosX, OffsetPosY);
}

void longNote::update(sf::RenderTarget& window, double velocity, double playTime, sf::Texture& noteBodyTexture){
    
    if(this->endTime - (11485 / 32) <= playTime * 1000  && this -> noteDone == false){
        this -> spriteTail.setPosition(x, 0);
        this -> noteDone = true;
        
    }
    if(this->noteDone == false){
        this -> spriteBody.setTextureRect(sf::IntRect(0, 0, 128, this->spriteHead.getPosition().y));
    }
    
    
    this->move(0, velocity);
    this->render(window);
    
}