#include "include/Util.h"
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

sf::Vector2f getDir(sf::Vector2f& start, sf::Vector2f& dest)
{
    // Difference of start from destination
    // Then, normalize it
}

sf::Vector2f calcRotation(sf::Vector2f& currentPos, double theta)
{
    // this function calculates the position of a point after it is being rotated
    // with respect to the a point currentPos
    sf::Vector2f newPos;
    newPos.x = currentPos.x * cos(theta) - currentPos.y * sin(theta);
    newPos.x = currentPos.x * sin(theta) + currentPos.y * cos(theta);

    return newPos;
}

void normalize(sf::Vector2f& v)
{
    v.x = v.x / std::abs(v.x);
    v.y = v.y / std::abs(v.y); 
}

int random_integer(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    std::random_device engine;

    return dist(engine);
}