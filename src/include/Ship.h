#ifndef SPACE_SHOOTER_SHIP_H
#define SPACE_SHOOTER_SHIP_H

#include <SFML/Graphics.hpp>

class Ship
{
public:
    Ship();
    Ship(float width, float height);
    ~Ship();

    void render(sf::RenderWindow& window);
    sf::RectangleShape& getShip();
    void setup();
    void onCollisionWithWall(int Collision_Side);
    void shipMovement();
    void rotationMovement();

    inline sf::Vector2f& getVel()        { return m_vel; }
    inline void setVel(sf::Vector2f vel) { m_vel = vel;  }

private:
    sf::RectangleShape m_ship;
    sf::Vector2f m_vel;
    sf::Vector2f m_facingDir;
    float m_rotationAngle;
};

#endif //SPACE_SHOOTER_SHIP_H
