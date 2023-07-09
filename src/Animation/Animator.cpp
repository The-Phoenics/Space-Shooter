#include "Animator.h"

Animator::Animator(sf::RenderWindow& win, sf::Texture spriteSheet, int columns, int rows)
    : window (win),
      texture(texture),
      columns(columns),
      rows   (rows),
      currentFrame(0)
{
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x / columns, texture.getSize().y / rows));
}

void Animator::update()
{
    currentFrame++;

    if (currentFrame >= columns * rows)
        currentFrame = 0;

    int frameX = currentFrame % columns;
    int frameY = currentFrame / columns;

    sprite.setTextureRect(sf::IntRect(frameX * sprite.getTextureRect().width,
                                      frameY * sprite.getTextureRect().height,
                                      sprite.getTextureRect().width,
                                      sprite.getTextureRect().height));
}

void Animator::setPosition(sf::Vector2f& pos)
{
    sprite.setPosition(pos);
}

void Animator::setScale(float scaleX, float scaleY)
{
    sprite.setScale(scaleX, scaleY);
}

void Animator::render()
{
    window.draw(sprite);
}