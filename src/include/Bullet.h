#ifndef SPACE_SHOOTER_BULLET_H
#define SPACE_SHOOTER_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(Ship& t_ship);
    Bullet(Ship& t_ship, float radii = 10.f);
    ~Bullet() {}

    void render(sf::RenderWindow& window);
    sf::CircleShape& getBullet();
    void setup();

    inline void  setRadii(float radii){ m_bullet.setRadius(radii); }
    inline float getRadii() const     { return m_bullet.getRadius(); }

    void onCollisionWithWall(int Collision_Side);
    void setbulletRenderPosition();
    void bulletMovement();
    void calcDir();


    inline sf::Vector2f& getVel()        { return m_vel; }
    inline void setVel(sf::Vector2f vel) { m_vel = vel;  }

private:
    sf::CircleShape m_bullet;
    Ship& m_ship;
    sf::Vector2f m_vel;
    sf::Vector2f m_dir;
};

#endif //SPACE_SHOOTER_BULLET_H
