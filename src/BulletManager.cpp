#include "include/BulletManager.h"

BulletManager::BulletManager()
    : m_bullets(std::vector<Bullet>())
{
}

void BulletManager::renderBullet(sf::RenderWindow& window)
{
    for (auto bullet : m_bullets)
    {
        window.draw(bullet.getBullet());
    }
}

void BulletManager::updateBulletCount(Ship& ship)
{
    Bullet b = Bullet(ship);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_bullets.push_back(b);
    }
}

void BulletManager::bulletsMovement()
{
    for (auto bullet : m_bullets)
        bullet.bulletMovement();
}