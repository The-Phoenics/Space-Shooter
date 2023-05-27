//
// Created by prime on 25/5/23.
//

#ifndef SPACE_SHOOTER_BULLET_H
#define SPACE_SHOOTER_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet();
    ~Bullet() {}

    void render(sf::RenderWindow& window);
    sf::CircleShape& getBullet();
    void setup();
    void onCollisionWithWall(int Collision_Side);
    void bulletMovement();

    inline sf::Vector2f& getVel()        { return m_vel; }
    inline void setVel(sf::Vector2f vel) { m_vel = vel;  }

private:
    sf::CircleShape m_bullet;
    sf::Vector2f m_vel;
};


#endif //SPACE_SHOOTER_BULLET_H
