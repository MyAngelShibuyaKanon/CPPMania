#include <vector>
#include <SFML/Graphics.hpp>
#include "note.h"
#pragma once

class graphicsHandler{


    private:
        std::vector<sf::Sprite> playfield;
        sf::Clock deltaClockGraphics;
        

    public:
        sf::Texture getTexture(int id);
        void renderNote(sf::RenderTarget& window, note& currentNote);
        void renderLongNote();
        int startThread(sf::RenderWindow* window);
};