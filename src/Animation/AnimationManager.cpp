#include "AnimationManager.h"

AnimationManager::AnimationManager()
	: m_explosionAnimators(),
	posi(100.f, 100.f),
	anim(TextureManager::get_explosion_texture(), 13, 1, posi, 10.f) // DBG
{
}

void AnimationManager::update()
{
	anim.update(); // DBG
	for (auto& a : m_explosionAnimators) {
		a.update();
	}
}

void AnimationManager::render(sf::RenderWindow& window)
{	
	anim.render(window); // DBG
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
		Animator a(TextureManager::get_explosion_texture(), 13, 1, position, 10.f);
		m_explosionAnimators.emplace_back(a);
		enemyDeathPositions.pop();
	}
}

void AnimationManager::removeAnimator()
{
	m_explosionAnimators.erase(
		std::remove_if(m_explosionAnimators.begin(), m_explosionAnimators.end(), [&](Animator& animator) {
			return !animator.isAlive;
		}),
		m_explosionAnimators.end()
	);
}
