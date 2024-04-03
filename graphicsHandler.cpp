#include <SFML/Graphics.hpp>
#include "graphicsHandler.h"
#pragma once


 sf::Texture graphicsHandler::getTexture(int id){
    switch (id){
        case 0:
            sf::Texture tempTexture;
            tempTexture.loadFromFile("/home/quertzy/Documents/Programming-stuff/c++/SFML/CppMania/Skins/- mayu (orbs)/Orbs/note8.png");
            return tempTexture;
    }
 }

 void graphicsHandler::renderNote(sf::RenderTarget& window, note& currentNote){
    currentNote.render(window, currentNote);
 }