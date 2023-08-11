#pragma once
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "TextureManager.h"
#include "Util.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	inline sf::CircleShape& getEnemy() { return this->m_enemy; }
	inline int getHealth() const       { return this->m_health; }

	void reduceHealth();

	void update();
	void render(sf::RenderWindow& window);

public:
	bool isAlive = true;
	bool hasHitShip = false;

private:
	void init();
	void move();
	void rotate();
	void onCollisionWithWall();

private:
	sf::CircleShape   m_enemy;

	sf::Vector2f m_dir;
	sf::Vector2f m_vel;

	int   m_health = 3;
	float m_rotate;
	float m_size;   // radius between 30 to 60

};