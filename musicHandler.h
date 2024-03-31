#include "SoLoud/include/soloud.h"
#include "SoLoud/include/soloud_wavstream.h"
#include "SoLoud/include/soloud_wav.h"
#include <vector>
#include <string>
class sfxNode{
    public:
        SoLoud::Wav sound;
};

class musicHandler{
    private:
        SoLoud::Soloud gSoLoud;
        SoLoud::WavStream mainMusic;
        std::vector<sfxNode> soundEffects;

    public:

        int handlerToMusic;
        void loadManiaSfx();
        void playManiaSfx(int posInVector);
        void playMusic();
        void loadMusic(std::string pathToFile);
        void purge();
        double getMusicPlayTime(SoLoud::handle handler);

    musicHandler(){
        gSoLoud.init();
    }
};

