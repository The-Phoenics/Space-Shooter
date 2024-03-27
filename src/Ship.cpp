#include "Ship.h"
#include "Util.h"
#include "TextureManager.h"

Ship::Ship(float width, float height, sf::RenderWindow& win)
    : m_vel(sf::Vector2f(0.f, 0.f)),
      goalVel(sf::Vector2f{0.f, 0.f}),
      c_maxVel(5.f),
      m_speed(0.2f),
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
    sf::Vector2f mousePos = sf::Vector2f(
        (float)sf::Mouse::getPosition(window).x, 
        (float)sf::Mouse::getPosition(window).y
    );
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
            m_ship.setPosition(WINDOW_WIDTH, m_ship.getPosition().y);
            break;
        case RIGHT:
            m_ship.setPosition(m_ship.getSize().x, m_ship.getPosition().y);
            break;
        case TOP:
            m_ship.setPosition(m_ship.getPosition().x, WINDOW_HEIGHT - m_ship.getSize().y);
            break;
        case BOTTOM:
            m_ship.setPosition(m_ship.getPosition().x, m_ship.getSize().y);
            break;
        default:
            break;
    }
}

float lerp(float target, float current, float increaseFactor)
{
    float diff = target - current;
    if (diff > increaseFactor)
        return current + increaseFactor;
    if (diff < -increaseFactor)
        return current - increaseFactor;

    return target;
}

void Ship::inputHandler(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::W:
            goalVel.y = -c_maxVel;
            break;

        case sf::Keyboard::S:
            goalVel.y = c_maxVel;
            break;

        case sf::Keyboard::A:
            goalVel.x = -c_maxVel;
            break;

        case sf::Keyboard::D:
            goalVel.x = c_maxVel;
            break;
        
        default:
            break;
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::W:
            goalVel.y = 0.f;
            break;

        case sf::Keyboard::S:
            goalVel.y = 0.f;
            break;

        case sf::Keyboard::A:
            goalVel.x = 0.f;
            break;

        case sf::Keyboard::D:
            goalVel.x = 0.f;
            break;
        
        default:
            break;
        }
    }
}

void Ship::alignShipRotationWithCursor(sf::RenderWindow& window)
{
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

void Ship::update(sf::RenderWindow& window, sf::Event& event)
{
    m_health = m_healthBar.getBarValue() / m_healthBar.getAmount();
    onCollisionWithWall(isColliding(m_ship, window));
    alignShipRotationWithCursor(window);
    calcFacingDir(window);
    m_healthBar.update();

    // update velocity
    m_vel.y = lerp(goalVel.y, m_vel.y, m_speed);
    m_vel.x = lerp(goalVel.x, m_vel.x, m_speed);

    sf::Vector2f currentPos = m_ship.getPosition();
    m_ship.setPosition({currentPos.x + m_vel.x, currentPos.y + m_vel.y});
}

void Ship::reset()
{
    m_healthBar.reset();
    m_health = m_healthBar.getBarValue() / m_healthBar.getAmount();
    m_ship.setPosition(MIDDLE_OF_SCREEN);
    isAlive = true;
}