#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class Bullet
{
public:
    Bullet(Ship& ship, float radii = 10.f);
    ~Bullet() {}

    void  render(sf::RenderWindow& window);
    void move();

    inline float     getVel()    const  { return m_vel; }
    inline float     getRadii()  const  { return m_bullet.getRadius(); }
    sf::CircleShape& getBullet()        { return m_bullet; }

    inline void  setVel(float vel) { m_vel = vel;  }
    inline void  setRadii(float radii) { m_bullet.setRadius(radii); }

private:
    sf::CircleShape m_bullet;
    sf::Vector2f m_dir;
    float m_vel;
};