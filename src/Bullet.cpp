#include "include/Bullet.h"
#include "include/Util.h"
#include "include/Ship.h"

Bullet::Bullet(Ship& t_ship)
    : m_vel(sf::Vector2f(0.5f, 0.5f)),
      m_ship(t_ship)
{
    m_bullet = sf::CircleShape();
    setup();
}

Bullet::Bullet(Ship& t_ship, float radii)
    : m_vel(sf::Vector2f(0.5f, 0.5f)),
      m_ship(t_ship)
{
    m_bullet = sf::CircleShape();
    setup();
    setRadii(radii);
}

void Bullet::render(sf::RenderWindow& window)
{
    window.draw(m_bullet);
}

sf::CircleShape& Bullet::getBullet()
{
    return m_bullet;
}

void Bullet::setbulletRenderPosition()
{
    m_bullet.setPosition(m_bullet.getPosition() + m_vel);
}

void Bullet::bulletMovement()
{
    m_bullet.setPosition(m_dir + m_vel);
}

void Bullet::setup()
{
    m_bullet.setRadius(10.f);
    m_bullet.setPosition(m_ship.getShip().getPosition());
    m_bullet.setOrigin(sf::Vector2f(25.f, 25.f));
    m_bullet.setFillColor(sf::Color::Green);
}

void Bullet::onCollisionWithWall(int Collision_Side)
{
    // TODO: delete the bullet
}
