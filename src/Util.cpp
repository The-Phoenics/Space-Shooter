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
    resultMult.x = v1.x * v2.x;
    resultMult.y = v1.y * v2.y;
    return resultMult;
}

sf::Vector2f operator*(sf::Vector2f& v, float n)
{
    sf::Vector2f result;
    result += v;
    return result;
}

sf::Vector2f operator/(sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x / n;
    resultDiv.y = v.y / n;
    return resultDiv;
}

sf::Vector2f calcPointAfterRotation(sf::Vector2f& currentPos, double theta)
{
    // this function calculates the position of a point after it is being rotated
    // with respect to the a point currentPos

    sf::Vector2f newPos;
    newPos.x = currentPos.x * cos(theta) - currentPos.y * sin(theta);
    newPos.x = currentPos.x * sin(theta) + currentPos.y * cos(theta);

    return newPos;
}

sf::Vector2f normalize(const sf::Vector2f& v)
{
    float mag = std::sqrt((v.x)*(v.x) + (v.y) * (v.y));
    sf::Vector2f dir(v.x / mag, v.y / mag);

    return dir;
}

int random_integer(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    std::random_device engine;

    return dist(engine);
}