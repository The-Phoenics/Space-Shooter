#include "Button.h"
#include "Util.h"

Button::Button()
    : m_timer(0.5f)
{
    init();
    m_timer.start();
}

Button::Button(const sf::Texture &texture)
    : buttonText(texture),
      m_timer(0.5f)
{
    init();
    button.setTexture(&texture);
    m_timer.start();
}

void Button::onFocus(sf::RenderWindow& window)
{
    if (isFocused(window))
    {
        sf::Vector2f pos = button.getPosition();
        float scaleFactor = 0.05f;
        button.setScale(1.f + scaleFactor, 1.f + scaleFactor);
        button.setPosition({button.getPosition().x + button.getPosition().x * scaleFactor / 2.f, button.getPosition().y + button.getPosition().y * scaleFactor / 2.f});
        button.setPosition(pos);
        button.setFillColor(sf::Color::Cyan);
    }
    else
    {
        reset();
    }
}

bool Button::isClicked(sf::RenderWindow& window)
{
    if (m_timer.getElapsedTime() >= 0.6f)
    {
        if (isFocused(window))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_timer.reset();
                return true;
            }
        }
    }
    return false;
}

bool Button::isFocused(sf::RenderWindow& window)
{
    sf::Vector2f mousePos = {
        static_cast<float>(sf::Mouse::getPosition(window).x),
        static_cast<float>(sf::Mouse::getPosition(window).y)
    };
    return button.getGlobalBounds().contains(mousePos);
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