#pragma once
#include <SFML/Graphics.hpp>

class Bar
{
public:
    Bar(float amount = 5.f, float mx = 200.f, float my = 15.f);
    ~Bar() = default;

    void increase();
    void decrease();

    void init();
    void update();
    void render(sf::RenderWindow& window);
    void reset();

    void setAmount  (float amount)      { m_amount = amount; }
    void setColor   (sf::Color color)   { m_bar.setFillColor(color); }
    // void setPosition(sf::Vector2f& pos) {
    //     m_bar.setPosition(pos);
    //     m_bar.setPosition({m_bar.getPosition().x + barOffset / 2.f, m_bar.getPosition().y + barOffset / 2.f});
    //     m_Border.setPosition(pos);    
    // }

    float getBarValue()        const { return m_size.x; }
    sf::Vector2f getPosition() const { return m_bar.getPosition(); }
    float getAmount()          const { return m_amount; }

private:
    float max_x;
    float max_y;

    float m_amount;
    float barOffset;

    sf::RectangleShape m_bar;
    sf::RectangleShape m_Border;
    sf::Vector2f m_size;

};