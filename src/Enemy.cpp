#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow& win)
	: window(win),
	  m_enemy()
{
    m_rotate = random_integer(45, 65) / 100.f;
    float ri = random_integer(111, 185) / 100.f; 
    m_vel    = sf::Vector2f(ri, ri);
    m_size   = random_integer(30, 80);

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
    this->onCollisionWithWall(isColliding(m_enemy, window));
}

void Enemy::render()
{
	window.get().draw(m_enemy);
}

void Enemy::init()
{
	sf::Vector2f pos = randomVector2f(150, 550);
	m_enemy.setRadius(40);
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

void Enemy::onCollisionWithWall(int Collision_Side)
{
    sf::Vector2f pos = m_enemy.getPosition();

    if (pos.y > 600) 
        m_enemy.setPosition(pos.x, 0);
    if (pos.y < 0)
        m_enemy.setPosition(pos.x, 600);
    if (pos.x > 800)
        m_enemy.setPosition(0, pos.y);
    if (pos.x < 0)
        m_enemy.setPosition(800, pos.x);
}
