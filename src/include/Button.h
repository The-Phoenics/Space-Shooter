#pragma once
#include <SFML/Graphics.hpp>
#include "Timer.h"

class Button
{
public:
    Button();
    Button(const sf::Texture& texture);
    ~Button() = default;

    void init();
    void reset();
    bool isClicked(sf::RenderWindow& window);
    bool isFocused(sf::RenderWindow& window);

    sf::RectangleShape& getButton() { return this->button; }

    void setButtonPos (const sf::Vector2f& pos)    { button.setPosition(pos); }
    void setButtonText(const sf::Texture& texture) { button.setTexture(&texture); }
    void setButtonSize(const sf::Vector2f& size)   { button.setSize(size); }

    void update() {
        m_timer.update();
    }
    void render(sf::RenderWindow& window) {
        window.draw(button);
    }

    void onFocus(sf::RenderWindow& window);

private:
    sf::RectangleShape button;
    sf::Texture buttonText;

    Timer m_timer;
};