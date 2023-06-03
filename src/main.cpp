#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "include/Collision.h"
#include "include/Ship.h"
#include "include/Util.h"
#include "include/BulletManager.h"

const static float width  = 800;
const static float height = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Space-Shooter", sf::Style::Close);
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
                window.close();
        }


        // ----------------- UPDATE ---------------- //

        ship.onCollisionWithWall(isColliding(ship.getShip(), window));
        ship.shipMovement();
        ship.rotationMovement();
        ship.calcFacingDir();

        bm.updateBulletCount(ship);
        bm.bulletsMovement();              //////////////////


        // ----------------- RENDER --------------- //

        window.clear();
        bm.renderBullet(window);
        ship.render(window);

        window.display();
    }
}