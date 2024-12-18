#include "Board.h"
#include "Player.h"
#include "shapeTile.h"

Player::Player(const int idPlayer, Board& board) : _idPlayer(idPlayer), _name("None"), _board(board) {
    _idPlayer = idPlayer;
    _board = board;
};

Player::Player(const Player& other)
    : _idPlayer(other._idPlayer),     // Copie de l'ID du joueur
      _name(other._name),             // Copie du nom du joueur
      _board(other._board),           // Garde la même référence de board
      _color(other._color)            // Copie de la couleur du joueur
{
    // Pas d'autres actions nécessaires
}

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
    if (name.empty()) {
        throw std::invalid_argument("Player::setName(const std::string_view &name) : Name cannot be empty");
    }
    if (name.length() > 10) {
        throw std::invalid_argument("Player::setName(const std::string_view &name) : Name cannot be more than 10 characters");
    }
    _name = name;
}
void Player::setColor(const Color color) {
    _color = color;
}
