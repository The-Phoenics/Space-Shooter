#include "Game.h"

Game::Game(sf::RenderWindow& win)
    : window(win),
      m_ship         (50, 50, window),
      m_enemyManager (),
      m_bulletManager(m_ship, window),
      mainMenuState  (win),
      pauseState     (win),
      gameOverState  (),
      m_enemyDeathPositions(),
      m_introAudio(AudioManager::get_mainmenu_buffer(), 40.f),
      m_gamePlayAudio(AudioManager::get_gameplay_buffer(), 40.f),
      m_score(),
      m_background(),
      m_crosshair()
{
    sf::Vector2f pos(10.f, 45.f);
    m_score.setPosition(pos);
    m_background.setTexture(&TextureManager::get_gameBackground_texture());
    m_background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    m_crosshair.setTexture(&TextureManager::get_crosshair_texture());
    m_crosshair.setSize(sf::Vector2f(30.f, 30.f));
    this->window.setFramerateLimit(60);
}

void Game::run()
{
    gamePlayState = Playing;

    while (window.isOpen())
    {
        // only run the game is window/game has focus
        if (window.hasFocus()) 
        {
            // polling events
            this->processEvents();

            if (isInMainMenuState)
            {
                m_introAudio.play(); // MUSIC
                if (mainMenuState.isPlayButtonClicked()) {
                    this->isInMainMenuState = false;
                    this->m_introAudio.stop();
                    continue;
                }
                this->mainMenuState.update(window);
                this->mainMenuState.render(window);
            }
            else
            {
                switch (gamePlayState)
                {
                    case Playing:
                    {
                        window.setMouseCursorVisible(false);
                        // switch to gameOverState
                        if (!m_ship.isAlive) {
                            gamePlayState = GameOver;
                            m_gamePlayAudio.stop();
                            window.setMouseCursorVisible(true);
                            continue;
                        }
    
                        // Gameplay 
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                            this->gamePlayState = Paused;
                            this->m_gamePlayAudio.pause();
                            window.setMouseCursorVisible(true);
                            continue;
                        }
                        if (pauseState.soundIsOn) {
                            if (!m_gamePlayAudio.isPlaying()) {
                                m_gamePlayAudio.play();
                            }
                        }
                        this->update();
                        this->remove();
                        this->render(window);
                    } break;

                    case Paused:
                    {
                        if (pauseState.resumeButtonClicked()) {
                            this->gamePlayState = Playing;
                            if (pauseState.soundIsOn) {
                                this->m_gamePlayAudio.resume();
                            }
                            continue;
                        }
                        if (pauseState.quitButtonClicked()) {
                            this->isInMainMenuState = true;
                            this->gamePlayState = Playing;
                            this->m_gamePlayAudio.stop();
                            this->reset();
                            continue;
                        }
                        this->pauseState.update(window);
                        this->pauseState.render(window);
                    } break;

                    case GameOver:
                    {
                        // restart the game
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                            this->reset();
                            gamePlayState = Playing;
                            continue;
                        }
                        this->gameOverState.update();
                        this->gameOverState.render(window);
                    } break;
                };
            }
        }
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
    }
}

// Update Game
void Game::update()
{
    m_crosshair.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

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
        if (!explAudio.isPlaying())
            explAudio.play();
    }

    // update the enemy dead position stack, right after they die, before removing them from vector
    this->m_enemyManager.updateStackOfDeadEnemyPositions(m_enemyDeathPositions);
    this->m_animationManager.createNewExplosionAnimators(m_enemyDeathPositions);

    this->m_animationManager.update();
    this->m_score.update();
}

// Render Game
void Game::render(sf::RenderWindow& window)
{
    this->window.clear();

    this->window.draw(this->m_background);
    this->m_bulletManager.render(window);
    this->m_animationManager.render(window);
    this->m_enemyManager.render(window);
    this->m_ship.render();
    this->m_score.render(window);
    window.draw(this->m_crosshair);

    this->window.display();
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
