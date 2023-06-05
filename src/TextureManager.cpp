#include "include/TextureManager.h"

sf::Texture TextureManager::shipText;
sf::Texture TextureManager::bulletText;

const sf::Texture& TextureManager::get_ship_texture() {
    if (!shipText.loadFromFile(TEXT_PATH_SHIP))
        std::cout << "Failed to load ship texture\n";
    return shipText;
}

const sf::Texture& TextureManager::get_bullet_texture() {
    if (!bulletText.loadFromFile(TEXT_PATH_BULLET))
        std::cout << "Failed to load bullet texture\n";
    return bulletText;
}
