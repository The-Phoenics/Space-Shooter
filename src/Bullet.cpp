#include "Bullet.h"
#include "Util.h"
#include "Ship.h"
#include "Ship.h"
#include "TextureManager.h"

Bullet::Bullet(Ship& ship, float radii)
    : m_vel(4.f)
{
    m_dir = ship.getFacingDir();
    m_bullet.setRadius(10.f);
    m_bullet.setPosition(ship.getShip().getPosition());
    m_bullet.setOrigin(m_bullet.getRadius(), m_bullet.getRadius());
    m_bullet.setTexture(&TextureManager::get_bullet_texture());
    m_bullet.rotate(ship.getShip().getRotation());
}

void Bullet::render(sf::RenderWindow& window) 
{
    window.draw(m_bullet);
}

void Bullet::move() 
{
    sf::Vector2f currentPos = m_bullet.getPosition();
    sf::Vector2f speed = (m_dir * m_vel);
    sf::Vector2f newPos = currentPos + speed;
    m_bullet.setPosition(newPos);
}

void Bullet::onCollisionWithWall(int Collision_Side)
{
    // TODO: delete the bullets
}