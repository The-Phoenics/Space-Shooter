#include "PauseState.h"

PauseState::PauseState(sf::RenderWindow& win)
    : resumeButton(),
      quitButton(),
      soundOptionButton()
{
    init();
}

void PauseState::update(sf::RenderWindow& window)
{
    resumeButton.update();
    quitButton.update();
    soundOptionButton.update();

    resumeButton.onFocus(window);
    quitButton.onFocus(window);

    if (quitButton.isClicked(window)) {
        window.close();
    }

    if (soundOptionButton.isClicked(window)) {
        soundIsOn = !soundIsOn;
        if (soundIsOn)
            soundOptionButton.setButtonText(TextureManager::getInstance().get_soundEnable_texture());
        else
            soundOptionButton.setButtonText(TextureManager::getInstance().get_soundDisable_texture());
    }
}

void PauseState::render(sf::RenderWindow& window)
{
    // window.clear();
    resumeButton.render(window);
    quitButton.render(window);
    soundOptionButton.render(window);
}

void PauseState::init()
{
    sf::Vector2f buttonSize = { 80.f, 80.f };
    sf::Vector2f centre(MIDDLE_OF_SCREEN.x, MIDDLE_OF_SCREEN.y);
    resumeButton.getButton().setSize(buttonSize);
    resumeButton.getButton().setOrigin(sf::Vector2f(resumeButton.getButton().getSize() / 2.f));
    resumeButton.setButtonPos({centre.x - buttonSize.x / 1.5f, centre.y});

    quitButton.getButton().setSize(buttonSize);
    quitButton.getButton().setOrigin(quitButton.getButton().getSize() / 2.f);
    quitButton.setButtonPos({centre.x + buttonSize.x / 1.5f, centre.y});

    soundOptionButton.getButton().setOrigin(soundOptionButton.getButton().getSize() / 2.f);
    soundOptionButton.setButtonSize(sf::Vector2f(45.f, 45.f));
    soundOptionButton.setButtonPos(sf::Vector2f(WINDOW_WIDTH + 35, 0 + 40.f));

    // Load textures
    resumeButton.setButtonText(TextureManager::getInstance().get_resumeButton_texture());
    quitButton.setButtonText  (TextureManager::getInstance().get_quitButton_texture());
    soundOptionButton.setButtonText(TextureManager::getInstance().get_soundEnable_texture());
}