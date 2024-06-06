#include <SFML/Graphics.hpp>
#include "graphicsHandler.h"
#pragma once


sf::Texture graphicsHandler::getTexture(int id){
   sf::Texture tempTexture;
    switch (id){
        case 0:
            tempTexture.loadFromFile("note8.png");
            return tempTexture;
    }

   tempTexture.loadFromFile("blank.png");
   return tempTexture;
 }

 