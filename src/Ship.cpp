#include "include/Ship.h"
#include "include/Util.h"
#include "include/TextureManager.h"

Ship::Ship()
    : m_vel(sf::Vector2f(1.f, 1.f)),
      m_rotationAngle(1.5f),
      m_headTip(m_ship.getPosition() - sf::Vector2f(m_ship.getSize().x / 2, m_ship.getSize().y / 2))
{
    m_ship = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
    m_ship.setPosition(400, 400);
    m_ship.setOrigin(m_ship.getSize() / 2.f);
    m_ship.setFillColor(sf::Color::Cyan);
    m_ship.setTexture(&TextureManager::get_ship_texture());
}

Ship::Ship(float width, float height)
    : m_vel(sf::Vector2f(1.f, 1.f)),
      m_rotationAngle(1.5f),
      m_headTip(m_ship.getPosition() - sf::Vector2f(m_ship.getSize().x / 2, m_ship.getSize().y / 2))
{
    m_ship = sf::RectangleShape(sf::Vector2f(width, height));
    m_ship.setPosition(400, 400);
    m_ship.setOrigin(m_ship.getSize() / 2.f);
    m_ship.setFillColor(sf::Color::Cyan);
    m_ship.setTexture(&TextureManager::get_ship_texture());
}

void Ship::calcFacingDir(sf::RenderWindow& window)
{
    // FIX : FIIRECTION IX THIS THE FACING DS NOT CALCULATED PROPERLY

    float currentAngle = m_ship.getRotation();
    std::cout << currentAngle << std::endl;
    if (currentAngle != 0)
        this->m_headTip = calcPointAfterRotation(*this, currentAngle);

    sf::Vector2f centre = sf::Vector2f(m_ship.getPosition());
    sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);

    //sf::Vector2f dir = this->m_headTip - centre;
    sf::Vector2f dir = mousePos - centre;
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

void Ship::shipMovement(sf::RenderWindow& window)
{
    //sf::Vector2f v(m_ship.getPosition().x + m_vel.x, m_ship.getPosition().y + m_vel.y);
    //m_ship.setPosition(v);

    rotationMovement(window);
}

void Ship::rotationMovement(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_ship.rotate(m_rotationAngle);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_ship.rotate(-1 * m_rotationAngle);

    // After rotation calculate the ship's facing dir
    this->calcFacingDir(window);
}