#include "note.h"
#include "vector"
#include <list>
#include "graphicsHandler.h"
#pragma once
struct noteStruct{
    int type; //0 is note 1 is LN
    int toBeHit;
    int lane;
};

class objectManager {
    public:
        
        sf::Texture tempTexture;
        note mainNote;
        std::vector<note> notes; //notes on screen
        std::vector<note> longNotes;//notes on screen
        std::vector<noteStruct> bufferednote; // list of notes and their time to be hit
        bool checkTopNoteFromBuffer(double playbackTime);
        void addNote(noteStruct curNote);
        void spawnNote(graphicsHandler& graphicsManager);
        void killNote(int index);
        void checkOutOfBoundNotes(int index);
};

