#include "Game.h"

Game::Game(sf::RenderWindow &win)
    : window(win),
      is_window_active(true),
      event(),
      m_ship(50, 50, window),
      m_bulletManager(m_ship, window),
      mainMenuState(win),
      pauseState(win),
      m_introAudio(AudioManager::getInstance().get_mainmenu_buffer(), 7.f),
      m_gamePlayAudio(AudioManager::getInstance().get_gameplay_buffer(), 7.f),
      c_explosionAudioValue(6.f)
{
    m_stars.setTexture(&TextureManager::getInstance().get_stars_texture());
    m_stars.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    // m_stars.setFillColor(sf::Color());
    m_background.setTexture(&TextureManager::getInstance().get_gameBackground_texture());
    m_background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    m_crosshair.setTexture(&TextureManager::getInstance().get_crosshair_texture());
    m_crosshair.setSize(sf::Vector2f(17.f, 17.f));
    window.setFramerateLimit(60);
}

void Game::mainMenuStateUpdate()
{
    m_introAudio.play();
    if (mainMenuState.isPlayButtonClicked(window))
    {
        this->isInMainMenuState = false;
        this->m_introAudio.stop();
    }
    else
    {
        this->mainMenuState.update(window);
        this->mainMenuState.render(window);
        window.draw(m_crosshair);
        window.display();
    }
}

void Game::run()
{
    gamePlayState = Playing;
    while (window.isOpen())
    {
        // polling events
        this->processEvents(event);
        if (is_window_active)
        {
            window.setMouseCursorVisible(false);
            if (isInMainMenuState)
            {
                this->mainMenuStateUpdate();
                window.draw(this->m_crosshair);
            }
            else
            {
                switch (gamePlayState)
                {
                case Playing:
                {
                    // switch to gameOverState
                    if (!m_ship.isAlive)
                    {
                        gamePlayState = GameOver;
                        m_gamePlayAudio.stop();
                        continue;
                    }

                    // Gameplay
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    {
                        this->gamePlayState = Paused;
                        this->m_gamePlayAudio.pause();
                        continue;
                    }
                    if (pauseState.soundIsOn)
                    {
                        if (!m_gamePlayAudio.isPlaying())
                            m_gamePlayAudio.play();
                    }
                    this->update();
                    this->remove();
                    this->render(window);
                }
                break;

                case Paused:
                {
                    if (pauseState.resumeButtonClicked(window))
                    {
                        this->gamePlayState = Playing;
                        if (pauseState.soundIsOn)
                        {
                            this->m_gamePlayAudio.resume();
                        }
                        continue;
                    }
                    if (pauseState.quitButtonClicked(window))
                    {
                        this->isInMainMenuState = true;
                        this->gamePlayState = Playing;
                        this->m_gamePlayAudio.stop();
                        this->reset();
                        continue;
                    }
                    this->render(window, false);
                    this->pauseState.update(window);
                    this->pauseState.render(window);
                    window.draw(this->m_crosshair);
                    window.display();
                }
                break;

                case GameOver:
                {
                    // restart the game
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    {
                        this->reset();
                        gamePlayState = Playing;
                    }
                    else
                    {
                        this->gameOverState.update();
                        this->gameOverState.render(window);
                        window.draw(this->m_crosshair);
                        window.display();
                    }
                }
                break;
                };
            }
        }
    }
}

void Game::processEvents(sf::Event& event)
{
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
        
        
        m_ship.inputHandler(event);

        if (event.type == sf::Event::MouseMoved) {
            m_crosshair.setPosition(
                sf::Mouse::getPosition(window).x,
                sf::Mouse::getPosition(window).y
            );
        }

        if (event.type == sf::Event::LostFocus)
            is_window_active = false;

        if (event.type == sf::Event::GainedFocus)
            is_window_active = true;
    }
}

// Update Game
void Game::update()
{
    this->m_ship.update(window, event);
    this->m_enemyManager.update();
    this->m_bulletManager.update();

    // reduce enemy health at bullet hit
    for (auto &bullet : m_bulletManager.m_bullets)
    {
        for (auto &enemy : m_enemyManager.m_enemies)
        {
            if (isColliding(bullet.getBullet(), enemy.getEnemy()))
            {
                enemy.reduceHealth();
            }
        }
    }

    for (auto &enemy : m_enemyManager.m_enemies)
    {
        // damage ship if it collides with rocks
        if (isColliding(m_ship.getShip(), enemy.getEnemy()))
        {
            if (m_ship.isAlive)
            {
                this->m_ship.reduceHealth();
            }
            enemy.isAlive = false;
            enemy.hasHitShip = true;
        }

        // add explosions audio when enemy dies
        if (!enemy.isAlive)
        {
            this->m_explosionsAudio.emplace_back(Audio(AudioManager::getInstance().get_explosion_buffer(), c_explosionAudioValue));
            this->m_score.increaseScore();
        }
    }

    // play explosions audios
    for (auto &explAudio : this->m_explosionsAudio)
    {
        if (!explAudio.isPlaying())
            explAudio.play();
    }

    // update the enemy dead position stack, right after they die, before removing them from vector
    m_enemyManager.updateStackOfDeadEnemyPositions(m_enemyDeathPositions);
    m_animationManager.createNewExplosionAnimators(m_enemyDeathPositions);

    m_animationManager.update();
    m_score.update();

    // update stars opacity
    static int colorAlpha = 1;
    sf::Color color = m_stars.getFillColor();
    if (color.a >= 255) {
        colorAlpha *= -1;
    }
    if (color.a <= 140) {
        colorAlpha *= -1;
    }
    color.a = int(color.a + colorAlpha);
    m_stars.setFillColor(color);
}

// Render Game
void Game::render(sf::RenderWindow &window, bool display)
{
    window.clear();
    window.draw(m_background);
    window.draw(m_stars);
    m_bulletManager.render(window);
    m_animationManager.render(window);
    m_enemyManager.render(window);
    m_ship.render(window);
    m_score.render(window);

    if (display)
        window.display();
}

// Remove entities
void Game::remove()
{
    // remove enemies
    for (auto &enemy : this->m_enemyManager.m_enemies)
    {
        m_bulletManager.removeBullets(enemy.getEnemy());
    }

    // if enemy health < 0 remove it
    this->m_enemyManager.removeEnemy();
    this->m_animationManager.removeAnimator();

    // remove explosion audios
    this->m_explosionsAudio.erase(
        std::remove_if(m_explosionsAudio.begin(), m_explosionsAudio.end(), [](Audio& ea) {
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
