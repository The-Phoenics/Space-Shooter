#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Timer.h"

class Animator
{
public:
    Animator(sf::Texture& spriteSheet, int c, int r, const sf::Vector2f& pos, float ft);
    ~Animator() { }

    void setPosition(sf::Vector2f& pos);
    void setScale(float scaleX, float scaleY);

    void update();
    void  render(sf::RenderWindow& window);

public:
    bool isAlive = true;
private:
    int columns;
    int rows;
    int currentFrame;

    // speed of animation
    float frameTime;
    Timer m_timer;

    sf::Texture* texture;
    sf::Vector2f position;
    sf::Sprite   sprite;
};