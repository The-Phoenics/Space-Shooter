#include "include/TextureManager.h"

sf::Texture TextureManager::shipText;
sf::Texture TextureManager::bulletText;
sf::Texture TextureManager::playButtonText;
sf::Texture TextureManager::exitButtonText;
sf::Texture TextureManager::resumeButtonText;
sf::Texture TextureManager::quitButtonText;
sf::Texture TextureManager::backgText;
sf::Texture TextureManager::asteroidText;
sf::Texture TextureManager::explosionText;
sf::Texture TextureManager::soundEnableText;
sf::Texture TextureManager::soundDisableText;


void TextureManager::instantiate_textures()
{
    shipText.loadFromFile(TEXT_RELATIVE_PATH_SHIP);
    bulletText.loadFromFile(TEXT_RELATIVE_PATH_BULLET);
    playButtonText.loadFromFile(TEXT_RELATIVE_PATH_PLAY);
    exitButtonText.loadFromFile(TEXT_RELATIVE_PATH_EXIT);
    resumeButtonText.loadFromFile(TEXT_RELATIVE_PATH_RESUME);
    quitButtonText.loadFromFile(TEXT_RELATIVE_PATH_QUIT);
    backgText.loadFromFile(TEXT_RELATIVE_PATH_BACKG);
    asteroidText.loadFromFile(TEXT_RELATIVE_PATH_ASTEROID);
    explosionText.loadFromFile(TEXT_RELATIVE_PATH_EXPLOSION);
    soundEnableText.loadFromFile(TEXT_RELATIVE_SOUND_ENABLE);
    soundDisableText.loadFromFile(TEXT_RELATIVE_SOUND_DISABLE);
}
