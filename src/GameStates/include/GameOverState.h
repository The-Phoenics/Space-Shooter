#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINES.h"

class GameOverState
{
public:
    GameOverState(sf::RenderWindow& win);
    ~GameOverState() { }

    void update();
    void render();

private:
    void init();

private:
    sf::RenderWindow& window;

    sf::Text m_gameOver;
    sf::Text m_playAgain;
    sf::Font m_gameOverFont;
};