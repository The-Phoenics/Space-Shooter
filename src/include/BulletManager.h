#pragma once

#include <vector>
#include "Bullet.h"
#include "Ship.h"
#include "Collision.h"

class BulletManager {
public:
    BulletManager(Ship& shootingObj, sf::RenderWindow& win);
    ~BulletManager() {}

    void renderBullet();
    void updateBulletCount(Ship& ship);
    void bulletsMovement();
    void removeBullets(sf::CircleShape& enemy);

    void update();
    void render();

public:
    std::vector<Bullet> m_bullets;

private:
    Ship& shootingShip;
    sf::RenderWindow& window;
    
    // TODO: Replace this with timer
    int tick = 0;
};