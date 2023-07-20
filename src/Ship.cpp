#include "include/Ship.h"
#include "include/Util.h"
#include "include/TextureManager.h"

#define M_PI 3.14

Ship::Ship(sf::RenderWindow& win)
    : m_vel(sf::Vector2f(1.f, 1.f)),
      m_ship(),
      window(win)
{
    m_ship.setSize(sf::Vector2f(100.f, 100.f));
    m_ship.setPosition(sf::Vector2f(400.f, 300.f));
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
        case LEFT:
            m_vel.x *= -1;
            break;
        case RIGHT:
            m_vel.x *= -1;
            break;
        case TOP:
            m_vel.y *= -1;
            break;
        case BOTTOM:
            m_vel.y *= -1;
            break;
        default:
            break;
    }
}

void Ship::movementControls()
{
    sf::Vector2f currentPos = m_ship.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        m_ship.setPosition(sf::Vector2f(currentPos.x, currentPos.y - m_speed));
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_ship.setPosition(sf::Vector2f(currentPos.x - m_speed, currentPos.y));
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        m_ship.setPosition(sf::Vector2f(currentPos.x, currentPos.y + m_speed));
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_ship.setPosition(sf::Vector2f(currentPos.x + m_speed, currentPos.y));
}

void Ship::move()
{
    // movement
    this->movementControls();

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
    this->move();
    this->calcFacingDir();
}
