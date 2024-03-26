#include "Bar.h"
#include "TextureManager.h"
#include "DEFINES.h"

Bar::Bar(float amount, float mx, float my)
    : max_x(mx), max_y(my),
      m_size(max_x, max_y),
      m_amount(amount),
      barOffset(4.f)
{
    init();
}

void Bar::init()
{
    m_bar.setSize({m_size.x - barOffset, m_size.y - barOffset});
    m_bar.setPosition({WINDOW_WIDTH - (20.f + m_size.x), 0 + 16.f});
    m_bar.setTexture(&TextureManager::getInstance().get_hbar_texture());

    m_Border.setSize(m_size);
    m_Border.setPosition(m_bar.getPosition());
    m_Border.setTexture(&TextureManager::getInstance().get_barborder_texture());
    m_bar.setPosition({m_bar.getPosition().x + barOffset / 2.f, m_bar.getPosition().y + barOffset / 2.f});
}

void Bar::update()
{
    m_bar.setSize({m_size.x - barOffset, m_size.y - barOffset});
}

void Bar::reset()
{
    m_size.x = max_x;
    m_size.y = max_y;
    m_bar.setSize(m_size);
}

void Bar::increase()
{
    if (m_size.x < max_x)
        m_size.x += m_amount;
}

void Bar::decrease()
{
    if (m_size.x > 0.0f)
        m_size.x -= m_amount;
}

void Bar:: render(sf::RenderWindow& window)
{
    window.draw(m_Border);
    window.draw(m_bar);
}