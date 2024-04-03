#include <SFML/Graphics.hpp>
#pragma once

class note {
    private:
        


    public:
        int timeToHit; 
        sf::Sprite sprite;
        void initNote(sf::Texture noteTexture, int noteTime, int noteLane);
        void update();
        void render(sf::RenderTarget& window, note& curNote);
        void move(int OffsetPosX, int OffsetPosY);
        void resetY();
        float getPosY();
};