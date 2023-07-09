#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum CollisionSide
{
    LEFT = 1, RIGHT, TOP, BOTTOM, NONE
};

inline bool isCollidingWithWall(sf::CircleShape& circle) {
    sf::Vector2f pos = circle.getPosition();
    float radii = circle.getRadius();
    return (pos.x - radii < 0.f   ||
            pos.x + radii > 800.f ||
            pos.y - radii < 0.f   ||
            pos.y + radii > 600.f
        );
}

inline int isColliding(const sf::RectangleShape& object, const sf::RenderWindow& window)
{
    if ((object.getPosition().x - object.getSize().x) < 0)
        return LEFT;

    if ((object.getPosition().x + object.getSize().x) > window.getSize().x)
        return RIGHT;

    if ((object.getPosition().y - object.getSize().y) < 0)
        return TOP;

    if ((object.getPosition().y + object.getSize().y) > window.getSize().y)
        return BOTTOM;

    return NONE;
}

inline int isColliding(const sf::CircleShape& object, const sf::RenderWindow& window)
{
    float radius = object.getRadius();
    if ((object.getPosition().x - radius) < 0)
        return LEFT;

    if ((object.getPosition().x + radius) > window.getSize().x)
        return RIGHT;

    if ((object.getPosition().y - radius) < 0)
        return TOP;

    if ((object.getPosition().y + radius) > window.getSize().y)
        return BOTTOM;

    return NONE;
}

inline bool isColliding(sf::RectangleShape& obj1, sf::RectangleShape& obj2)
{
    return (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds()));
}

inline bool isColliding(sf::CircleShape& obj1, sf::CircleShape& obj2)
{
    return (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds()));
}

inline bool isColliding(sf::RectangleShape & obj1, sf::CircleShape & obj2)
{
    return (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds()));
}
