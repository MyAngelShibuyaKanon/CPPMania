#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class longNote {
    private:
        


    public:
        ~longNote(){
            std::cout << index << "\n";
        }
        int index;
        int timeToHit; 
        int endTime;
        int noteLane;
        sf::Sprite spriteHead;
        sf::Sprite spriteTail;
        sf::Sprite spriteBody;
        void initNote(sf::Texture& noteHeadTexture,sf::Texture& noteTailTexture, sf::Texture& noteBodytexture, int noteTime, int endTime, int noteLane, int index, float velocity);
        void update(sf::RenderTarget& window, double velocity);
        void render(sf::RenderTarget& window);
        void move(double OffsetPosX, double OffsetPosY);
        void resetY();
        float getPosY();

};