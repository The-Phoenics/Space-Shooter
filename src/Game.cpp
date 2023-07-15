#include "Game.h"
#include "Util.h"

Game::Game()
    : m_GameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Shooter", sf::Style::Close),
      m_ship         (50, 50, m_GameWindow),
      m_enemyManager (m_GameWindow),
      m_bulletManager(m_ship, m_GameWindow),
      mainMenuState  (m_GameWindow),
      pauseState     (m_GameWindow),
      gameOverState  (m_GameWindow),
      m_enemyDeathPositions()
{
    m_GameWindow.setFramerateLimit(60);
}

void Game::run()
{
    gamePlayState = Playing;

    while (m_GameWindow.isOpen())
    {
        // sfml event polling
        this->processEvents();

        if (isInMainMenuState)
        {
            if (mainMenuState.isPlayButtonClicked()) {
                this->isInMainMenuState = false;
                continue;
            }
            mainMenuState.update();
            mainMenuState.render();
        }

        else // If not in MainMenuState
        {
            if (gamePlayState == Playing)
            { 
                // Gameplay 
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    gamePlayState = Paused;
                    continue;
                }
                this->update();
                this->remove();
                this->render();
                continue;
            }
            else if (gamePlayState == Paused)
            {
                if (pauseState.resumeButtonClicked()) {
                    gamePlayState = Playing;
                    continue;
                }
                if (pauseState.quitButtonClicked()) {
                    this->isInMainMenuState = true;
                    gamePlayState = Playing;
                    continue;
                }
                pauseState.update();
                pauseState.render();
                continue;
            }
            else if (gamePlayState == GameOver)
            {
                gameOverState.update();
                gameOverState.render();
                continue;
            }
        }
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_GameWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_GameWindow.close();
    }
}

// Update Game
void Game::update()
{
    m_ship.update();
    m_enemyManager.update();
    m_bulletManager.update();
    m_animationManager.update(); // NR


    for (auto& bullet : m_bulletManager.m_bullets)
    {
        for (auto& enemy : m_enemyManager.m_enemies)
        {
            if (isColliding(bullet.getBullet(), enemy.getEnemy()))
            {
                enemy.reduceHealth(); // reduce enemy health at bullet hit
            }
        }
    }

    // update the enemy dead position stack, right after they die, before removing them from vector
    m_enemyManager.updateStackOfDeadEnemyPositions(m_enemyDeathPositions);
    m_animationManager.updateStack(m_enemyDeathPositions);
}

// Render Game
void Game::render()
{
    m_GameWindow.clear();

    m_bulletManager.render();
    m_enemyManager.render();
    m_animationManager.render(m_GameWindow);
    m_ship.render();

    m_GameWindow.display();
}

void Game::remove()
{
    // remove enemies
    for (auto& enemy : m_enemyManager.m_enemies) {
        m_bulletManager.removeBullets(enemy.getEnemy());
    }

    // if enemy health < 0 remove it
    m_enemyManager.removeEnemy();
    m_animationManager.removeAnimator();
}
