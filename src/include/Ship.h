#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"

class Ship
{
public:
    Ship(sf::RenderWindow& win);
    Ship(float width, float height, sf::RenderWindow& win);
    ~Ship() {}

    inline sf::Vector2f& getVel() { return m_vel; }
    inline void setVel(sf::Vector2f vel) { m_vel = vel; }

    inline sf::RectangleShape& getShip() { return m_ship; }
    inline sf::Vector2f getFacingDir()   { return m_facingDir; }
    
    void update();
    void render();

private:
    void  movementControls();
    void  move();
    void  calcFacingDir();
    float angleToAlignSpriteWithMouse(const sf::Vector2f& mousePos, const sf::Vector2f& spritePos);
    void  onCollisionWithWall(int Collision_Side);

private:
    sf::RectangleShape m_ship;
    sf::Vector2f m_vel;
    sf::Vector2f m_facingDir;
    float m_speed = 1.2f;
    sf::RenderWindow& window;
};