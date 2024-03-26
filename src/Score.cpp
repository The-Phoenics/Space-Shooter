#include "Score.h"
#include "DEFINES.h"

Score::Score()
    : m_text(),
      m_font()
{
    init();
    m_text.setPosition({25.f, 10.f});
    m_text.setCharacterSize(30.f);
}

void Score::init()
{
    if (!m_font.loadFromFile("../res/font/GAMERIA.ttf")) {
        std::cout << "Failed to load font\n";
    }

    m_text.setFont(m_font);
    m_text.setString(std::to_string(m_score));
}

void Score::update()
{
    m_text.setString(std::to_string(m_score));
}

void Score:: render(sf::RenderWindow& window)
{
    window.draw(m_text);
}

void Score::reset()
{
    m_score = 0;
}