#include <fstream>
#include <iostream>
#include "objectManager.h"
#include "objectManager.cpp"
void parseHitNoteLine(std::string textLine, objectManager& obj);

void parseMap(objectManager& obj){
    bool hitObjects = false;
    std::string textLine;
    std::ifstream osuFile;
    osuFile.open("Uzuki Mao - MYSTERIA ~ Tamashii no Yukue (Short Ver.) (Muse Dash) [Mysteria].osu");
    while(std::getline(osuFile >> std::ws, textLine)) {
        printf("%s", textLine.c_str());
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
    int x = std::stoi(textLine.substr(0, textLine.find(",")));
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

    if (type != 1){
        endTime = 0;
        endTime = std::stoi(textLine.substr(0, textLine.find(":")));
        textLine.erase(0, textLine.find(":") + 1);
        std::cout << endTime << std::endl;
    }
    else{
        endTime = 0;

    }

    std::string hitSample = textLine.substr(0);
    textLine.erase();
    noteStruct note;
    if(type == 1){
    note.type = 1; 
    }
    else {
        note.type = 2;
    }

    note.toBeHit = timeToHit;
    std::cout << x << " " << y << " " << timeToHit << " " << type << " " << hitsound << " " << endTime << " " << hitSample << std::endl;
    obj.addNote(note);

}