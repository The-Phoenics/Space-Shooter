#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "Bar.h"

class Ship
{
public:
    Ship(float width, float height, sf::RenderWindow& win);
    ~Ship() = default;

    sf::Vector2f& getVel() { return m_vel; }
    void setVel(sf::Vector2f vel) { m_vel = vel; }
    sf::RectangleShape& getShip() { return m_ship; }
    sf::Vector2f getFacingDir()   { return m_facingDir; }

    void inputHandler(sf::Event& event);
    void reset();
    void reduceHealth();
    void update(sf::RenderWindow& window, sf::Event& event);
    void render(sf::RenderWindow& window);

public:
    bool isAlive = true;

private:
    void  alignShipRotationWithCursor(sf::RenderWindow& window);
    void  calcFacingDir(sf::RenderWindow& window);
    float angleToAlignSpriteWithMouse(const sf::Vector2f& mousePos, const sf::Vector2f& spritePos);
    void  onCollisionWithWall(int Collision_Side);

private:
    sf::RectangleShape m_ship;

    sf::Vector2f m_vel;
    sf::Vector2f goalVel;
    sf::Vector2f m_facingDir;
    const float c_maxVel;
    float m_speed;

    Bar m_healthBar;
    unsigned int m_health;

    sf::Text m_HpText;
};