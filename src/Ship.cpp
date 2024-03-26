#include "Ship.h"
#include "Util.h"
#include "TextureManager.h"

#define PI 3.14

Ship::Ship(float width, float height, sf::RenderWindow& win)
    : m_vel(sf::Vector2f(3.f, 3.f)),
      m_health(5),
      m_ship(),
      m_healthBar(5.f)
{
    m_ship = sf::RectangleShape(sf::Vector2f(width, height));
    m_ship.setPosition(MIDDLE_OF_SCREEN);
    m_ship.setOrigin(m_ship.getSize() / 2.f);
    m_ship.setFillColor(sf::Color::Cyan);
    m_ship.setTexture(&TextureManager::getInstance().get_ship_texture());
}

void Ship::calcFacingDir(sf::RenderWindow& window)
{
    sf::Vector2f centre = sf::Vector2f(m_ship.getPosition());
    sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(window).x, 
                                         (float)sf::Mouse::getPosition(window).y);

    sf::Vector2f dir = mousePos - centre;
    m_facingDir = normalize(dir);
}

void Ship::reduceHealth()
{
    if (m_health > 0)
        m_healthBar.decrease();
    if (m_health <= 0)
        isAlive = false;
}

void Ship::render(sf::RenderWindow& window)
{
    window.draw(m_ship);
    m_healthBar.render(window);
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

    // TODO: Improve ship movement
    // TODO: Add lerp to ship movement

    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    //     m_ship.setPosition(sf::Vector2f(currentPos + m_facingDir * 2.f));
}

void Ship::move(sf::RenderWindow& window)
{
    // movement
    this->movementControls();

    // rotational movement
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
    angle = std::atan2(hypot.y, base.x) * 180.0f / PI;
    angle > 180.f ? angle = 180.f - angle : angle = 180.f + angle;
    return angle;
}

void Ship::update(sf::RenderWindow& window)
{
    m_health = m_healthBar.getBarValue() / m_healthBar.getAmount();
    this->onCollisionWithWall(isColliding(m_ship, window));
    this->move(window);
    this->calcFacingDir(window);
    this->m_healthBar.update();
}

void Ship::reset()
{
    m_healthBar.reset();
    m_health = m_healthBar.getBarValue() / m_healthBar.getAmount();
    m_ship.setPosition(MIDDLE_OF_SCREEN);
    isAlive = true;
}