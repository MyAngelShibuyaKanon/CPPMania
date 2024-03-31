#include <vector>
#include <SFML/Graphics.hpp>


class graphicsHandler{


    private:
        std::vector<sf::Sprite> playfield;

    
    void graphicsHander(sf::RenderWindow* window);
}