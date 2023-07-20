#include "Button.h"

Button::Button(sf::RenderWindow& win)
    : window(win)
{
    init();
}

Button::Button(sf::RenderWindow& win, const sf::Texture& texture)
    : buttonText(texture),
      window(win)
{
    init();
    button.setTexture(&texture);
}

Button::~Button()
{
}

bool Button::isClicked()
{
    if (mouseIsOverButton())
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            return true;

    return false;
}

bool Button::mouseIsOverButton()
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