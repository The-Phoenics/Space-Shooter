//
// Created by prime on 25/5/23.
//

#include "Bullet.h"
#include "Util.h"

Bullet::Bullet()
    : m_vel(sf::Vector2f(0.5f, 0.5f))
{
    m_bullet = sf::CircleShape();
    setup();
}

void Bullet::render(sf::RenderWindow& window)
{
    window.draw(m_bullet);
}

sf::CircleShape& Bullet::getBullet()
{
    return m_bullet;
}

void Bullet::bulletMovement()
{
    m_bullet.setPosition(m_bullet.getPosition() + m_vel);
}

void Bullet::setup()
{
    m_bullet.setRadius(10.f);
    m_bullet.setPosition(300.f, 100.f);
    m_bullet.setOrigin(sf::Vector2f(25.f, 25.f));
    m_bullet.setFillColor(sf::Color::Green);
}

void Bullet::onCollisionWithWall(int Collision_Side)
{
    // TODO: delete the bullet
}
