#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

// if textures do not load replace path with absolute or check your current working directory
constexpr const char* TEXT_RELATIVE_PATH_SHIP        = "../res/textures/ship.png";
constexpr const char* TEXT_RELATIVE_PATH_BULLET      = "../res/textures/bullet.png";
constexpr const char* TEXT_RELATIVE_PATH_PLAY        = "../res/textures/playButton.png";
constexpr const char* TEXT_RELATIVE_PATH_EXIT        = "../res/textures/exitButton.png";
constexpr const char* TEXT_RELATIVE_PATH_RESUME      = "../res/textures/resumeButton.png";
constexpr const char* TEXT_RELATIVE_PATH_QUIT        = "../res/textures/quitButton.png";
constexpr const char* TEXT_RELATIVE_PATH_BACKG       = "../res/textures/space_background.png";
constexpr const char* TEXT_RELATIVE_PATH_ASTEROID    = "../res/textures/asteroid.png";
constexpr const char* TEXT_RELATIVE_PATH_EXPLOSION   = "../res/textures/explosion.png";
constexpr const char* TEXT_RELATIVE_SOUND_ENABLE     = "../res/textures/soundEnable.png";
constexpr const char* TEXT_RELATIVE_SOUND_DISABLE    = "../res/textures/soundDisable.png";
constexpr const char* TEXT_RELATIVE_PATH_BACKGROUND  = "../res/textures/spacebackground.png";
constexpr const char* TEXT_RELATIVE_PATH_CROSSHAIR   = "../res/textures/crosshair.png";

class TextureManager
{
public:
    void instantiate_textures();

    static TextureManager& getInstance()
    {
        static TextureManager stextureManager;
        return stextureManager;
    }

    const sf::Texture& get_ship_texture()             { return shipText;         }
    const sf::Texture& get_bullet_texture()           { return bulletText;       }
    const sf::Texture& get_playButton_texture()       { return playButtonText;   }
    const sf::Texture& get_exitButton_texture()       { return exitButtonText;   }
    const sf::Texture& get_resumeButton_texture()     { return resumeButtonText; }
    const sf::Texture& get_quitButton_texture()       { return quitButtonText;   }
    const sf::Texture& get_background_texture()       { return backgText;        }
    const sf::Texture& get_asteroid_texture()         { return asteroidText;     }
          sf::Texture& get_explosion_texture()        { return explosionText;    }
    const sf::Texture& get_soundEnable_texture()      { return soundEnableText;  }
    const sf::Texture& get_soundDisable_texture()     { return soundDisableText; }
    const sf::Texture& get_gameBackground_texture()   { return backgroundText;   }
    const sf::Texture& get_crosshair_texture()        { return crosshairText;    }

public:
    static constexpr size_t EXPLOSION_TEXT_ROWS    = 1;
    static constexpr size_t EXPLOSION_TEXT_COLUMNS = 13;

private:

    TextureManager() {}
    ~TextureManager() {}
    TextureManager(const TextureManager&) = delete;

    sf::Texture shipText;
    sf::Texture bulletText;
    sf::Texture playButtonText;
    sf::Texture exitButtonText;
    sf::Texture resumeButtonText;
    sf::Texture quitButtonText;
    sf::Texture backgText;
    sf::Texture asteroidText;
    sf::Texture explosionText;
    sf::Texture soundEnableText;
    sf::Texture soundDisableText;
    sf::Texture backgroundText;
    sf::Texture crosshairText;
};
