#pragma once

#include <vector>
#include "Bullet.h"
#include "Ship.h"
#include "Collision.h"
#include "Timer.h"

class BulletManager {
public:
    BulletManager(Ship& shootingObj, sf::RenderWindow& win);
    ~BulletManager() {}

    void renderBullet();
    void updateBulletCount(Ship& ship);
    void bulletsMovement();
    void removeBullets(sf::CircleShape& enemy);

    void update();
    void render(sf::RenderWindow& window);

public:
    std::vector<Bullet> m_bullets;
    bool m_canShoot = true;

private:
    Ship& shootingShip;

    // TODO: Replace this with timer
    Timer m_timer;
    int tick = 0;
};