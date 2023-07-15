#include "AnimationManager.h"

AnimationManager::AnimationManager()
	: m_explosionAnimators()
{
}

void AnimationManager::update()
{
	// update
	for (size_t i = 0; i < m_explosionAnimators.size(); i++)
	{
		std::cout << "\nInside for loop\n";
		m_explosionAnimators[i]->update();
	}
}

void AnimationManager::render(sf::RenderWindow& window)
{
	for (Animator* explosion : m_explosionAnimators) {
		explosion->render(window);
	}
}

void AnimationManager::updateStack(std::stack<sf::Vector2f>& enemyDeathPositions)
{
	// generate new animations when enemies dies
	while (!enemyDeathPositions.empty())
	{
		sf::Vector2f pos = enemyDeathPositions.top();
		Animator* animator = createExplosionAnimator(pos);

		m_explosionAnimators.push_back(animator);
		enemyDeathPositions.pop();
	}
}

Animator* AnimationManager::createExplosionAnimator(sf::Vector2f& explosionPos)
{
	Animator* animator = new Animator(TextureManager::get_explosion_texture(), explosionPos,
									  TextureManager::EXPLOSION_TEXT_COLUMNS, TextureManager::EXPLOSION_TEXT_COLUMNS);
	return animator;
}

void AnimationManager::removeAnimator()
{
	// delete memory
	for (size_t i = 0; i < m_explosionAnimators.size(); i++)
	{
		if (!m_explosionAnimators[i]->isAnimating) {
			delete m_explosionAnimators[i];
		}
	}

	// DBG
	// erase Animator pointers
	m_explosionAnimators.erase(
		std::remove_if(m_explosionAnimators.begin(), m_explosionAnimators.end(), [](Animator* a) {
			return !a->isAnimating; }),
		m_explosionAnimators.end()
	);
}
