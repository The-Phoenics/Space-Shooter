#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"

class Ship : public sf::Transformable
{
public:
    Ship(sf::RenderWindow& win);
    Ship(float width, float height, sf::RenderWindow& win);
    ~Ship() {}

    inline sf::Vector2f& getVel() { return m_vel; }
    inline void setVel(sf::Vector2f vel) { m_vel = vel; }

    inline sf::RectangleShape& getShip() { return m_ship; }
    inline sf::Vector2f getFacingDir()   { return m_facingDir; }

    void  onCollisionWithWall(int Collision_Side);

    void  shipMovement();
    void  calcFacingDir();
    float angleToAlignSpriteWithMouse(const sf::Vector2f& mousePos, const sf::Vector2f& spritePos);
    
    void update();
    void render();

private:
    sf::RectangleShape m_ship;
    sf::Vector2f m_vel;
    sf::Vector2f m_facingDir;
    sf::RenderWindow& window;
};