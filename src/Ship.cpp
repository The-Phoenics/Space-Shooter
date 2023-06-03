#include "include/Ship.h"
#include "include/Util.h"

Ship::Ship()
    : m_currentAngle(0.f),
      m_vel(sf::Vector2f(1.f, 1.f)),
      m_rotationAngle(1.5f)
{
    m_ship = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
    m_ship.setPosition(400, 400);
    m_ship.setOrigin(m_ship.getSize() / 2.f);
    m_ship.setFillColor(sf::Color::Cyan);
}

Ship::Ship(float width, float height)
    : m_currentAngle(0.f),
      m_vel(sf::Vector2f(1.f, 1.f)),
      m_rotationAngle(1.5f),
      m_ship(sf::RectangleShape(sf::Vector2f(width, height)))
{
    m_ship.setPosition(400, 400);
    m_ship.setOrigin(m_ship.getSize() / 2.f);
    m_ship.setFillColor(sf::Color::Cyan);
}


void Ship::calcFacingDir()
{
    sf::Vector2f dest(m_ship.getPosition() - sf::Vector2f(m_ship.getSize().x / 2, m_ship.getSize().y / 2));
    sf::Vector2f start(m_ship.getPosition());

    sf::Vector2f dir = dest - start;
    m_facingDir = normalize(dir);
}

void Ship::render(sf::RenderWindow& window)
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
    sf::Vector2f v(m_ship.getPosition().x + m_vel.x, m_ship.getPosition().y + m_vel.y);
    m_ship.setPosition(v);
}

void Ship::rotationMovement()
{
    clamp<float>(m_currentAngle, 0, 360);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_ship.rotate(this->m_currentAngle);
    this->setcurrentAngle(getcurrentAngle() + m_rotationAngle);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_ship.rotate(-1 * this->m_currentAngle);
}