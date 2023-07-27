#include "GameOverState.h"

GameOverState::GameOverState(sf::RenderWindow& win)
    : window(win)
{
    init();
}

void GameOverState::init()
{
    if (!m_gameOverFont.loadFromFile(PATH_TO_FONT)) {
        std::cout << "Failed to load font\n";
    }

    float gameOverCharSize = 60.f;
    m_gameOver.setFont(m_gameOverFont);
    m_gameOver.setString("Game Over");
    m_gameOver.setCharacterSize(gameOverCharSize);
    m_gameOver.setPosition(MIDDLE_OF_SCREEN.x - (gameOverCharSize * 7) / 2.f, MIDDLE_OF_SCREEN.y - (gameOverCharSize * 2) / 2.f);

    float playAgainCharSize = 20.f;
    m_playAgain.setFont(m_gameOverFont);
    m_playAgain.setString("Press Enter to play again");
    m_playAgain.setCharacterSize(playAgainCharSize);
    m_playAgain.setPosition(MIDDLE_OF_SCREEN.x - (playAgainCharSize * 19) / 2.f, MIDDLE_OF_SCREEN.y - (playAgainCharSize * 3) + 80.f);
}

void GameOverState::update()
{
}

void GameOverState::render()
{
    window.clear();
    window.draw(m_gameOver);
    window.draw(m_playAgain);
    window.display();
}