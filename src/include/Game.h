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
	Game(sf::RenderWindow& window);
	~Game() { }

	enum PlayState
	{
		Playing,
		Paused,
		GameOver
	};

	void run();
	void reset();

private:
	void processEvents();
	void update();
	void render(sf::RenderWindow& window);
	void remove();

public:
    bool isplaying = false;

private:
	sf::RenderWindow& window;
	sf::RectangleShape m_crosshair;

    Ship  m_ship;
	sf::RectangleShape m_background;
	EnemyManager       m_enemyManager;
	BulletManager      m_bulletManager;
	AnimationManager   m_animationManager;

	std::stack<sf::Vector2f> m_enemyDeathPositions;

	// GameState instances
	MainMenu       mainMenuState;
	PauseState     pauseState;
	GameOverState  gameOverState;
	PlayState      gamePlayState;
	bool isInMainMenuState = true;

	Audio m_introAudio;
	std::vector<Audio> m_explosionsAudio;
	Audio m_gamePlayAudio;

	// Scrore instance
	Score m_score;
};
