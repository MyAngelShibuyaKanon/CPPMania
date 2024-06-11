#pragma once
#include "note.h"
#include "longNote.h"
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


void objectManager::spawnNote(graphicsHandler& graphicsManager, float velocity){
    if (this->bufferednote.front().type == 1){

        //std::cout << "N" << "\n";
        this->mainNote.initNote(this->tempTexture, this->bufferednote.front().toBeHit, this->bufferednote.front().lane, this -> numNotes);
        this->notes.push_back(this->mainNote);
        //std::cout << this->bufferednote.front().lane << "\n";
    }

    else if (this->bufferednote.front().type == 128){
        //std::cout << "LN: " << this->bufferednote.front().toBeHit << "\n";

        this->mainLongNote.initNote(this->tempTexture, this->longNoteTailTexture,this->longNoteBodyTexture , this->bufferednote.front().toBeHit, this->bufferednote.front().endTime, this->bufferednote.front().lane, this -> numLongNotes, velocity);
        this->longNotes.push_back(this->mainLongNote);
        //std::cout << this->bufferednote.front().lane << "\n";
    }

    this->bufferednote.erase(this->bufferednote.begin());
}

void objectManager::killNote(int index){
    //std::cout << "killed" << "\n";
    //this->notes.erase(notes.begin() + index - 1);
    
}

void objectManager::checkOutOfBoundNotes(int index){
    if (this->notes[index].getPosY() > 1000){
        killNote(index);
    }
}

void objectManager::clearNotes(double playTime){
    for (int i = 0; i < this -> notes.size(); i++){
        //std::cout << playTime * 1000 << " " << this -> notes[i].timeToHit << " " << (playTime * 1000) - this -> notes[i].timeToHit << "\n";
        //std::cout << this -> notes[i].sprite.getPosition().y << "\n";
        if (playTime * 1000 - this -> notes[i].timeToHit >= 126){
            this -> notes.erase(this -> notes.begin() + i);
            i =- 1;
            continue;
        }
        else {
            continue;
        }
    }
}

void objectManager::checkJudgment(int noteLane, double playTime){
    int judgement;
   
            for (int i = 0; i < this -> notes.size(); i++){
                if (this -> notes[i].noteLane == noteLane ){
                    judgement = abs(playTime * 1000 - this -> notes[i].timeToHit);
                    std::cout << judgement << "ms" << "\n";
                    if (judgement <= 16){
                        this -> judgementScores.push_back(1);
                    }
                    else if (judgement <= 40){
                        this -> judgementScores.push_back(2);
                    }
                    else if (judgement <= 73){
                        this -> judgementScores.push_back(3);
                    }
                    else if (judgement <= 104){
                        this -> judgementScores.push_back(4);
                    }
                    else if (judgement <= 126){
                        this -> judgementScores.push_back(5);
                    }
                    else if (judgement <= 164){
                        this -> judgementScores.push_back(6);
                    }
                    if (judgement > 164){
                        continue;
                    }else{
                        this -> notes.erase(this -> notes.begin() + i);
                        break;
                    }
                }
            }
            
}