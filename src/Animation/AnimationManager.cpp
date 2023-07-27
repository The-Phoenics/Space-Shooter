#include "AnimationManager.h"

AnimationManager::AnimationManager()
	: m_explosionAnimators()
{
}

void AnimationManager::update()
{
	for (auto& a : m_explosionAnimators) {
		a.update();
	}
}

void AnimationManager::render(sf::RenderWindow& window)
{
	for (auto& a : m_explosionAnimators) {
		a.render(window);
	}
}

void AnimationManager::createNewExplosionAnimators(std::stack<sf::Vector2f>& enemyDeathPositions)
{
	sf::Vector2f position;
	// create animators for all the positions present in stack
	while (!enemyDeathPositions.empty())
	{
		position = enemyDeathPositions.top();
		m_explosionAnimators.emplace_back(TextureManager::get_explosion_texture(), 13, 1, position, 2.5f);
		enemyDeathPositions.pop();
	}
}

void AnimationManager::removeAnimator()
{
	m_explosionAnimators.erase(
		std::remove_if(m_explosionAnimators.begin(), m_explosionAnimators.end(), [&](Animator& a) {
			return !a.isAlive;
		}),
		m_explosionAnimators.end()
	);
}
