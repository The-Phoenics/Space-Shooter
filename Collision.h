//
// Created by prime on 21/5/23.
//

#ifndef SPACE_SHOOTER_COLLISION_H
#define SPACE_SHOOTER_COLLISION_H

#include <SFML/Graphics.hpp>

enum CollisionSide
{
    LEFT = 1, RIGHT, TOP, BOTTOM, NONE
};

int isColliding(const sf::RectangleShape& object, const sf::RenderWindow& window);

bool isColliding(const sf::RectangleShape& obj1, const sf::RectangleShape& obj2);

#endif //SPACE_SHOOTER_COLLISION_H
