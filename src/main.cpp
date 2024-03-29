#include "Game.h"
#include "DEFINES.h"
#include "AudioManager.h"
#include "Util.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Shooter", sf::Style::Close);
    TextureManager::getInstance().instantiate_textures();
    AudioManager::getInstance().instantiate_audio();

    Game game(window);
    game.run();
}