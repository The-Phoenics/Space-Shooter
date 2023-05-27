//
// Created by prime on 21/5/23.
//

#include "Ship.h"
#include "Util.h"

Ship::Ship()
{
    m_ship = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
    setup();
    m_vel = sf::Vector2f (1.f, 1.f);
}

Ship::Ship(float width, float height)
{
    m_ship = sf::RectangleShape(sf::Vector2f(width, height));
    setup();
    m_vel = sf::Vector2f (1.f, 1.f);
}

void Ship::setup()
{
    m_rotationAngle = 1.5f;
    m_ship.setPosition(100, 100);
    m_ship.setOrigin(m_ship.getSize().x / 2, m_ship.getSize().y / 2);
    m_ship.setFillColor(sf::Color::Cyan);
}

Ship::~Ship()
{
}

void Ship::render(sf::RenderWindow& window)
{
    window.draw(m_ship);
}

sf::RectangleShape& Ship::getShip() {
    return m_ship;
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
    sf::Vector2f v(m_ship.getPosition().x + m_vel.x, m_ship.getPosition().y + m_vel.y);
    m_ship.setPosition(v);
}

void Ship::rotationMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_ship.rotate(m_rotationAngle);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_ship.rotate(-1 * m_rotationAngle);
}