#include "Button.h"

Button::Button(sf::RenderWindow& win)
    : window(win),
      m_timer(0.5f)
{
    init();
    m_timer.start();
}

Button::Button(sf::RenderWindow& win, const sf::Texture& texture)
    : buttonText(texture),
      window(win),
      m_timer(0.5f)
{
    init();
    button.setTexture(&texture);
    m_timer.start();
}

Button::~Button()
{
}

void Button::onFocus()
{
    sf::Vector2f pos = button.getPosition();
    this->button.setScale(1.2f, 1.2f);
    this->button.setPosition(pos);
    this->button.setFillColor(sf::Color::Cyan);
}

bool Button::isClicked()
{
    if (m_timer.getElapsedTime() >= 0.6f) {
        if (isFocused()) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                m_timer.reset();
                return true;
            }
        }
    }
    return false;
}

bool Button::isFocused()
{
    return (button.getGlobalBounds().contains(
        sf::Mouse::getPosition(window).x,
        sf::Mouse::getPosition(window).y)
    );
}

void Button::init()
{
    button = sf::RectangleShape();
    button.setPosition(sf::Vector2f(400, 300));
    button.setSize(sf::Vector2f(200.f, 50.f));
    
    sf::Vector2f centre = sf::Vector2f(button.getSize().x / 2.f, button.getSize().x / 2.f);
    button.setOrigin(centre);
}

void Button::reset()
{
    button.setScale(1.f, 1.f);
    button.setFillColor(sf::Color::White);
}