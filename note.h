#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class note {
    private:
        


    public:
        ~note(){
            std::cout << index << "\n";
        }
        int index;
        int timeToHit; 
        sf::Sprite sprite;
        void initNote(sf::Texture& noteTexture, int noteTime, int noteLane, int index);
        void update(sf::RenderTarget& window, double velocity);
        void render(sf::RenderTarget& window);
        void move(double OffsetPosX, double OffsetPosY);
        void resetY();
        float getPosY();

};