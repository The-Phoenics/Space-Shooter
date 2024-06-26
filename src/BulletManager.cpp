#include "BulletManager.h"

BulletManager::BulletManager(Ship& shootingObj, sf::RenderWindow& win)
    : m_bullets(),
      shootingShip(shootingObj),
      
      m_timer()
{
    m_timer.start();
}

void BulletManager::renderBullet(sf::RenderWindow& window)
{
    for (Bullet& bullet : m_bullets)
        window.draw(bullet.getBullet());
}

void BulletManager::updateBulletCount(Ship& ship)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse().isButtonPressed(sf::Mouse::Left)) {
        m_bullets.push_back(Bullet(ship));
        m_canShoot = false;
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
    m_timer.update();

    if (m_timer.getElapsedTime() >= BULLET_COUNT_UPDATE_TIME_INTERVAL && !m_canShoot) {
        m_timer.reset();
        m_canShoot = true;
    }

    if (m_canShoot)
        this->updateBulletCount(shootingShip);
    this->bulletsMovement();
}

void BulletManager::render(sf::RenderWindow& window)
{
    this->renderBullet(window);
}