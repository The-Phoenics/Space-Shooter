#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow& win)
	: window(win),
	  m_enemy()
{
    sf::Vector2f dir = randomVector2f(-360, 360);
	m_dir = normalize(dir);

	init();
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	this->move();
    this->rotate();
    this->onCollisionWithWall();
}

void Enemy::render()
{
	window.get().draw(m_enemy);
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
    m_rotate = random_integer(45, 65) / 100.f;
    float ri = random_integer(111, 185) / 100.f; 
    m_vel    = sf::Vector2f(ri, ri);
    m_size   = random_integer(40, 60);
	sf::Vector2f pos = randomVector2f(100, 800);
    
	m_enemy.setRadius(m_size);
	m_enemy.setPosition(pos);
	m_enemy.setOrigin(sf::Vector2f(m_enemy.getRadius(), m_enemy.getRadius()));
	m_enemy.setTexture(&TextureManager::get_asteroid_texture());
}

void Enemy::move()
{
	sf::Vector2f currentPos = m_enemy.getPosition();
	m_enemy.setPosition(currentPos + (m_dir * m_vel));
}

void Enemy::rotate()
{
    this->m_enemy.rotate(this->m_rotate);
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
