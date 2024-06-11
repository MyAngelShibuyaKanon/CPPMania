#include "note.h"
#include "longNote.h"
#include "vector"
#include <list>
#include "graphicsHandler.h"
#pragma once
struct noteStruct{
    int type; //0 is note 128 is LN
    int toBeHit;
    int endTime;
    int lane;
};

class objectManager {
    public:
        int numNotes;
        int numLongNotes;
        sf::Texture tempTexture;
        sf::Texture longNoteTailTexture;
        sf::Texture longNoteBodyTexture;
        note mainNote;
        longNote mainLongNote;
        std::vector<int> judgementScores;
        std::vector<note> notes; //notes on screen
        std::vector<longNote> longNotes;//notes on screen
        std::vector<noteStruct> bufferednote; // list of notes and their time to be hit
        bool checkTopNoteFromBuffer(double playbackTime);
        void addNote(noteStruct curNote);
        void spawnNote(graphicsHandler& graphicsManager, float dt);
        void killNote(int index);
        void checkOutOfBoundNotes(int index);
        void clearNotes(double playTime);
        void checkJudgment(int noteLane, double playTime);
};

