#include <SFML/Graphics.hpp>
#include <random>

sf::Vector2f operator+(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator-(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator*(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator/(sf::Vector2f& v, float n);

sf::Vector2f operator*(sf::Vector2f& v, float n);

sf::Vector2f calcPointAfterRotation(sf::Vector2f& v, double theta);

sf::Vector2f normalize(const sf::Vector2f& v);

int random_integer(int min, int max);

template<typename T>
void clamp(T& value, T minValue, T maxValue)
{
	if (value < minValue)
		value = minValue;
	
	if (value > maxValue)
		value = maxValue;
}