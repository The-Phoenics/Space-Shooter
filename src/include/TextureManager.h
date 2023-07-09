#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINES.h"

class TextureManager
{
public:
    static const sf::Texture& get_ship_texture();
    static const sf::Texture& get_bullet_texture();
    static const sf::Texture& get_playButton_texture();
    static const sf::Texture& get_exitButton_texture();
    static const sf::Texture& get_resumeButton_texture();
    static const sf::Texture& get_quitButton_texture();
    static const sf::Texture& get_background_texture();
    static const sf::Texture& get_asteroid_texture();
    static const sf::Texture& get_explosion_texture();

private:
    static sf::Texture shipText;
    static sf::Texture bulletText;
    static sf::Texture playButtonText;
    static sf::Texture exitButtonText;
    static sf::Texture resumeButtonText;
    static sf::Texture quitButtonText;
    static sf::Texture backgText;
    static sf::Texture asteroidText;
    static sf::Texture explosionText;
};
