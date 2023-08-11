#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& win)
  : playButton(win),
    exitButton(win),
    m_background(),
    playButText(),
    exitButText()
{
    init();
    m_background.setTexture (&TextureManager::get_background_texture());
    playButton.setButtonText(TextureManager::get_playButton_texture());
    exitButton.setButtonText(TextureManager::get_exitButton_texture());
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
    m_background.setSize(sf::Vector2f(window.getSize()));
    playButton.getButton().setPosition(MIDDLE_OF_SCREEN);
    sf::Vector2f exitButPos(playButton.getButton().getPosition().x, playButton.getButton().getPosition().y + 100.f);
    exitButton.setButtonPos(exitButPos);
    exitButton.getButton().setFillColor(sf::Color::Cyan);
}

void MainMenu::update()
{
    playButton.update();
    exitButton.update();

    if (playButton.isFocused()) {
        playButton.onFocus();
    } else {
        playButton.reset();
    }

    if (exitButton.isFocused()) {
        exitButton.onFocus();
    } else {
        exitButton.reset();
    }
    
    if (playButton.isClicked()) {
        std::cout << "Play clicked!\n";
    }

    if (exitButton.isClicked()) {
        std::cout << "Exiting game!\n";
        window.close();
    }
}

void MainMenu::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(m_background);
    playButton.render();
    exitButton.render();
    window.display();
}