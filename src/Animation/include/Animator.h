#pragma once
#include <SFML/Graphics.hpp>

class Animator
{
public:
    Animator(sf::RenderWindow& win, sf::Texture spriteSheet, int columns, int rows);
    ~Animator() { }

    void setPosition(sf::Vector2f& pos);
    void setScale(float scaleX, float scaleY);
    
    void update();
    void render();

private:
    sf::RenderWindow& window;
    sf::Texture texture;
    sf::Sprite  sprite;
    int columns; // columns in sprite sheet
    int rows;    // rows in sprite sheet
    int currentFrame;
};