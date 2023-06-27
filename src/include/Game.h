#pragma once
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "Ship.h"
#include "BulletManager.h"

class Game
{
public:
	Game();
	~Game() {}

	unsigned int getWindowWidth()  const { return m_GameWindow.getSize().x; }
	unsigned int getWindowHeight() const { return m_GameWindow.getSize().y; }

	void run();

private:
	void processEvents();
	void update();
	void render();

public:
    bool isplaying = false;

private:
	sf::RenderWindow m_GameWindow;
    
    Ship m_ship;
	BulletManager m_bulletManager;
};
