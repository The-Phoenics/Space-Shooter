#include "include/MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& win)
  : window(win),
    playButton(window),
    exitButton(window),
    m_background(),
    playButText(),
    exitButText()
{
    init();
    m_background.setTexture (&backgroundText);
    playButton.setButtonText(playButText);
    exitButton.setButtonText(exitButText);
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
    m_background.setSize(sf::Vector2f(window.getSize()));
    sf::Vector2f exitButPos(playButton.getButton().getPosition().x, playButton.getButton().getPosition().y + 100.f);
    exitButton.setButtonPos(exitButPos);
    exitButton.getButton().setFillColor(sf::Color::Cyan);

    backgroundText.loadFromFile("/home/prime/Desktop/Space-Shooter/res/background.png");
    playButText.loadFromFile   ("/home/prime/Desktop/Space-Shooter/res/playButton.png");
    exitButText.loadFromFile   ("/home/prime/Desktop/Space-Shooter/res/exitButton.png");
}

void MainMenu::update()
{
    if (playButton.isClicked()) {
        std::cout << "Play clicked!\n";
    }

    if (exitButton.isClicked()) {
        std::cout << "Exiting the Game ...\n";
        window.close();
    }
}

void MainMenu::render()
{
    window.clear();
    //window.draw(m_background);
    playButton.render();
    exitButton.render();
    window.display();
}