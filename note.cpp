#include <SFML/Graphics.hpp>


void note::initNote(sf::Texture& noteTexture, int noteTime, int noteLane){
    this -> sprite.setTexture(noteTexture);
    this -> sprite.setPosition(0, 0);
    switch (noteLane){
        case 1:
            this -> sprite.setPosition(((720 / 2)) - (2 * 132), 0);
            break;
        case 2:
            this -> sprite.setPosition(((720 / 2)) - (1 * 132), 0);
            break;
        case 3:
            this -> sprite.setPosition(((720 / 2)), 0);
            break;
        case 4:
            this -> sprite.setPosition(((720 / 2)) + (1 * 132), 0);
            break;
    }
} 

void note::render(sf::RenderTarget& target){
    target.draw(this -> sprite);
}

void note::move(int OffsetPosX, int OffsetPosY){
    this -> sprite.move(OffsetPosX, OffsetPosY);
}

float note::getPosY(){
    float posY = this -> sprite.getPosition().y;
    return posY;
}

void note::resetY(){//for tests
    this -> sprite.setPosition(this -> sprite.getPosition().x, 0);
}