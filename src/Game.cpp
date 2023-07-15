#include "Game.h"
#include "Util.h"

Game::Game()
    : m_GameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Shooter", sf::Style::Close),
      m_ship         (50, 50, m_GameWindow),
      m_enemyManager (m_GameWindow),
      m_bulletManager(m_ship, m_GameWindow),
      mainMenuState  (m_GameWindow),
      pauseState     (m_GameWindow),
      gameOverState  (m_GameWindow)
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
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    gamePlayState = Paused;
                    continue;
                }
                this->update();
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
    eraseSprites();
}

// Render Game
void Game::render()
{
    m_GameWindow.clear();

    m_bulletManager.render();
    m_enemyManager.render();
    m_ship.render();

    m_GameWindow.display();
}

void Game::eraseSprites()
{
    for (auto& bullet : m_bulletManager.m_bullets) {
        for (auto& enemy : m_enemyManager.m_enemies) {
            if (isColliding(bullet.getBullet(), enemy.getEnemy())) {
                m_bulletManager.removeBullets(enemy.getEnemy());
                enemy.reduceHealth(); // reduce enemy health at bullet hit
            }
        }
    }

    // if enemy health < 0 remove it
    m_enemyManager.removeEnemy();
}
