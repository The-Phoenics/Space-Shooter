#pragma once
#include "GameOverState.h"
#include "MainMenu.h"
#include "PauseState.h"

class StateManager
{
public:
    StateManager(sf::RenderWindow& win);
    ~StateManager() { }

    void update();
    void render();

    void switchStates();

private:
    sf::RenderWindow& window;

    enum GameState
    {
        MainMenuState,
        GamePlayState,
        OverState
    };

    enum PlayState
	{
		Playing,
		Paused,
		GameOver
	};

    GameState m_gameState;
    PlayState m_playState;

    MainMenu       mainMenuState;
	PauseState     pauseState;
	GameOverState  gameOverState;

};
