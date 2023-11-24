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
    ~PauseState();

    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    inline bool resumeButtonClicked() { return resumeButton.isClicked();      }
    inline bool quitButtonClicked()   { return quitButton.isClicked();        }
    inline bool soundButtonClicked()  { return soundOptionButton.isClicked(); }

public:
    bool soundIsOn = true;

private:
    void setup();

private:
    Button resumeButton;
    Button quitButton;
    Button soundOptionButton;
};