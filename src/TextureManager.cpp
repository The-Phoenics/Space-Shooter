#include "include/TextureManager.h"

sf::Texture TextureManager::shipText;
sf::Texture TextureManager::bulletText;

const sf::Texture& TextureManager::get_ship_texture() 
{
    !shipText.loadFromFile(TEXT_RELATIVE_PATH_SHIP);
    return shipText;
}

const sf::Texture& TextureManager::get_bullet_texture()
{
    !bulletText.loadFromFile(TEXT_RELATIVE_PATH_BULLET);
    return bulletText;
}
