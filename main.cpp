#include "mania.h"
#include "mania.cpp"
#include <string>
#include <filesystem>




int main(int argc, char *argv[]){

    if(argc <=4){
        printf("Please add a width, height, .osu file, and .ogg argument (ex. \"./mania 2560 1440 \"Christell - Dubidubidu (Cut Ver.) (Kibitz) [catJAM].osu\" output.ogg\") \n");
        return 0;
    }

    int screenWidth = std::stoi(argv[1]);
    int screenHeight = std::stoi(argv[2]);
    std::string mapPath = argv[3];
    std::string songPath = argv[4];

    mania maniaSession;
    maniaSession.workDir = std::filesystem::current_path();
    maniaSession.screenWidth = screenWidth;
    maniaSession.screenHeight = screenHeight;
    maniaSession.mapPath = mapPath;
    maniaSession.songPath = songPath;
    maniaSession.maniaStart();

    return 0;
}