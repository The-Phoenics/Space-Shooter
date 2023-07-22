#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Animator
{
public:
    Animator(const sf::Texture& spriteSheet, int c, int r, const sf::Vector2f& pos, float ft);
    ~Animator() { }

    void setPosition(sf::Vector2f& pos);
    void setScale(float scaleX, float scaleY);

    void update();
    void render(sf::RenderWindow& window);

public:
    bool isAlive = true;
private:
    int columns;
    int rows;
    int currentFrame;

    // more the frametime slower the animation
    float frameTime;
    float time = 0;

    sf::Texture  texture;
    sf::Vector2f position;
    sf::Sprite   sprite;
};