#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "TextureManager.h"

class PauseState
{
public:
    PauseState(sf::RenderWindow& win);
    ~PauseState();

    void update();
    void render();

    inline bool resumeButtonClicked() { return resumeButton.isClicked(); }
    inline bool quitButtonClicked()   { return quitButton.isClicked(); }

private:
    void setup();

private:
    sf::RenderWindow& window;

    Button resumeButton;
    Button quitButton;

    sf::Texture resumeButText;
    sf::Texture quitButText;
};