#include "include/BulletManager.h"

BulletManager::BulletManager()
    : m_bullets(std::vector<Bullet>())
{
}

void BulletManager::renderBullet(sf::RenderWindow& window)
{
    for (Bullet& bullet : m_bullets)
        window.draw(bullet.getBullet());
}

void BulletManager::updateBulletCount(Ship& ship)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        m_bullets.push_back(Bullet(ship));
    }
}

void BulletManager::bulletsMovement()
{
    for (Bullet& bullet : m_bullets)
        bullet.move();
}