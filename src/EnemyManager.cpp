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
	for (auto& enemy : m_enemies)
		enemy.update();

	spawnEnemies();
}

void EnemyManager::render()
{
	for (auto& enemy : m_enemies)
		enemy.render();
}

void EnemyManager::removeEnemy()
{
	m_enemies.erase(
		std::remove_if(m_enemies.begin(), m_enemies.end(), [&](Enemy& enemy) {
			return enemy.isAlive = false;
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
