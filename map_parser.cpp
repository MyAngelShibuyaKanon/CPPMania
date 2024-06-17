#include <fstream>
#include <iostream>
#include "objectManager.h"
#include "objectManager.cpp"

void parseHitNoteLine(std::string textLine, objectManager& obj);

void parseMap(objectManager& obj){
    bool hitObjects = false;
    std::string textLine;
    std::ifstream osuFile;
    osuFile.open("Casandra - Junpakustudy time (keksikosu) [Happy Girl!].osu");
    while(std::getline(osuFile >> std::ws, textLine)) {
        //printf("%s", textLine.c_str());
        if (textLine.find("HitObjects") != -1){
            hitObjects = true;
            continue;
        }

        if (hitObjects){
            parseHitNoteLine(textLine, obj);
        }
        
    }
    osuFile.close();
}


void parseHitNoteLine(std::string textLine, objectManager& obj){
    noteStruct note;
    double x = std::stoi(textLine.substr(0, textLine.find(",")));
    textLine.erase(0, textLine.find(",") + 1);
    int y = std::stoi(textLine.substr(0, textLine.find(",")));
    textLine.erase(0, textLine.find(",") + 1);
    int timeToHit = std::stoi(textLine.substr(0, textLine.find(",")));
    textLine.erase(0, textLine.find(",") + 1);
    int type = std::stoi(textLine.substr(0, textLine.find(",")));
    textLine.erase(0, textLine.find(",") + 1);
    int hitsound = std::stoi(textLine.substr(0, textLine.find(",")));
    textLine.erase(0, textLine.find(",") + 1);
    int endTime;

    if (type == 128){
        endTime = std::stoi(textLine.substr(0, textLine.find(":")));
        textLine.erase(0, textLine.find(":") + 1);
        //std::cout << std::endl << endTime << "Obj is LN" << std::endl;
    }
    else{
        endTime = 0;
        textLine.erase(0, textLine.find(":") + 1);
        //std::cout << endTime << std::endl;
    }

    std::string hitSample = textLine.substr(0);
    textLine.erase();
    
    
    note.type = type; 
    note.endTime = endTime;
    note.toBeHit = timeToHit;
    note.lane = floor(x * 4 / 512);

    //std::cout << note.lane << " " << y << " " << timeToHit << " " << type << " " << hitsound << " " << endTime << " " << hitSample << std::endl;
    obj.addNote(note);

}