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
}

void PauseState::render()
{
    resumeButton.render();
    quitButton.render();
    window.display();
}

void PauseState::setup()
{
    sf::Vector2f centre = sf::Vector2f(400, 300 - 50);
    resumeButton.getButton().setOrigin(sf::Vector2f(resumeButton.getButton().getSize() / 2.f));
    resumeButton.setButtonPos(centre);

    quitButton.getButton().setOrigin(resumeButton.getButton().getSize() / 2.f);
    quitButton.setButtonPos(sf::Vector2f(resumeButton.getButton().getPosition().x, resumeButton.getButton().getPosition().y + 100));

    // Load textures
    resumeButton.setButtonText(TextureManager::get_resumeButton_texture());
    quitButton.setButtonText  (TextureManager::get_quitButton_texture());
}