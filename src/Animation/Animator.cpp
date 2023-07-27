#include "Animator.h"

Animator::Animator(const sf::Texture& spriteSheet, int c, int r, const sf::Vector2f& pos, float ft)
    : texture(spriteSheet),
      position(pos),
      columns(c),
      rows   (r),
      currentFrame(0),
      frameTime(ft),
      sprite()
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x / columns, texture.getSize().y / rows));

    sf::Vector2f centre(sprite.getTextureRect().width / 2.f, sprite.getTextureRect().height / 2.f);
    sprite.setOrigin(centre);
    setPosition(position);
}

void Animator::update()
{
    if (isAlive) {
        time += 0.5;

        if (time > frameTime) {
            currentFrame++;

            if (currentFrame > columns * rows) {
                currentFrame = 0;
                isAlive = false;
                return;
            }

            int frameX = currentFrame % columns;
            int frameY = currentFrame / columns;

            sprite.setTextureRect(sf::IntRect(
                frameX * sprite.getTextureRect().width,
                frameY * sprite.getTextureRect().height,
                sprite.getTextureRect().width,
                sprite.getTextureRect().height)
            );
            time = 0.f;
        }
    }
}

void Animator::setPosition(sf::Vector2f& pos)
{
    sprite.setPosition(pos);
}

void Animator::setScale(float scaleX, float scaleY)
{
    sprite.setScale(scaleX, scaleY);
}

void Animator::render(sf::RenderWindow& window)
{
    if (isAlive) {
        window.draw(sprite);
    }
}