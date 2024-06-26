#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

// if textures do not load replace path with absolute or check your current working directory
constexpr const char* TEXT_RELATIVE_PATH_SHIP        = "../res/textures/ship.png";
constexpr const char* TEXT_RELATIVE_PATH_BULLET      = "../res/textures/bullet.png";
constexpr const char* TEXT_RELATIVE_PATH_PLAY        = "../res/textures/start.png";
constexpr const char* TEXT_RELATIVE_PATH_EXIT        = "../res/textures/exit.png";
constexpr const char* TEXT_RELATIVE_PATH_RESUME      = "../res/textures/resume.png";
constexpr const char* TEXT_RELATIVE_PATH_QUIT        = "../res/textures/replay.png";
constexpr const char* TEXT_RELATIVE_PATH_BACKG       = "../res/textures/space_background.png";
constexpr const char* TEXT_RELATIVE_PATH_ASTEROID    = "../res/textures/asteroid.png";
constexpr const char* TEXT_RELATIVE_PATH_EXPLOSION   = "../res/textures/explosion.png";
constexpr const char* TEXT_RELATIVE_SOUND_ENABLE     = "../res/textures/soundEnable.png";
constexpr const char* TEXT_RELATIVE_SOUND_DISABLE    = "../res/textures/soundDisable.png";
constexpr const char* TEXT_RELATIVE_PATH_BACKGROUND  = "../res/textures/spacebackground.png";
constexpr const char* TEXT_RELATIVE_PATH_CROSSHAIR   = "../res/textures/crosshair.png";
constexpr const char* TEXT_RELATIVE_PATH_HBAR        = "../res/textures/hbar.png";
constexpr const char* TEXT_RELATIVE_PATH_BARBORDER   = "../res/textures/barborder.png";
constexpr const char* TEXT_RELATIVE_PATH_STARS       = "../res/textures/stars.png";

class TextureManager
{
public:
    void instantiate_textures();

    static TextureManager& getInstance()
    {
        static TextureManager stextureManager;
        return stextureManager;
    }

    sf::Texture& get_ship_texture()             { return shipText;         }
    sf::Texture& get_bullet_texture()           { return bulletText;       }
    sf::Texture& get_playButton_texture()       { return playButtonText;   }
    sf::Texture& get_exitButton_texture()       { return exitButtonText;   }
    sf::Texture& get_resumeButton_texture()     { return resumeButtonText; }
    sf::Texture& get_quitButton_texture()       { return quitButtonText;   }
    sf::Texture& get_background_texture()       { return backgText;        }
    sf::Texture& get_asteroid_texture()         { return asteroidText;     }
    sf::Texture& get_explosion_texture()        { return explosionText;    }
    sf::Texture& get_soundEnable_texture()      { return soundEnableText;  }
    sf::Texture& get_soundDisable_texture()     { return soundDisableText; }
    sf::Texture& get_gameBackground_texture()   { return backgroundText;   }
    sf::Texture& get_crosshair_texture()        { return crosshairText;    }
    sf::Texture& get_barborder_texture()        { return barBorderText;    }
    sf::Texture& get_hbar_texture()             { return hbarText;         }
    sf::Texture& get_stars_texture()            { return starsText;        }

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
    sf::Texture barBorderText;
    sf::Texture hbarText;
    sf::Texture starsText;
};
