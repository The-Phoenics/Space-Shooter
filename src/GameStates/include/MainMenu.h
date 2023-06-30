#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class MainMenu
{
public:
    MainMenu(sf::RenderWindow& win);
    ~MainMenu();
    
    void update();
    void render();

    inline bool isPlayButtonClicked() { return playButton.isClicked(); }

private:
    void init();

private:
    sf::RenderWindow& window;

    sf::RectangleShape m_background;
    Button playButton;
    Button exitButton;
    
    sf::Texture backgroundText;
    sf::Texture playButText;
    sf::Texture exitButText;
};
