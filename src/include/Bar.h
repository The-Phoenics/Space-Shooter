#pragma once
#include <SFML/Graphics.hpp>

class Bar
{
public:
    Bar(float amount = 5.f, float mx = 200.f, float my = 15.f);
    ~Bar() { }

    void increase();
    void decrease();

    void init();
    void update();
    void render(sf::RenderWindow& window);
    void reset();

    void setAmount  (float amount)      { m_amount = amount; }
    void setPosition(sf::Vector2f& pos) { m_bar.setPosition(pos); }
    void setColor   (sf::Color color)   { m_bar.setFillColor(color); }

    float getBarValue()        const { return m_size.x; }
    sf::Vector2f getPosition() const { return m_bar.getPosition(); }
    float getAmount()          const { return m_amount; }

private:
    float max_x;
    float max_y;

    float m_amount;

    sf::RectangleShape m_bar;
    sf::Vector2f m_size;

};