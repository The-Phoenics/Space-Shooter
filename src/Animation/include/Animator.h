#pragma once
#include <SFML/Graphics.hpp>

class Animator
{
public:
    Animator(sf::RenderWindow& win, sf::Texture spriteSheet, int columns, int rows);
    ~Animator() { }

    void setPosition(sf::Vector2f& pos);      
    void setScale(float scaleX, float scaleY);

    inline bool isAnimating()  const { return m_animating; }
    inline void setAnimating(bool isAnimating) { m_animating = isAnimating; }
    
    void update();
    void render();

private:
    sf::RenderWindow & window;
    sf::Texture m_texture;
    sf::Sprite  m_sprite;
    int m_columns; // columns in sprite sheet
    int m_rows;    // rows in sprite sheet
    int currentFrame;
    bool m_animating;
};