#include <iostream>

#include "Game.h"

int main() {
    Game game;
    game.setNumberPlayerPlaying(3);
    game.getPlayer(0).placeTiles(5, 5, game.getShapeTile(0));
    game.getPlayer(0).placeTiles(2, 6, game.getShapeTile(1));
    game.displayBoard();

    return 0;
}
