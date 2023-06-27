#include "Game.h"

Game::Game()
    : m_GameWindow(sf::VideoMode(800, 600), "Space Shooter", sf::Style::Close),
      m_ship(Ship(50, 50, m_GameWindow)),
      m_bulletManager(BulletManager(m_ship, m_GameWindow))
{
    m_GameWindow.setFramerateLimit(60);
}

void Game::run()
{
    while (m_GameWindow.isOpen())
    {
        this->processEvents();
        this->update();
        this->render();
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
    m_bulletManager.update();
}

// Render Game
void Game::render()
{
    m_GameWindow.clear();

    m_ship.render();
    m_bulletManager.render();

    m_GameWindow.display();
}