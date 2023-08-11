#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "DEFINES.h"

class Score
{    
public:
    Score();
    ~Score() { }

    void init();

    void update();
    void  render(sf::RenderWindow& window);
    void reset();

    void increaseScore(int n = 5) { m_score += n; }
    void decreaseScore(int n = 5) { m_score -= n; }

    void setPosition(sf::Vector2f& pos)  { m_text.setPosition(pos); }
    sf::Vector2f getPosition() const { return m_text.getPosition(); }

private:
    unsigned int m_score { 0 };
    sf::Text m_text;
    sf::Font m_font;
};