#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "TextureManager.h"
#include "DEFINES.h"

class MainMenu
{
public:
    MainMenu(sf::RenderWindow& win);
    ~MainMenu();
    
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    inline bool isPlayButtonClicked() { return playButton.isClicked(); }

private:
    void init();

private:
    sf::RectangleShape m_background;
    Button playButton;
    Button exitButton;
    
    sf::Texture backgroundText;
    sf::Texture playButText;
    sf::Texture exitButText;
};
