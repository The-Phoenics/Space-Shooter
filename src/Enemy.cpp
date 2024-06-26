#include "Enemy.h"

Enemy::Enemy()
	: m_enemy()
{
    sf::Vector2f dir = randomVector2f(-360, 360);
	m_dir = normalize(dir);

	init();
}

void Enemy::update()
{
	this->move();
    this->rotate();
    this->onCollisionWithWall();
}

void Enemy::render(sf::RenderWindow& window)
{
	window.draw(m_enemy);
}

void Enemy::reduceHealth() { 
    if (m_health > 0)
    {
        --m_health;
        // enemy becomes darker as health drops
        sf::Color color = m_enemy.getFillColor();
        color.r -= 30;
        color.g -= 30;
        color.b -= 30;
        m_enemy.setFillColor(color);
    }
    if (m_health <= 0)
        isAlive = false;
}

void Enemy::init()
{
    m_rotate  = random_integer(45, 65)   / 100.f;
    float vel = random_integer(111, 185) / 100.f; 
    m_vel     = sf::Vector2f(vel, vel);
    m_size    = random_integer(40, 60); // radius

	sf::Vector2f pos(0.f, 0.f);
    pos.x = random_integer(m_size, WINDOW_WIDTH);
    if (random_integer(1, 10) % 2)
        pos.y = random_integer(WINDOW_HEIGHT - WINDOW_HEIGHT / 3, WINDOW_HEIGHT);
    else 
        pos.y = random_integer(m_size, WINDOW_HEIGHT - WINDOW_HEIGHT / 5);
    
	m_enemy.setRadius(m_size);
	m_enemy.setPosition(pos);
	m_enemy.setOrigin(sf::Vector2f(m_enemy.getRadius(), m_enemy.getRadius()));
	m_enemy.setTexture(&TextureManager::getInstance().get_asteroid_texture());
}

void Enemy::move()
{
	sf::Vector2f currentPos = m_enemy.getPosition();
	m_enemy.setPosition(currentPos + (m_dir * m_vel));
}

void Enemy::rotate()
{
    m_enemy.rotate(m_rotate);
}

void Enemy::onCollisionWithWall()
{
    sf::Vector2f pos = m_enemy.getPosition();

    if (pos.y > WINDOW_HEIGHT + 50)
        m_enemy.setPosition(pos.x, 0 - 50);
    if (pos.y < 0 - 50)
        m_enemy.setPosition(pos.x, WINDOW_HEIGHT + 50);
    if (pos.x > WINDOW_WIDTH + 50)
        m_enemy.setPosition(0 - 50, pos.y);
    if (pos.x < 0 - 50)
        m_enemy.setPosition(WINDOW_WIDTH + 50, pos.x);
}
