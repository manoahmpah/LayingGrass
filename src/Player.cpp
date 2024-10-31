#include "Player.h"
#include "shapeTile.h"

Player::Player(const int idPlayer, Board& board) : _idPlayer(idPlayer), _name("Player"), _board(board) {
    _idPlayer = idPlayer;
    _board = board;
};

void Player::placeTile(const int x, const int y) const {
    _board.placeTile(x, y, _idPlayer);
    _board.setIdPlayer(x, y , _idPlayer);
}

void Player::placeTiles(const int x, const int y, shapeTile &shapeTile) const {
    _board.placeTiles(x - 1, y - 1, _idPlayer, shapeTile.getTile());
    shapeTile.setPosed(true);
}

void Player::getBoard() const {
    _board.displayBoard();
}