#include "Game.h"

#include <iostream>

Game::Game() : _numberPlayerPlaying(2), _board(_numberPlayerPlaying) {
    createMussels();
}

void Game::createMussels() {
    for (const auto& PositionTile : _shapeTiles) {
        MoldTiles moldTile1(PositionTile.getTile());
        _mussels.push_back(moldTile1);
    }
}

void Game::displayMold(const int index) const {
    _mussels[index].displayMold();
}
void Game::displayBoard() const {
    _board.displayBoard();
}
void Game::startGame() {
    setNumberPlayerPlaying(9);
    _board.placeRandomlyBonus(getNumberPlayerPlaying());
    _players[0].placeTiles(5, 5, _shapeTiles[0]);
    _players[0].placeTiles(9, 9, _shapeTiles[1]);

    displayBoard();
}

/* ========= Getter ========= */
int Game::getNumberPlayerPlaying() const {
    return _numberPlayerPlaying;
}
Player Game::getPlayer(const int index) const {
    return _players[index];
}

ShapeTile Game::getShapeTile(const int index) const {
    return _shapeTiles[index];
}


/* ========= Setter ========= */
void Game::setNumberPlayerPlaying(const int numberPlayerPlaying) {
    _numberPlayerPlaying = numberPlayerPlaying;
    for (int i = 0; i < numberPlayerPlaying; i++) {
        _players.emplace_back(i+1, _board);
    }
    _board.adjustSize(numberPlayerPlaying);
}
