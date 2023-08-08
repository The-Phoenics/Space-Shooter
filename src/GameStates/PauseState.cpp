#include "include/PauseState.h"

PauseState::PauseState(sf::RenderWindow& win)
    : window(win),
      resumeButton(window),
      quitButton(window),
      soundOptionButton(window)
{
    setup();
}

PauseState::~PauseState()
{
}

void PauseState::update()
{
    // ISSUE: Cannot apply effect on these buttons as window nevers gets cleared in this state
    // for now changed non-clearing of window to clearing window
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
        std::cout << "Quit clicked\n";
        window.close();
    }

    if (soundOptionButton.isClicked()) {
        if (soundIsOn) {
            std::cout << "Disabling sound\n";
            soundOptionButton.setButtonText(TextureManager::get_soundDisable_texture());
            soundIsOn = false;
        }
        else {
            std::cout << "Enabling sound\n";
            soundOptionButton.setButtonText(TextureManager::get_soundEnable_texture());
            soundIsOn = true;
        }
    }
}

void PauseState::render()
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
    soundOptionButton.setButtonPos(sf::Vector2f(WINDOW_WIDTH + 35, 0 + 40.f)); // DBG

    // Load textures
    resumeButton.setButtonText(TextureManager::get_resumeButton_texture());
    quitButton.setButtonText  (TextureManager::get_quitButton_texture());
    soundOptionButton.setButtonText(TextureManager::get_soundEnable_texture());
}