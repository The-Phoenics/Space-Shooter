#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& win)
  : playButton(),
    exitButton(),
    m_background(),
    playButText(),
    exitButText()
{
    init();
    m_background.setTexture (&TextureManager::getInstance().get_background_texture());
    playButton.setButtonText(TextureManager::getInstance().get_playButton_texture());
    exitButton.setButtonText(TextureManager::getInstance().get_exitButton_texture());
}

void MainMenu::init()
{
    m_background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    playButton.getButton().setPosition(MIDDLE_OF_SCREEN);
    sf::Vector2f exitButPos(playButton.getButton().getPosition().x, playButton.getButton().getPosition().y + 100.f);
    exitButton.setButtonPos(exitButPos);
    exitButton.getButton().setFillColor(sf::Color::Cyan);
}

void MainMenu::update(sf::RenderWindow& window)
{
    playButton.update();
    exitButton.update();

    playButton.onFocus(window);
    exitButton.onFocus(window);

    if (exitButton.isClicked(window)) {
        std::cout << "Exiting game!\n";
        window.close();
    }
}

void MainMenu::render(sf::RenderWindow& window)
{
    window.clear();
    window.draw(m_background);
    playButton.render(window);
    exitButton.render(window);
    window.display();
}