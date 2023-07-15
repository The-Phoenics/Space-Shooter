#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Animator
{
public:
    Animator(sf::Texture spriteSheet, sf::Vector2f& pos, int columns, int rows, int counts = 1);
    ~Animator() {  }

    void setAnimationPosition(sf::Vector2f& pos);
    void setAnimationScale(float scaleX, float scaleY);

    void update();
    void render(sf::RenderWindow& window);

public:
    bool isAnimating;
    float m_animatingSpeed = 500;

private:
    sf::Texture m_texture;
    sf::Sprite  m_sprite;
    int m_columns; // columns in sprite sheet
    int m_rows;    // rows in sprite sheet
    int currentFrame;

    int m_animationCounts;
};