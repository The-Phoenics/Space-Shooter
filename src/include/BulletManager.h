#pragma once

#include <vector>
#include "Bullet.h"
#include "Ship.h"

class BulletManager {
public:
    BulletManager(Ship& shootingObj, sf::RenderWindow& win);
    ~BulletManager() {}

    void renderBullet();
    void updateBulletCount(Ship& ship);
    void bulletsMovement();

    void update();
    void render();

private:
    std::vector<Bullet> m_bullets;
    Ship& shootingShip;
    sf::RenderWindow& window;
    
    // TODO: Replace this with timer
    int tick = 0;
};