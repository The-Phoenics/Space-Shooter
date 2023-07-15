#pragma once
#include <SFML/Graphics.hpp>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

#include "Animator.h"
#include "TextureManager.h"

class AnimationManager
{
public:
	AnimationManager();
	~AnimationManager() { std::cout << "Destructor: Deleting animation\n"; } // DBG

	void update();
	void render(sf::RenderWindow& window);

	void updateStack(std::stack<sf::Vector2f>& enemyDeathPositions);

	Animator* createExplosionAnimator(sf::Vector2f& explosionPos);
	void removeAnimator();

private:
	// a new animator will be created for each and every new animation
	std::vector<Animator*> m_explosionAnimators;

};
