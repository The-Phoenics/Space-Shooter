#include "Animator.h"

Animator::Animator(sf::RenderWindow& win, sf::Texture spriteSheet, int columns, int rows)
    : window (win),
      m_texture(spriteSheet),
      m_columns(columns),
      m_rows   (rows),
      currentFrame(0)
{
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0, 0, m_texture.getSize().x / m_columns, m_texture.getSize().y / m_rows));
}

void Animator::update()
{
    currentFrame++;

    if (currentFrame >= m_columns * m_rows)
        currentFrame = 0;

    int frameX = currentFrame % m_columns;
    int frameY = currentFrame / m_columns;

    m_sprite.setTextureRect(sf::IntRect(frameX * m_sprite.getTextureRect().width,
                                      frameY * m_sprite.getTextureRect().height,
                                      m_sprite.getTextureRect().width,
                                      m_sprite.getTextureRect().height));
}

void Animator::setPosition(sf::Vector2f& pos)
{
    m_sprite.setPosition(pos);
}

void Animator::setScale(float scaleX, float scaleY)
{
    m_sprite.setScale(scaleX, scaleY);
}

void Animator::render()
{
    window.draw(m_sprite);
}