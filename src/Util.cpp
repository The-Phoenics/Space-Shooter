#include "include/Util.h"
#include <cmath>
#include <SFML/System.hpp>

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

sf::Vector2f operator+(sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x + n;
    resultDiv.y = v.y + n;
    return resultDiv;
}

sf::Vector2f operator-(sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x - n;
    resultDiv.y = v.y - n;
    return resultDiv;
}

sf::Vector2f operator*(sf::Vector2f& v, float n)
{
    sf::Vector2f result;
    result.x = v.x * n;
    result.y = v.y * n;
    return result;
}

sf::Vector2f operator/(sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x / n;
    resultDiv.y = v.y / n;
    return resultDiv;
}

float clamp(float min, float max, float value)
{
    bool isNegative = value < 0.f ? true : false; 
    int retVal = std::abs(value);;
    if (value < min)
        retVal = min;
    else if (value > max)
        retVal = max;
    
    if (isNegative) {
        return -1 * retVal;
    }
    return retVal;
}

sf::Vector2f calcPointAfterRotation(Ship& ship, float rotationAngle)
{
    sf::Vector2f center(ship.getShip().getPosition());
    float sideLength = ship.getShip().getSize().x;

    // Convert the rotation angle from degrees to radians
    float rotationRadians = DegToRadian(rotationAngle);

    // Calculate the coordinates of the center of the square relative to the top left corner
    float topLeftX = center.x - (sideLength / 2.0f);
    float topLeftY = center.y - (sideLength / 2.0f);

    // Apply rotation transformation
    float rotatedX = topLeftX * std::cos(rotationRadians) - topLeftY * std::sin(rotationRadians);
    float rotatedY = topLeftX * std::sin(rotationRadians) + topLeftY * std::cos(rotationRadians);

    // Adjust the coordinates of the top left corner relative to the center
    rotatedX += (sideLength / 2.0f);
    rotatedY += (sideLength / 2.0f);

    return sf::Vector2f(rotatedX, rotatedY);
}

sf::Vector2f normalize(const sf::Vector2f& v)
{
    float mag = std::sqrt((v.x)*(v.x) + (v.y) * (v.y));
    sf::Vector2f dir(v.x / mag, v.y / mag);
    return dir;
}

float DegToRadian(float degree)
{
    return degree * PI / 180.0f;
}

int random_integer(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

sf::Vector2f randomVector2f(int min, int max)
{
    sf::Vector2f dir;
    dir.x = random_integer(min, max);
    dir.y = random_integer(min, max);
    return dir;
}

void operator<<(std::ostream& os, sf::Vector2f v)
{
    os << v.x << ", " << v.y << std::endl;
}