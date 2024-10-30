#include <iostream>

#include "Game.h"

int main() {
    Game game;
    game.setNumberPlayerPlaying(3);
    game.getPlayer(0).placeTile(0, 1);
    game.displayBoard();

    return 0;
}
