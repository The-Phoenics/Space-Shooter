#include "Score.h"

Score::Score()
    : m_text(),
      m_font()
{
    init();
    sf::Vector2f pos(0 + 30.f, 0 + 30.f);
    m_text.setPosition(pos);
    m_text.setCharacterSize(TEXT_SIZE);
}

void Score::init()
{
    if (!m_font.loadFromFile(PATH_TO_FONT)) {
        std::cout << "Failed to load font\n";
    }
    
    m_text.setFont(m_font);
    m_text.setString("Score  " + std::to_string(m_score));
}

void Score::update()
{
    m_text.setString("Score  " + std::to_string(m_score));
}

void Score::render(sf::RenderWindow& window)
{
    window.draw(m_text);
}

void Score::reset()
{
    m_score = 0;
}