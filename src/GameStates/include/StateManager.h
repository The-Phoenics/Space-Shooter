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

    void setState();
    void getState() const;

private:
    sf::RenderWindow& window;

    enum PlayState
	{
		Playing,
		Paused,
		GameOver
	};

    MainMenu       mainMenuState;
	PauseState     pauseState;
	GameOverState  gameOverState;

};
