#include <SFML/Graphics.hpp>
#include "Ship.h"
#include <iostream>
#include <random>

#define PI 3.14159

sf::Vector2f operator+(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator-(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator*(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator/(sf::Vector2f& v, float n);

sf::Vector2f operator*(sf::Vector2f& v, float n);

sf::Vector2f calcPointAfterRotation(Ship& ship, float rotationAngle);

sf::Vector2f normalize(const sf::Vector2f& v);

float DegToRadian(float degree);

int random_integer(int min, int max);

sf::Vector2f randomVector2f(int min, int max);

void operator<<(std::ostream& os, sf::Vector2f v);