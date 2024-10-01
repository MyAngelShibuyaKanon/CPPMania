#include <SFML/Graphics.hpp>
#pragma once 
class note {
    private:
        


    public:
        ~note(){
            //std::cout << index << "\n";
        }
        int index;
        int timeToHit; 
        int noteLane;
        sf::Sprite sprite;
        void initNote(sf::Texture& noteTexture, int noteTime, int noteLane, int index, int screenWidth);
        void update(sf::RenderTarget& window, double velocity);
        void render(sf::RenderTarget& window);
        void move(double OffsetPosX, double OffsetPosY);
        void resetY();
        float getPosY();

};
