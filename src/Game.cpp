#include "Game.h"

Game::Game() : _numberPlayerPlaying(2), _board(_numberPlayerPlaying) {}

void Game::createMussels() {
    for (const auto& PositionTile : _positionAllTiles) {
        MoldTiles moldTile1(PositionTile);
        _mussels.push_back(moldTile1);
    }
}

void Game::displayMold(const int index) const {
    _mussels[index].displayMold();
}
void Game::displayBoard() const {
    _board.displayBoard();
}


/* ========= Getter ========= */
int Game::getNumberPlayerPlaying() const {
    return _numberPlayerPlaying;
}


/* ========= Setter ========= */
void Game::setNumberPlayerPlaying(const int numberPlayerPlaying) {
    _numberPlayerPlaying = numberPlayerPlaying;
    for (int i = 0; i < numberPlayerPlaying; i++) {
        _players.emplace_back();
    }
    _board.adjustSize(numberPlayerPlaying);
}
