#pragma once
#include <SFML/Graphics.hpp>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

#include "Util.h"
#include "Animator.h"
#include "TextureManager.h"

class AnimationManager
{
public:
	AnimationManager();
	~AnimationManager() {}

	void update();
	void render(sf::RenderWindow& window);
	void removeAnimator();

	void createNewExplosionAnimators(std::stack<sf::Vector2f>& enemyDeathPositions);

private:
	std::vector<Animator> m_explosionAnimators;
	
};
