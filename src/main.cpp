#include "Game.h"
#include "DEFINES.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Shooter", sf::Style::Close);
    TextureManager::instantiate_textures();
    AudioManager::instantiate_audio();

    Game game(window);
    game.run();
}