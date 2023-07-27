#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

#include "DEFINES.h"
#include "Util.h"
#include "Ship.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "AnimationManager.h"
#include "MainMenu.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "Animator.h"
#include "Audio.h"
#include "AudioManager.h"
#include "Score.h"
#include "Bar.h"

class Game
{
public:
	Game(sf::RenderWindow& win);
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
	sf::RenderWindow& m_GameWindow;

    Ship  m_ship;
	EnemyManager     m_enemyManager;
	BulletManager    m_bulletManager;
	AnimationManager m_animationManager;

	// for explosions at dead positions
	std::stack<sf::Vector2f> m_enemyDeathPositions;

	// GameState instances
	MainMenu       mainMenuState;
	PauseState     pauseState;
	GameOverState  gameOverState;

	bool isInMainMenuState = true;
	PlayState  gamePlayState;

	Audio m_introAudio; // DBG
	std::vector<Audio> m_explosionsAudio; // DBG
	Audio m_gamePlayAudio; // DBG

	// Scrore instance
	Score m_score;
	
};
