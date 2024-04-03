#include "note.h"
#include "vector"
#include "graphicsHandler.h"
#pragma once
struct noteStruct{
    int type; //0 is note 1 is LN
    int toBeHit;
};

class objectManager {
    public:
        note mainNote;
        std::vector<note> notes; //notes on screen
        std::vector<note> longNotes;//notes on screen
        std::vector<noteStruct> bufferednote; // list of notes and their time to be hit
        bool checkTopNoteFromBuffer(double playbackTime);
        void addNote(noteStruct curNote);
        void spawnNote(noteStruct& curNote, graphicsHandler& graphicsManager, objectManager& obj);
        void moveNote(note& curNote, float offsetY);
};

