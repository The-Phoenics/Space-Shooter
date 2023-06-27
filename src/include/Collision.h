#pragma once
#include <SFML/Graphics.hpp>

enum CollisionSide
{
    LEFT = 1, RIGHT, TOP, BOTTOM, NONE
};

int isColliding(const sf::RectangleShape& object, const sf::RenderWindow& window);

bool isColliding(const sf::RectangleShape& obj1, const sf::RectangleShape& obj2);
