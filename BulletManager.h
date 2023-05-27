//
// Created by prime on 27/5/23.
//

#ifndef SPACE_SHOOTER_BULLETMANAGER_H
#define SPACE_SHOOTER_BULLETMANAGER_H

#include <vector>
#include "Bullet.h"
#include "Ship.h"

class BulletManager {
public:
    BulletManager();
    ~BulletManager() {}

    void renderBullet(sf::RenderWindow& window);
    void updateBulletCount();
    void bulletMovement();

private:
    std::vector<Bullet> m_bullets;
};


#endif //SPACE_SHOOTER_BULLETMANAGER_H
