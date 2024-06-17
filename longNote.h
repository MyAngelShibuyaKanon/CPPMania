#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class longNote {
    private:
        


    public:
        ~longNote(){
            //std::cout << "i was supposed to died at " << endTime << "\n";
        }
        int index;
        int timeToHit; 
        int endTime;
        int noteLane;
        int x;
        bool noteDone;
        sf::Sprite spriteHead;
        sf::Sprite spriteTail;
        sf::Sprite spriteBody;
        sf::Texture noteTailTexture;
        void initNote(sf::Texture& noteHeadTexture,sf::Texture& noteTailTexture, sf::Texture& noteBodytexture, int noteTime, int endTime, int noteLane, int index, float velocity, double dt);
        void update(sf::RenderTarget& window, double velocity, double playTime, sf::Texture& noteBodyTexture);
        void render(sf::RenderTarget& window);
        void move(double OffsetPosX, double OffsetPosY);
        void resetY();
        float getPosY();

};