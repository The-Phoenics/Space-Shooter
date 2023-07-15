#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

#include "DEFINES.h"
#include "Ship.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "AnimationManager.h"

#include "MainMenu.h"
#include "GameOverState.h"
#include "PauseState.h"

class Game
{
public:
	Game();
	~Game() { }

	enum PlayState
	{
		Playing,
		Paused,
		GameOver
	};

	void run();

private:
	void processEvents();
	void update();
	void render();
	void remove();

public:
    bool isplaying = false;

private:
	sf::RenderWindow m_GameWindow;

    Ship  m_ship;
	EnemyManager     m_enemyManager;
	BulletManager    m_bulletManager;
	AnimationManager m_animationManager;

	std::stack<sf::Vector2f> m_enemyDeathPositions;

	bool isInMainMenuState = true;
	PlayState  gamePlayState;

	// GameState Objects
	MainMenu       mainMenuState;
	PauseState     pauseState;
	GameOverState  gameOverState;

};
