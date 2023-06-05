#ifndef SPACE_SHOOTER_BULLET_H
#define SPACE_SHOOTER_BULLET_H

#include <SFML/Graphics.hpp>
#include "include/Ship.h"

class Bullet 
{
public:

    Bullet(Ship& ship, float radii = 10.f);
    ~Bullet() {}

    void render(sf::RenderWindow& window);

    void onCollisionWithWall(int Collision_Side);
    void move();

    // getter .. setters
    inline float getVel()         { return m_vel; }
    inline void setVel(float vel) { m_vel = vel;  }

    sf::CircleShape& getBullet() { return m_bullet; }

    inline void  setRadii(float radii) { m_bullet.setRadius(radii); }
    inline float getRadii() const { return m_bullet.getRadius(); }

private:
    sf::CircleShape m_bullet;
    sf::Vector2f m_dir;
    float m_vel;
};

#endif //SPACE_SHOOTER_BULLET_H
