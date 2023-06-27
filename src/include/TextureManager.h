#pragma once

#define TEXT_RELATIVE_PATH_SHIP   "../res/ship.png"
#define TEXT_RELATIVE_PATH_BULLET "../res/bullet2.png"

// #define TEXT_PATH_SHIP   "res/ship.png"
// #define TEXT_PATH_BULLET "res/bullet2.png"

#include <SFML/Graphics.hpp>
#include <iostream>

class TextureManager
{
public:
    static const sf::Texture& get_ship_texture();
    static const sf::Texture& get_bullet_texture();

private:
    static sf::Texture shipText;
    static sf::Texture bulletText;

};
