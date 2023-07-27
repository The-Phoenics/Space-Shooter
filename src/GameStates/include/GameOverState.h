#pragma once
#include <SFML/Graphics.hpp>

class GameOverState
{
public:
    GameOverState(sf::RenderWindow& win);
    ~GameOverState();

    void update();
    void render();

private:
    void init();

private:
    sf::RenderWindow& window;

};