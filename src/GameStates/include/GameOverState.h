#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINES.h"

class GameOverState
{
public:
    GameOverState();
    ~GameOverState() { }

    void update();
    void render(sf::RenderWindow& window);

private:
    void init();

private:
    sf::Text m_gameOver;
    sf::Text m_playAgain;
    sf::Font m_gameOverFont;
};