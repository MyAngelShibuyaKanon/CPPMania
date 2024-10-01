#include <vector>
#include <string>
#include "note.h"
#include <SFML/Graphics.hpp>
#pragma once

class graphicsHandler{


    private:
        std::vector<sf::Sprite> playfield;
        sf::Clock deltaClockGraphics;
        

    public:
        sf::Texture judgementTextures[6];
        sf::Sprite judgementSprite;
        std::vector<sf::Sprite> judmentScores;
        int timeSinceLastJudgement;
        sf::Texture noteHitCircle;
        std::vector<sf::Sprite> columnHitLine;
        sf::Sprite hitCircle;
        sf::Texture getTexture(int id);
        void genPlayfield(int colSize, int screenWidth);
        void renderPlayfield(sf::RenderTarget& window);
        void renderNote(note& currentNote);
        void renderLongNote();
        int startThread(sf::RenderWindow* window);
        void showJudgement(int judgementLevel);
        void loadJudgements(int screenWidth);
        void updateJudgement(double playTime, std::vector<int>& judgementScores, sf::RenderWindow& window);
};

