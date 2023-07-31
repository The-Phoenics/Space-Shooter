#include "StateManager.h"

StateManager::StateManager(sf::RenderWindow& win)
    : window(win),
      mainMenuState  (window),
      pauseState     (window),
      gameOverState  (window)
{
    m_playState = Playing;
    m_gameState = MainMenuState;
}

void StateManager::update()
{
    // TODO
}

void StateManager::render()
{
    // TODO
}

void StateManager::switchStates()
{
    // TODO
}