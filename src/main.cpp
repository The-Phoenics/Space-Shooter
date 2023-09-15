#include "Game.h"
#include "DEFINES.h"

// window
extern sf::RenderWindow window;

int main()
{
    window.setMouseCursorVisible(false);
    TextureManager::instantiate_textures();
    AudioManager::instantiate_audio();

    Game game(window);
    game.run();
}