#pragma once
#include "note.h"
#include "graphicsHandler.h"
#include "graphicsHandler.cpp"
#include <iostream>

void objectManager::addNote(noteStruct curNote){
    this->bufferednote.push_back(curNote);
}

bool objectManager::checkTopNoteFromBuffer(double playbackTime){
    if (this->bufferednote.front().toBeHit - (11485 / 29) <= playbackTime * 1000 ){
        return true;
    }
    return false;
}


void objectManager::spawnNote(graphicsHandler& graphicsManager){
    std::cout << "spawned" << "\n";
    this->mainNote.initNote(this->tempTexture, this->bufferednote.front().toBeHit, this->bufferednote.front().lane, notes.size());
    std::cout << "spawned" << "\n";
    this->bufferednote.erase(this->bufferednote.begin());
    std::cout << "spawned" << "\n";
    this->notes.push_back(this->mainNote);
    std::cout << "spawned" << "\n";

}

void objectManager::killNote(int index){
    std::cout << "killed" << "\n";
    //this->notes.erase(notes.begin() + index - 1);
    
}

void objectManager::checkOutOfBoundNotes(int index){
    if (this->notes[index].getPosY() > 1000){
        killNote(index);
    }
}