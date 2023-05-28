#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Collision.h"
#include "Ship.h"
#include "Util.h"
#include "BulletManager.h"
const static int N = 10;

const static float width  = 800;
const static float height = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), " ", sf::Style::Close);
    window.setFramerateLimit(60);

    Ship ship(50, 50);
    BulletManager bm;

    // ------------------ EVENTS ----------------- //
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();;
        }


        // ----------------- UPDATE ---------------- //

        ship.onCollisionWithWall(isColliding(ship.getShip(), window));
        ship.shipMovement();
        ship.rotationMovement();

        bm.updateBulletCount();
        bm.bulletMovement();


        // ----------------- RENDER --------------- //

        window.clear();
        bm.renderBullet(window);
        ship.render(window);

        window.display();
    }
}