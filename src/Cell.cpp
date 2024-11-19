#include "Cell.h"

Cell::Cell() : _isUsed(false), _isTilesPlayer(false), _idPlayer(-1) {
    _bonus.tileExchange = false;
    _bonus.stone = false;
    _bonus.robbery = false;
}
Cell::Cell(const Cell& other) = default;

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        _isUsed = other._isUsed;
        _isTilesPlayer = other._isTilesPlayer;
        _idPlayer = other._idPlayer;
        _bonus = other._bonus;
    }
    return *this;
}

/* ========= Getter ========= */
bool Cell::getIsUsed() const {
    return _isUsed;
}
bool Cell::getIsTilesPlayer() const {
    return _isTilesPlayer;
}
bool Cell::getBonusTileExchange() const {
    return _bonus.tileExchange;
}
bool Cell::getBonusStone() const {
    return _bonus.stone;
}
bool Cell::getBonusRobbery() const {
    return _bonus.robbery;
}
int Cell::getIDPlayer() const {
    return _idPlayer;
}

/* ========= Setter ========= */
void Cell::setUsed(const bool isUsed) {
    _isUsed = isUsed;
}

void Cell::setIdPlayer(const int idPlayer) {
    _idPlayer = idPlayer;
}

void Cell::setTilesPlayer(const bool isTilesPlayer) {
    _isTilesPlayer = isTilesPlayer;
}
void Cell::setBonusTileExchange(const bool bonusTileExchange) {
    _bonus.tileExchange = bonusTileExchange;
}
void Cell::setBonusStone(const bool bonusStone) {
    _bonus.stone = bonusStone;
}
void Cell::setBonusRobbery(const bool bonusRobbery) {
    _bonus.robbery = bonusRobbery;
}