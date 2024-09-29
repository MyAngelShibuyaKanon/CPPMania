#include "mania.h"
#include "mania.cpp"
#include <string>

int main(int argc, char *argv[]){

    if(argc <=2){
        printf("Please add a width and height argument (ex. \"./mania 2560 1440\") \n");
        return 0;
    }

    int screenWidth = std::stoi(argv[1]);
    int screenHeight = std::stoi(argv[2]);
    std::string mapPath = argv[3];
    std::string songPath = argv[4];

    mania maniaSession;

    maniaSession.screenWidth = screenWidth;
    maniaSession.screenHeight = screenHeight;
    maniaSession.mapPath = mapPath;
    maniaSession.songPath = songPath;
    maniaSession.maniaStart();

    return 0;
}