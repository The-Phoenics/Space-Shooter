#pragma once
#include "Enemy.h"
#include "Collision.h"

#include <stack>
#include <functional>

class EnemyManager
{
public:
	EnemyManager(sf::RenderWindow& win);
	~EnemyManager();

	void update();
	void render();

	void updateStackOfDeadEnemyPositions(std::stack<sf::Vector2f>& enemyDeathPositions);

	void removeEnemy();
	void spawnEnemies();

private:
	void init();

public:
	std::vector<Enemy> m_enemies;
	const size_t MAX_COUNT = 5;

private:
	sf::RenderWindow& window;
};