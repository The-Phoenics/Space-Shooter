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

const sf::Texture& TextureManager::get_ship_texture() 
{
    shipText.loadFromFile(TEXT_RELATIVE_PATH_SHIP);
    return shipText;
}

const sf::Texture& TextureManager::get_bullet_texture()
{
    bulletText.loadFromFile(TEXT_RELATIVE_PATH_BULLET);
    return bulletText;
}

const sf::Texture& TextureManager::get_playButton_texture()
{
    playButtonText.loadFromFile(TEXT_RELATIVE_PATH_PLAY);
    return playButtonText;
}

const sf::Texture& TextureManager::get_exitButton_texture()
{
    exitButtonText.loadFromFile(TEXT_RELATIVE_PATH_EXIT);
    return exitButtonText;
}

const sf::Texture& TextureManager::get_resumeButton_texture()
{
    resumeButtonText.loadFromFile(TEXT_RELATIVE_PATH_RESUME);
    return resumeButtonText;
}

const sf::Texture& TextureManager::get_quitButton_texture()
{
    quitButtonText.loadFromFile(TEXT_RELATIVE_PATH_QUIT);
    return quitButtonText;
}

const sf::Texture& TextureManager::get_background_texture()
{
    backgText.loadFromFile(TEXT_RELATIVE_PATH_BACKG);
    return backgText;
}

const sf::Texture& TextureManager::get_asteroid_texture()
{
    asteroidText.loadFromFile(TEXT_RELATIVE_PATH_ASTEROID);
    return asteroidText;
}

const sf::Texture& TextureManager::get_explosion_texture()
{
    asteroidText.loadFromFile(TEXT_RELATIVE_PATH_EXPLOSION);
    return explosionText;
}

