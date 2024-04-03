#pragma once
#include "note.h"
#include "graphicsHandler.h"
#include "graphicsHandler.cpp"

void objectManager::addNote(noteStruct curNote){
    this->bufferednote.push_back(curNote);
}

bool objectManager::checkTopNoteFromBuffer(double playbackTime){
    if (this->bufferednote.front().toBeHit >= playbackTime){
        return true;
    }
}

void objectManager::moveNote(note& curNote, float offsetY){
    curNote.sprite.move(0, offsetY);
}

void objectManager::spawnNote(noteStruct& curNote, graphicsHandler& graphicsManager, objectManager& obj){
    //std::cout << "a" << std::endl;
    obj.mainNote.initNote(graphicsManager.getTexture(0), curNote.toBeHit, 1);
    //std::cout << "a" << std::endl;
    obj.bufferednote.erase(obj.bufferednote.begin());
    //std::cout << "a" << std::endl;
    obj.notes.push_back(obj.mainNote);
    
    std::cout << obj.notes.back().timeToHit << std::endl;
}