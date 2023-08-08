#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

// if textures do not load replace path with absolute or check your current working directory
constexpr const char* TEXT_RELATIVE_PATH_SHIP      = "/home/prime/Desktop/dev/SpaceShooter/res/textures/ship.png";
constexpr const char* TEXT_RELATIVE_PATH_BULLET    = "/home/prime/Desktop/dev/SpaceShooter/res/textures/bullet.png";
constexpr const char* TEXT_RELATIVE_PATH_PLAY      = "/home/prime/Desktop/dev/SpaceShooter/res/textures/playButton.png";
constexpr const char* TEXT_RELATIVE_PATH_EXIT      = "/home/prime/Desktop/dev/SpaceShooter/res/textures/exitButton.png";
constexpr const char* TEXT_RELATIVE_PATH_RESUME    = "/home/prime/Desktop/dev/SpaceShooter/res/textures/resumeButton.png";
constexpr const char* TEXT_RELATIVE_PATH_QUIT      = "/home/prime/Desktop/dev/SpaceShooter/res/textures/quitButton.png";
constexpr const char* TEXT_RELATIVE_PATH_BACKG     = "/home/prime/Desktop/dev/SpaceShooter/res/textures/space_background.png";
constexpr const char* TEXT_RELATIVE_PATH_ASTEROID  = "/home/prime/Desktop/dev/SpaceShooter/res/textures/asteroid.png";
constexpr const char* TEXT_RELATIVE_PATH_EXPLOSION = "/home/prime/Desktop/dev/SpaceShooter/res/textures/explosion.png";
constexpr const char* TEXT_RELATIVE_SOUND_ENABLE   = "/home/prime/Desktop/dev/SpaceShooter/res/textures/soundEnable.png";
constexpr const char* TEXT_RELATIVE_SOUND_DISABLE  = "/home/prime/Desktop/dev/SpaceShooter/res/textures/soundDisable.png";


class TextureManager
{
public:
    static void instantiate_textures();

    static const sf::Texture& get_ship_texture()         { return shipText;         }
    static const sf::Texture& get_bullet_texture()       { return bulletText;       }
    static const sf::Texture& get_playButton_texture()   { return playButtonText;   }
    static const sf::Texture& get_exitButton_texture()   { return exitButtonText;   }
    static const sf::Texture& get_resumeButton_texture() { return resumeButtonText; }
    static const sf::Texture& get_quitButton_texture()   { return quitButtonText;   }
    static const sf::Texture& get_background_texture()   { return backgText;        }
    static const sf::Texture& get_asteroid_texture()     { return asteroidText;     }
    static       sf::Texture& get_explosion_texture()    { return explosionText;    }
    static const sf::Texture& get_soundEnable_texture()  { return soundEnableText;  }
    static const sf::Texture& get_soundDisable_texture() { return soundDisableText; }

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
    static sf::Texture soundEnableText;
    static sf::Texture soundDisableText;
};
