#pragma once
#include "Enemy.h"
#include "Animator.h"
#include "Collision.h"
#include <functional>

class EnemyManager
{
public:
	EnemyManager(sf::RenderWindow& win);
	~EnemyManager();

	void update();
	void render();

	void removeEnemy();
	void spawnEnemies();

private:
	void init();

public:
	std::vector<Enemy> m_enemies;
	const size_t MAX_COUNT = 5;

private:
	sf::RenderWindow& window;

	sf::Texture m_explosionText;
	//Animator m_explosion;
};