#include "Player.h"
#include "shapeTile.h"

Player::Player(const int idPlayer, Board& board) : _idPlayer(idPlayer), _name("None"), _board(board) {
    _idPlayer = idPlayer;
    _board = board;
};

void Player::placeTile(const int x, const int y) const {
    _board.placeTile(x, y, _idPlayer);
    _board.setIdPlayer(x, y , _idPlayer);
}

void Player::placeTiles(const int x, const int y, ShapeTile &shapeTile) const {
    _board.placeTiles(x - 1, y - 1, _idPlayer, shapeTile.getTile());
    shapeTile.setPosed(true);
}


/* ========= Getter ========= */
std::string Player::getName() const {
    return _name;
}
void Player::getBoard() const {
    _board.displayBoard();
}
int Player::getIdPlayer() const {
    return _idPlayer;
}

std::string Player::getColor() const {
    return getColorCode(_color);
}

/* ========= Setter ========= */
void Player::setName(const std::string_view &name) {
    _name = name;
}
void Player::setColor(const Color color) {
    _color = color;
}
