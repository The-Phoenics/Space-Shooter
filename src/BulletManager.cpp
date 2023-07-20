#include "include/BulletManager.h"

BulletManager::BulletManager(Ship& shootingObj, sf::RenderWindow& win)
    : m_bullets(),
      shootingShip(shootingObj),
      window(win)
{
}

void BulletManager::renderBullet()
{
    for (Bullet& bullet : m_bullets)
        window.draw(bullet.getBullet());
}

void BulletManager::updateBulletCount(Ship& ship)
{
    if (sf::Mouse().isButtonPressed(sf::Mouse::Left)) {
        m_bullets.push_back(Bullet(ship));
    }
}

void BulletManager::bulletsMovement()
{
    for (Bullet& bullet : m_bullets)
        bullet.move();
}

void BulletManager::removeBullets(sf::CircleShape& enemy)
{
    m_bullets.erase(
        std::remove_if(m_bullets.begin(), m_bullets.end(), [&](Bullet& bullet) {
            return isColliding(bullet.getBullet(), enemy) || isCollidingWithWall(bullet.getBullet());
            }),
        m_bullets.end()
    );
}

void BulletManager::update()
{
    // TODO: Replace Ticking with Timer
    if (tick > 20)
        tick = 0;
    tick++;

    if (tick > 20)
        this->updateBulletCount(shootingShip);
    this->bulletsMovement();
}

void BulletManager::render()
{
    this->renderBullet();
}