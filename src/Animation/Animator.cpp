#include "Animator.h"
#include "DEFINES.h"

Animator::Animator(sf::Texture spriteSheet, sf::Vector2f& pos, int columns, int rows, int counts)
    : m_texture(spriteSheet),
    m_columns(columns),
    m_rows(rows),
    currentFrame(0),
    m_animationCounts(counts)
{
    std::cout << "Constructor: Creating animation\n"; // DBG

    isAnimating = true;
    setAnimationPosition(pos);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0, 0, m_texture.getSize().x / m_columns, m_texture.getSize().y / m_rows));
}

void Animator::update()
{
    if (m_animationCounts == 0) {
        isAnimating = false;
    }

    if (isAnimating)
    {
        if (m_animatingSpeed == 0) {
            currentFrame++;
            m_animatingSpeed = 500;
        }

        if (currentFrame >= m_columns * m_rows) {
            m_animationCounts--;
            currentFrame = 0;
        }

        int frameX = currentFrame % m_columns;
        int frameY = currentFrame / m_columns;

        m_sprite.setTextureRect(sf::IntRect(frameX * m_sprite.getTextureRect().width,
            frameY * m_sprite.getTextureRect().height,
            m_sprite.getTextureRect().width,
            m_sprite.getTextureRect().height));

        m_animatingSpeed--;
    }
}

void Animator::setAnimationPosition(sf::Vector2f& pos)
{
    m_sprite.setPosition(pos);
}

void Animator::setAnimationScale(float scaleX, float scaleY)
{
    m_sprite.setScale(scaleX, scaleY);
}

void Animator::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}