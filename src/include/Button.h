#pragma once
#include <SFML/Graphics.hpp>
#include "Timer.h"

class Button
{
public:
    Button(sf::RenderWindow& win);
    Button(sf::RenderWindow& win, const sf::Texture& texture);
    ~Button();

    void init();
    void reset();
    bool isClicked();
    bool isFocused();

    sf::RectangleShape& getButton() { return this->button; }

    inline void setButtonPos (const sf::Vector2f& pos)    { button.setPosition(pos); }
    inline void setButtonText(const sf::Texture& texture) { button.setTexture(&texture); }
    inline void setButtonSize(const sf::Vector2f& size)   { button.setSize(size); }

    inline void update() { m_timer.update(); }
    inline void render() { window.draw(this->button); }

    void onFocus();
    void fadeOut();

private:
    sf::RenderWindow& window;
    sf::RectangleShape button;
    sf::Texture buttonText;

    Timer m_timer;
};