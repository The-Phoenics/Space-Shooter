#include <SFML/Graphics.hpp>
#include "include/Ship.h"

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

float angleToAlignSpriteWithMouse(const sf::Vector2f& mousePos, const sf::Vector2f& spritePos);

template<typename T>
void clamp(T& value, T minValue, T maxValue)
{
	if (value < minValue)
		value = minValue;
	
	if (value > maxValue)
		value = maxValue;
}