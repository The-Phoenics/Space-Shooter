#include "include/Ship.h"
#include "include/Util.h"
#include "include/TextureManager.h"

Ship::Ship(sf::RenderWindow& win)
    : m_vel(sf::Vector2f(1.f, 1.f)),
      window(win)
{
    m_ship = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
    m_ship.setPosition(400, 400);
    m_ship.setOrigin(m_ship.getSize() / 2.f);
    m_ship.setFillColor(sf::Color::Cyan);
    m_ship.setTexture(&TextureManager::get_ship_texture());
}

Ship::Ship(float width, float height, sf::RenderWindow& win)
    : m_vel(sf::Vector2f(1.f, 1.f)),
      window(win)
{
    m_ship = sf::RectangleShape(sf::Vector2f(width, height));
    m_ship.setPosition(400, 400);
    m_ship.setOrigin(m_ship.getSize() / 2.f);
    m_ship.setFillColor(sf::Color::Cyan);
    m_ship.setTexture(&TextureManager::get_ship_texture());
}

void Ship::calcFacingDir()
{
    sf::Vector2f centre = sf::Vector2f(m_ship.getPosition());
    sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);

    sf::Vector2f dir = mousePos - centre;
    m_facingDir = normalize(dir);
}

void Ship::render()
{
    window.draw(m_ship);
}

void Ship::onCollisionWithWall(int Collision_Side) {
    switch (Collision_Side)
    {
        case 1:
            m_vel.x *= -1;
            break;
        case 2:
            m_vel.x *= -1;
            break;
        case 3:
            m_vel.y *= -1;
            break;
        case 4:
            m_vel.y *= -1;
            break;
        default:
            break;
    }
}

void Ship::shipMovement()
{
    // Rotational movement
    static sf::Vector2f mousePos;
    static float angle;

    mousePos = sf::Vector2f((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
    angle = angleToAlignSpriteWithMouse(mousePos, m_ship.getPosition()) - 90.f;

    m_ship.setRotation(angle);
}

float Ship::angleToAlignSpriteWithMouse(const sf::Vector2f& mousePos, const sf::Vector2f& spritePos)
{
    float angle = 0.0f;
    sf::Vector2f hypot = mousePos - spritePos;
    sf::Vector2f base  = sf::Vector2f(mousePos.x, spritePos.y) - spritePos;

    angle = std::atan2(hypot.y, base.x) * 180.0f / M_PI;

    angle > 180.f ? angle = 180.f - angle : angle = 180.f + angle;
    return angle;
}

void Ship::update()
{
    this->onCollisionWithWall(isColliding(m_ship, window));
    this->shipMovement();
    this->calcFacingDir();
}
