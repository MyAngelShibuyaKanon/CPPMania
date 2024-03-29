#include <SFML/Graphics.hpp>

class note {
    private:
        sf::Sprite sprite;


    public:
        void initNote(sf::Texture& noteTexture, int noteTime, int noteLane);
        void update();
        void render(sf::RenderTarget& target);
        void move(int OffsetPosX, int OffsetPosY);
        void resetY();
        float getPosY();
};