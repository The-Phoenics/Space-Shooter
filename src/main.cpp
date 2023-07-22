#include "Game.h"
#include "DEFINES.h"

// window
extern sf::RenderWindow window;

int main()
{    
    Game game(window);
    game.run();
}