#include "PauseState.h"

PauseState::PauseState(sf::RenderWindow& win)
    : resumeButton(win),
      quitButton(win),
      soundOptionButton(win)
{
    setup();
}

PauseState::~PauseState()
{
}

void PauseState::update()
{
    resumeButton.update();
    quitButton.update();
    soundOptionButton.update();

    if (resumeButton.isFocused()) {
        resumeButton.onFocus();
    } else {
        resumeButton.reset();
    }

    if (quitButton.isFocused()) {
        quitButton.onFocus();
    } else {
        quitButton.reset();
    }
    
    if (resumeButton.isClicked()) {
        std::cout << "Resume clicked!\n";
    }

    if (quitButton.isClicked()) {
        std::cout << "Quit clicked!\n";
        window.close();
    }

    if (soundOptionButton.isClicked()) {
        if (soundIsOn) {
            std::cout << "Disabling sound!\n";
            soundOptionButton.setButtonText(TextureManager::get_soundDisable_texture());
            soundIsOn = false;
        }
        else {
            std::cout << "Enabling sound!\n";
            soundOptionButton.setButtonText(TextureManager::get_soundEnable_texture());
            soundIsOn = true;
        }
    }
}

void PauseState::render(sf::RenderWindow& window)
{
    window.clear();
    resumeButton.render();
    quitButton.render();
    soundOptionButton.render();
    window.display();
}

void PauseState::setup()
{
    sf::Vector2f centre(MIDDLE_OF_SCREEN.x, MIDDLE_OF_SCREEN.y - 50.f);
    resumeButton.getButton().setOrigin(sf::Vector2f(resumeButton.getButton().getSize() / 2.f));
    resumeButton.setButtonPos(centre);

    quitButton.getButton().setOrigin(quitButton.getButton().getSize() / 2.f);
    quitButton.setButtonPos(sf::Vector2f(resumeButton.getButton().getPosition().x - 10.f, resumeButton.getButton().getPosition().y + 100));

    soundOptionButton.getButton().setOrigin(soundOptionButton.getButton().getSize() / 2.f);
    soundOptionButton.setButtonSize(sf::Vector2f(45.f, 45.f));
    soundOptionButton.setButtonPos(sf::Vector2f(WINDOW_WIDTH + 35, 0 + 40.f));

    // Load textures
    resumeButton.setButtonText(TextureManager::get_resumeButton_texture());
    quitButton.setButtonText  (TextureManager::get_quitButton_texture());
    soundOptionButton.setButtonText(TextureManager::get_soundEnable_texture());
}