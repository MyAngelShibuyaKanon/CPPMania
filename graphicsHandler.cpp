#include "graphicsHandler.h"

#include "note.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


sf::Texture graphicsHandler::getTexture(int id){
   sf::Texture tempTexture;
    switch (id){
        case 0:
            tempTexture.loadFromFile("/Skins/- mayu (orbs)/Orbs/note8.png");
            return tempTexture;
    }

   tempTexture.loadFromFile("blank.png");
   return tempTexture;
 }

 void graphicsHandler::genPlayfield(int colSize, int screenWidth){
  this -> noteHitCircle.loadFromFile("Skins/- mayu (orbs)/Orbs/key.png");
  int x;
  for (int i = 1; i <= colSize; i++){
    
    switch (i){
        case 1:
            x = ((screenWidth / 2)) - (2 * ((screenWidth / 3) / 4) );
            break;
        case 2:
            x = ((screenWidth / 2)) - (1 * ((screenWidth / 3) / 4) );
            break;
        case 3:
            x = ((screenWidth / 2));
            break;
        case 4:
            x = ((screenWidth / 2)) + (1 * ((screenWidth / 3) / 4));
            break;
    }
    this -> hitCircle.setTexture(this -> noteHitCircle);
    this -> hitCircle.setPosition(x, 1440 - (hitCircle.getTexture()->getSize().y * 1.7 + 132));
    this -> hitCircle.setScale(1.7, 1.7);
    this -> columnHitLine.push_back(this -> hitCircle);
  
  }
}

void graphicsHandler::renderPlayfield(sf::RenderTarget& window){
  for (int i = 0; i < this -> columnHitLine.size(); i++){
    window.draw(this -> columnHitLine[i]);
  }
}

void graphicsHandler::loadJudgements(int screenWidth){
  sf::Texture judgementTexture;
  judgementTexture.loadFromFile("Skins/- mayu (orbs)/mania-hit0-0.png");
  this -> judgementTextures[5] = judgementTexture;
  judgementTexture.loadFromFile("Skins/- mayu (orbs)/mania-hit50-0.png");
  this -> judgementTextures[4] = judgementTexture;
  judgementTexture.loadFromFile("Skins/- mayu (orbs)/mania-hit100-0.png");
  this -> judgementTextures[3] = judgementTexture;
  judgementTexture.loadFromFile("Skins/- mayu (orbs)/mania-hit200-0.png");
  this -> judgementTextures[2] = judgementTexture;
  judgementTexture.loadFromFile("Skins/- mayu (orbs)/mania-hit300-0.png");
  this -> judgementTextures[1] = judgementTexture;
  judgementTexture.loadFromFile("Skins/- mayu (orbs)/mania-hit300g-0.png");
  this -> judgementTextures[0] = judgementTexture;

  this -> judgementSprite.setPosition(screenWidth / 2 - 128, 200);
} 
void graphicsHandler::showJudgement(int judgementLevel){
  switch (judgementLevel)
  {
  case 1:
    this -> judgementSprite.setTexture(this -> judgementTextures[0]);
    break;

  case 2:
    this -> judgementSprite.setTexture(this -> judgementTextures[1]);
    break;

  case 3:
    this -> judgementSprite.setTexture(this -> judgementTextures[2]);
    break;

  case 4:
    this -> judgementSprite.setTexture(this -> judgementTextures[3]);
    break;

  case 5:
    this -> judgementSprite.setTexture(this -> judgementTextures[4]);
    break;

  case 6:
    this -> judgementSprite.setTexture(this -> judgementTextures[5]);
    break;
  
  default:

    break;
  }
}

void graphicsHandler::updateJudgement(double playTime, std::vector<int>& judgementScores, sf::RenderWindow& window){
  if (!judgementScores.empty()){
    this -> showJudgement(judgementScores.back());
    judgementScores.clear();
    this -> timeSinceLastJudgement = playTime * 1000;
  }

  if (playTime * 1000 - this -> timeSinceLastJudgement <= 100 && playTime * 1000 - this ->timeSinceLastJudgement  > 0){
    window.draw(this -> judgementSprite);
  }
  
}