#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "TextureManager.h"
#include "DEFINES.h"
#include "Util.h"

class PauseState
{
public:
    PauseState(sf::RenderWindow& win);
    ~PauseState() = default;

    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    bool resumeButtonClicked(sf::RenderWindow& window){
        return resumeButton.isClicked(window);
    }

    bool quitButtonClicked(sf::RenderWindow& window)  {
        return quitButton.isClicked(window);
    }

    bool soundButtonClicked(sf::RenderWindow& window) {
        return soundOptionButton.isClicked(window);
    }


public:
    bool soundIsOn = true;

private:
    void init();

private:
    Button resumeButton;
    Button quitButton;
    Button soundOptionButton;
};