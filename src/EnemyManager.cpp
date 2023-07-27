#include "EnemyManager.h"

EnemyManager::EnemyManager(sf::RenderWindow& win)
	: window(win)
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

void EnemyManager::render()
{
	for (auto& enemy : this->m_enemies)
		enemy.render();
}

void EnemyManager::updateStackOfDeadEnemyPositions(std::stack<sf::Vector2f>& enemyDeathPositions)
{
	// update stack
	for (auto& enemy : m_enemies)
	{
		if (!enemy.isAlive && !enemy.hasHitShip) {
			enemyDeathPositions.push(enemy.getEnemy().getPosition());
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
		m_enemies.push_back(Enemy(window));
	}
}

void EnemyManager::init()
{
	for (size_t i = 0; i < MAX_COUNT; ++i) {
		m_enemies.push_back(Enemy(window));
	}
}
