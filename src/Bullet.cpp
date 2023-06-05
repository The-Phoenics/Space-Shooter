#include "include/Bullet.h"
#include "include/Util.h"
#include "include/Ship.h"
#include "include/Ship.h"
#include "include/TextureManager.h"

Bullet::Bullet(Ship& ship, float radii)
    : m_vel(100.0f)
{
    m_dir = ship.getFacingDir();

    m_bullet.setRadius(10.f);
    m_bullet.setPosition(ship.getShip().getPosition());
    m_bullet.setOrigin(m_bullet.getRadius(), m_bullet.getRadius());
    m_bullet.setTexture(&TextureManager::get_bullet_texture());
}

void Bullet::render(sf::RenderWindow& window) {
    window.draw(m_bullet);
}

void Bullet::move() {
    m_bullet.setPosition(m_bullet.getPosition() + (m_dir * m_vel));
}

void Bullet::onCollisionWithWall(int Collision_Side)
{
    // TODO: delete the bullet
}