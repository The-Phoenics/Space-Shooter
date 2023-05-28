#include "Util.h"
#include <cmath>

sf::Vector2f operator+(sf::Vector2f& v1, sf::Vector2f& v2)
{
    sf::Vector2f resultPlus;
    resultPlus.x = v1.x + v2.x;
    resultPlus.y = v1.y + v2.y;
    return resultPlus;
}

sf::Vector2f operator-(sf::Vector2f& v1, sf::Vector2f& v2)
{
    sf::Vector2f resultMinus;
    resultMinus.x = v1.x - v2.x;
    resultMinus.y = v1.y - v2.y;
    return resultMinus;
}

sf::Vector2f operator*(sf::Vector2f& v1, sf::Vector2f& v2)
{
    sf::Vector2f resultMult;
    resultMult.x = v1.x - v2.x;
    resultMult.y = v1.y - v2.y;
    return resultMult;
}

void operator*(sf::Vector2f& v, int n)
{
    v.x *= n;
    v.y *= n;
}

sf::Vector2f operator/(sf::Vector2f& v, int n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x / n;
    resultDiv.y = v.y / n;
    return resultDiv;
}

sf::Vector2f calcRotation(sf::Vector2f& v, double theta)
{
    sf::Vector2f newPos;
    newPos.x = v.x * cos(theta) - v.y * sin(theta);
    newPos.x = v.x * sin(theta) + v.y * cos(theta);

    return newPos;
}

int random_integer(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    std::random_device engine;

    return dist(engine);
}