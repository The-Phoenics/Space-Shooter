#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	init();
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::update()
{
	// update enemies
	for (auto& enemy : m_enemies)
		enemy.update();

	// respawn enemies
	spawnEnemies();
}

void EnemyManager::render(sf::RenderWindow& window)
{
	for (auto& enemy : this->m_enemies)
		enemy.render(window);
}

void EnemyManager::updateStackOfDeadEnemyPositions(std::stack<sf::Vector2f>& enemyDeathPositions)
{
	// update stack
	for (auto& enemy : m_enemies)
	{
		if (!enemy.isAlive) {
			sf::Vector2f pos = enemy.getEnemy().getPosition();
			enemyDeathPositions.push(pos);
		}
	}
}

void EnemyManager::removeEnemy()
{
	m_enemies.erase(
		std::remove_if(m_enemies.begin(), m_enemies.end(), [&](Enemy& enemy) {
			return !enemy.isAlive;
			}),
		m_enemies.end()
	);
}

void EnemyManager::spawnEnemies()
{
	while (m_enemies.size() < MAX_COUNT) {
		m_enemies.emplace_back(Enemy());
	}
}

void EnemyManager::init()
{
	for (size_t i = 0; i < MAX_COUNT; ++i) {
		m_enemies.emplace_back(Enemy());
	}
}
