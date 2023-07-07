#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define TEXT_RELATIVE_PATH_SHIP      "res/ship.png"
#define TEXT_RELATIVE_PATH_BULLET    "res/bullet.png"
#define TEXT_RELATIVE_PATH_PLAY      "res/playButton.png"
#define TEXT_RELATIVE_PATH_EXIT      "res/exitButton.png"
#define TEXT_RELATIVE_PATH_RESUME    "res/resumeButton.png"
#define TEXT_RELATIVE_PATH_QUIT      "res/quitButton.png"
#define TEXT_RELATIVE_PATH_BACKG     "res/background.png"
#define TEXT_RELATIVE_PATH_ASTEROID  "res/asteroid.png"

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

private:
    static sf::Texture shipText;
    static sf::Texture bulletText;
    static sf::Texture playButtonText;
    static sf::Texture exitButtonText;
    static sf::Texture resumeButtonText;
    static sf::Texture quitButtonText;
    static sf::Texture backgText;
    static sf::Texture asteroidText;
};
