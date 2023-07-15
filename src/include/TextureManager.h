#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

// if textures do not load replace path with absolute or check your current working directory
constexpr const char* TEXT_RELATIVE_PATH_SHIP      = "/home/prime/Desktop/SpaceShooter/res/ship.png";
constexpr const char* TEXT_RELATIVE_PATH_BULLET    = "/home/prime/Desktop/SpaceShooter/res/bullet.png";
constexpr const char* TEXT_RELATIVE_PATH_PLAY      = "/home/prime/Desktop/SpaceShooter/res/playButton.png";
constexpr const char* TEXT_RELATIVE_PATH_EXIT      = "/home/prime/Desktop/SpaceShooter/res/exitButton.png";
constexpr const char* TEXT_RELATIVE_PATH_RESUME    = "/home/prime/Desktop/SpaceShooter/res/resumeButton.png";
constexpr const char* TEXT_RELATIVE_PATH_QUIT      = "/home/prime/Desktop/SpaceShooter/res/quitButton.png";
constexpr const char* TEXT_RELATIVE_PATH_BACKG     = "/home/prime/Desktop/SpaceShooter/res/background.png";
constexpr const char* TEXT_RELATIVE_PATH_ASTEROID  = "/home/prime/Desktop/SpaceShooter/res/asteroid.png";
constexpr const char* TEXT_RELATIVE_PATH_EXPLOSION = "/home/prime/Desktop/SpaceShooter/res/explosion.png";

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

public:
    static constexpr size_t EXPLOSION_TEXT_ROWS    = 1;
    static constexpr size_t EXPLOSION_TEXT_COLUMNS = 13;

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
