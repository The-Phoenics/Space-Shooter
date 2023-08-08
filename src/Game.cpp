#include "Game.h"

Game::Game(sf::RenderWindow& win)
    : m_GameWindow(win),
      m_ship         (50, 50, m_GameWindow),
      m_enemyManager (m_GameWindow),
      m_bulletManager(m_ship, m_GameWindow),
      mainMenuState  (m_GameWindow),
      pauseState     (m_GameWindow),
      gameOverState  (m_GameWindow),
      m_enemyDeathPositions(),
      m_introAudio(AudioManager::get_mainmenu_buffer(), 40.f),
      m_gamePlayAudio(AudioManager::get_gameplay_buffer(), 40.f),
      m_score()
{
    sf::Vector2f pos(10.f, 45.f);
    m_score.setPosition(pos);
    this->m_GameWindow.setFramerateLimit(60);
}

void Game::run()
{
    gamePlayState = Playing;

    while (m_GameWindow.isOpen())
    {
        // only run the game is window/game has focus
        if (m_GameWindow.hasFocus()) 
        {
            // polling events
            this->processEvents();

            if (isInMainMenuState)
            {
                m_introAudio.play(); // MUSIC
                if (mainMenuState.isPlayButtonClicked()) {
                    this->isInMainMenuState = false;

                    this->m_introAudio.stop(); // MUSIC
                    continue;
                }
                this->mainMenuState.update();
                this->mainMenuState.render();
            }

            else // If not in MainMenuState
            {
                if (gamePlayState == Playing)
                {
                    // switch to gameOverState
                    if (!m_ship.isAlive) {
                        gamePlayState = GameOver;
                        m_gamePlayAudio.stop();
                        continue;
                    }

                    // Gameplay 
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        this->gamePlayState = Paused;
                        this->m_gamePlayAudio.pause(); // MUSIC
                        continue;
                    }
                    if (!m_gamePlayAudio.isPlaying()) { // MUSIC
                        m_gamePlayAudio.play();
                    }
                    this->update();
                    this->remove();
                    this->render();
                    continue;
                }
                else if (gamePlayState == Paused)
                {
                    if (pauseState.resumeButtonClicked()) {
                        this->gamePlayState = Playing;
                        this->m_gamePlayAudio.resume();
                        continue;
                    }
                    if (pauseState.quitButtonClicked()) {
                        this->isInMainMenuState = true;
                        this->gamePlayState = Playing;
                        this->m_gamePlayAudio.stop(); // MUSIC
                        continue;
                    }
                    this->pauseState.update();
                    this->pauseState.render();
                    continue;
                }
                else if (gamePlayState == GameOver)
                {
                    // restart the game
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        this->reset();
                        gamePlayState = Playing;
                        continue;
                    }

                    this->gameOverState.update();
                    this->gameOverState.render();
                    continue;
                }
            }
        }
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (this->m_GameWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->m_GameWindow.close();
    }
}

// Update Game
void Game::update()
{
    this->m_ship.update();
    this->m_enemyManager.update();
    this->m_bulletManager.update();

    // reduce enemy health at bullet hit
    for (auto& bullet : m_bulletManager.m_bullets) {
        for (auto& enemy : m_enemyManager.m_enemies) {
            if (isColliding(bullet.getBullet(), enemy.getEnemy())) {
                enemy.reduceHealth();
            }
        }
    }

    for (auto& enemy : m_enemyManager.m_enemies) {
        // damage ship if it collides with rocks
        if (isColliding(m_ship.getShip(), enemy.getEnemy())) {
            if (m_ship.isAlive) {
                this->m_ship.reduceHealth();
            }
            enemy.isAlive = false;
            enemy.hasHitShip = true;
        }

        // add explosions audio when enemy dies
        if (!enemy.isAlive) {
            this->m_explosionsAudio.emplace_back(Audio(AudioManager::get_explosion_buffer(), 8.f));
            this->m_score.increaseScore();
        }
    }

    // play explosions audios
    for (auto& explAudio : this->m_explosionsAudio) {
        if (!explAudio.isPlaying()) // DBG
            explAudio.play();
    }

    // update the enemy dead position stack, right after they die, before removing them from vector
    this->m_enemyManager.updateStackOfDeadEnemyPositions(m_enemyDeathPositions);
    this->m_animationManager.createNewExplosionAnimators(m_enemyDeathPositions);

    this->m_animationManager.update();
    this->m_score.update();
}

// Render Game
void Game::render()
{
    this->m_GameWindow.clear();

    this->m_bulletManager.render();
    this->m_animationManager.render(m_GameWindow);
    this->m_enemyManager.render();
    this->m_ship.render();
    this->m_score.render(m_GameWindow);

    this->m_GameWindow.display();
}

// Remove entities
void Game::remove()
{
    // remove enemies
    for (auto& enemy : this->m_enemyManager.m_enemies) {
        m_bulletManager.removeBullets(enemy.getEnemy());
    }

    // if enemy health < 0 remove it
    this->m_enemyManager.removeEnemy();
    this->m_animationManager.removeAnimator();

    // remove explosion audios
    this->m_explosionsAudio.erase(
        std::remove_if(m_explosionsAudio.begin(), m_explosionsAudio.end(), [&](Audio& ea) {
            return !ea.isPlaying();
        }),
        m_explosionsAudio.end()
    );
}

// Reset the game
void Game::reset()
{
    m_score.reset();
    m_ship.reset();
}