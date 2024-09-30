//#ifndef MANIA_H
//#define MANIA_H

#include <string>

class mania {
    private:
        const double noteSpeedConst = 13720;
        int songPosition;
        int noteSpeed;
        int keys;
        int mainMusicHandle;
        int HitPos = 436;
        
        int columnWidth = 132;

    public:
        std::string workDir;
        std::string mapPath;
        std::string songPath;
        int screenHeight;
        int screenWidth;
        void maniaStart();
};

//#endif