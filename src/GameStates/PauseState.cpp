#include "include/PauseState.h"

PauseState::PauseState(sf::RenderWindow& win)
    : window(win),
      resumeButton(window),
      quitButton(window)
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
}

void PauseState::render()
{
    window.clear();
    resumeButton.render();
    quitButton.render();
    window.display();
}

void PauseState::setup()
{
    sf::Vector2f centre(MIDDLE_OF_SCREEN.x, MIDDLE_OF_SCREEN.y - 50.f);
    resumeButton.getButton().setOrigin(sf::Vector2f(resumeButton.getButton().getSize() / 2.f));
    resumeButton.setButtonPos(centre);

    quitButton.getButton().setOrigin(resumeButton.getButton().getSize() / 2.f);
    quitButton.setButtonPos(sf::Vector2f(resumeButton.getButton().getPosition().x - 10.f, resumeButton.getButton().getPosition().y + 100));

    // Load textures
    resumeButton.setButtonText(TextureManager::get_resumeButton_texture());
    quitButton.setButtonText  (TextureManager::get_quitButton_texture());
}