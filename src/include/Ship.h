#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "Bar.h"

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

    void reset();
    void reduceHealth();
    
    void update();
    void render();

public:
    bool isAlive = true;

private:
    void initHpText();
    void  movementControls();
    void  move();
    void  calcFacingDir();
    float angleToAlignSpriteWithMouse(const sf::Vector2f& mousePos, const sf::Vector2f& spritePos);
    void  onCollisionWithWall(int Collision_Side);

private:
    sf::RenderWindow& window;
    sf::RectangleShape m_ship;

    sf::Vector2f m_vel;
    sf::Vector2f m_facingDir;
    float m_speed { 1.2f };

    Bar m_healthBar;
    unsigned int m_health;

    sf::Text m_HpText;
    sf::Font m_HpFont;
};