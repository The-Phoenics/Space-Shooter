#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "include/Game.h"
#include "include/Collision.h"
#include "include/Ship.h"
#include "include/Util.h"
#include "include/BulletManager.h"

int main()
{
    Game game;
    game.isplaying = true;

    if (game.isplaying)
        game.run();
    else {
        // Render Game Menu
    }
}