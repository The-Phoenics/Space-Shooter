#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINES.h"
#include "Ship.h"
#include "Enemy.h"
#include "BulletManager.h"
#include "EnemyManager.h"

#include "GameStates/include/MainMenu.h"
#include "GameStates/include/GameOverState.h"
#include "GameStates/include/PauseState.h"

class Game
{
public:
	Game();
	~Game() {}

	enum PlayState
	{
		Playing,
		Paused,
		GameOver
	};

	unsigned int getWindowWidth()  const { return m_GameWindow.getSize().x; }
	unsigned int getWindowHeight() const { return m_GameWindow.getSize().y; }

	void run();

private:
	void processEvents();
	void update();
	void render();
	void eraseSprites();

public:
    bool isplaying = false;

private:
	sf::RenderWindow m_GameWindow;
    
    Ship  m_ship;
	EnemyManager m_enemyManager;
	BulletManager m_bulletManager;

	bool isInMainMenuState = true;
	PlayState  gamePlayState;

	// GameState Objects
	MainMenu       mainMenuState;
	PauseState     pauseState;
	GameOverState  gameOverState;

};
