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
    if (this->bufferednote.front().toBeHit - (11485 / 32) <= playbackTime * 1000 ){
        return true;
    }
    return false;
}


void objectManager::spawnNote(graphicsHandler& graphicsManager, float velocity, double dt){
    if (this->bufferednote.front().type == 1){

        this->mainNote.initNote(this->tempTexture, this->bufferednote.front().toBeHit, this->bufferednote.front().lane, this -> numNotes);
        this->notes.push_back(this->mainNote);

    }

    else if (this->bufferednote.front().type == 128){

        this->mainLongNote.initNote(this->tempTexture, this->longNoteTailTexture,this->longNoteBodyTexture , this->bufferednote.front().toBeHit, this->bufferednote.front().endTime, this->bufferednote.front().lane, this -> numLongNotes, velocity, dt);
        this->longNotes.push_back(this->mainLongNote);

    }

    this->bufferednote.erase(this->bufferednote.begin());
}

void objectManager::killNote(int index){

    
}

void objectManager::checkOutOfBoundNotes(int index){
    if (this->notes[index].getPosY() > 1000){
        killNote(index);
    }
}

void objectManager::clearNotes(double playTime){
    for (int i = 0; i < this -> notes.size(); i++){
        if (playTime * 1000 - this -> notes[i].timeToHit >= 126){
            this -> notes.erase(this -> notes.begin() + i);
            i =- 1;
            continue;
        }
        else {
            continue;
        }
    }

    for (int i = 0; i < this -> longNotes.size(); i++){
        if (playTime * 1000 - this -> longNotes[i].endTime >= 126){
            this -> longNotes.erase(this -> longNotes.begin() + i);
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
    this->noteToJudge.clear();
    this->longNoteToJudge.clear();

    for (int i = 0; i < this -> notes.size(); i++){
        if (this -> notes[i].noteLane == noteLane ){
            this->noteToJudge.push_back(notes[i]);
            this-> itNote = i;
            
            break;
        }
    }

    for (int i = 0; i < this -> longNotes.size(); i++){
        if (this -> longNotes[i].noteLane == noteLane ){
            this->longNoteToJudge.push_back(longNotes[i]);
            this-> itLongNote = i;
            break;
        }
    }


    
    if(!this->noteToJudge.empty()){
        if(this->longNoteToJudge.empty()){

        }else if(abs(playTime * 1000 - this -> notes[this->itNote].timeToHit) > abs(playTime * 1000 - this -> longNotes[this->itLongNote].timeToHit) ){
            return;
        }
        judgement = abs(playTime * 1000 - this -> notes[this->itNote].timeToHit);
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
            return;
        }else{
            this -> notes.erase(this -> notes.begin() + this -> itNote);
            return;
        }
    }

    if(!this->longNoteToJudge.empty()){
        if(this->noteToJudge.empty()){

        }else if(abs(playTime * 1000 - this -> notes[this->itNote].timeToHit) < abs(playTime * 1000 - this -> longNotes[this->itLongNote].timeToHit) ){
            return;
        }

        judgement = abs(playTime * 1000 - this -> longNotes[this->itLongNote].timeToHit);
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
            return;
        }else{
            //this -> longNotes.erase(this -> longNotes.begin() + this -> itLongNote);
            return;
        }
    }
}