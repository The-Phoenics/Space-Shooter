#include "Game.h"
#include "DEFINES.h"

// window
extern sf::RenderWindow window;

int main()
{
    TextureManager::instantiate_textures();
    AudioManager::instantiate_audio();

    Game game(window);
    game.run();
}