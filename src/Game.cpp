#include "Game.h"
#include "Util.h"

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
    m_GameWindow.setFramerateLimit(60);
}

void Game::run()
{
    gamePlayState = Playing;

    while (m_GameWindow.isOpen())
    {
        // only run the game is window has focus
        if (m_GameWindow.hasFocus()) 
        {
            // sfml event polling
            this->processEvents();

            if (isInMainMenuState)
            {
                m_introAudio.play(); // MUSIC
                if (mainMenuState.isPlayButtonClicked()) {
                    this->isInMainMenuState = false;

                    m_introAudio.stop(); // MUSIC
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
                        m_gamePlayAudio.pause(); // MUSIC
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
                        gamePlayState = Playing;
                        continue;
                    }
                    if (pauseState.quitButtonClicked()) {
                        this->isInMainMenuState = true;
                        gamePlayState = Playing;
                        m_gamePlayAudio.stop(); // MUSIC
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

    for (auto& bullet : m_bulletManager.m_bullets) {
        for (auto& enemy : m_enemyManager.m_enemies) {
            if (isColliding(bullet.getBullet(), enemy.getEnemy())) {
                enemy.reduceHealth(); // reduce enemy health at bullet hit
            }

            // add explosions audio when enemy dies
            if (!enemy.isAlive) {
                m_explosionsAudio.emplace_back(Audio(AudioManager::get_explosion_buffer(), 8.f));
                m_score.increaseScore();
            }
        }
    }

    // play explosions audios
    for (auto& explosionAudio : m_explosionsAudio) {
        explosionAudio.play();
    }

    // update the enemy dead position stack, right after they die, before removing them from vector
    m_enemyManager.updateStackOfDeadEnemyPositions(m_enemyDeathPositions);
    m_animationManager.createNewExplosionAnimators(m_enemyDeathPositions);

    m_animationManager.update();
    m_score.update();
}

// Render Game
void Game::render()
{
    m_GameWindow.clear();

    m_bulletManager.render();
    m_animationManager.render(m_GameWindow);
    m_enemyManager.render();
    m_ship.render();
    m_score.render(m_GameWindow);

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

    // remove explosion audios
    m_explosionsAudio.erase(
        std::remove_if(m_explosionsAudio.begin(), m_explosionsAudio.end(), [&](Audio& ea) {
            return !ea.isPlaying();
        }),
        m_explosionsAudio.end()
    );
}
