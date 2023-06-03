#include "include/Bullet.h"
#include "include/Util.h"
#include "include/Ship.h"

Bullet::Bullet(Ship& ship, float radii)
    : m_vel(100.0f)
{
    this->calcDir(ship.getShip());
    m_bullet.setRadius(10.f);
    m_bullet.setPosition(ship.getShip().getPosition());
    m_bullet.setFillColor(sf::Color::Red);
    m_bullet.setOrigin(m_bullet.getRadius(), m_bullet.getRadius());
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

void Bullet::calcDir(sf::RectangleShape& player)
{
    // ----- BULLET DIRECTION ----- //
    sf::Vector2f tlc = player.getPosition() - (player.getSize() / 2.f);
    m_dir = normalize(tlc - player.getPosition());
}