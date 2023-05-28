//
// Created by prime on 21/5/23.
//
#include "Collision.h"

int isColliding(const sf::RectangleShape& object, const sf::RenderWindow& window)
{
    if (object.getPosition().x - object.getSize().x < 0)
        return LEFT;

    if (object.getPosition().x + object.getSize().x > window.getSize().x)
        return RIGHT;

    if (object.getPosition().y - object.getSize().y < 0)
        return TOP;

    if (object.getPosition().y + object.getSize().y > window.getSize().y)
        return BOTTOM;

    return NONE;
}

bool isColliding(const sf::RectangleShape& obj1, const sf::RectangleShape& obj2)
{
    if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds()))
        return true;

    return false;
}