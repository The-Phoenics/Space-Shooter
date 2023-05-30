#include <SFML/Graphics.hpp>
#include <random>

sf::Vector2f operator+(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator-(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator*(sf::Vector2f& v1, sf::Vector2f& v2);

sf::Vector2f operator/(sf::Vector2f& v, int n);

void operator*(sf::Vector2f& v, int n);

sf::Vector2f getDir(sf::Vector2f& start, sf::Vector2f& dest);

sf::Vector2f calcRotation(sf::Vector2f& v, double theta);

void normalize(sf::Vector2f& v);

int random_integer(int min, int max);