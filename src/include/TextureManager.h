#ifndef SPACE_SHOOTER_TEXTUREMANAGER_H
#define SPACE_SHOOTER_TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

struct TextureManager
{
    TextureManager();
    ~TextureManager();
    

private:
    sf::Texture player;
};


#endif //SPACE_SHOOTER_TEXTUREMANAGER_H
