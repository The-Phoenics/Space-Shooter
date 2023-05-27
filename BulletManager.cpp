//
// Created by prime on 27/5/23.
//

#include "BulletManager.h"

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

// THIS FUNCTION IS SUSPICIOUS
void BulletManager::updateBulletCount()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_bullets.push_back(Bullet());
    }
}

void BulletManager::bulletMovement()
{
    for (auto bullet : m_bullets)
    {
        bullet.bulletMovement();
    }
}