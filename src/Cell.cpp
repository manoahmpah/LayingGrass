#include "Cell.h"


Cell::Cell() : _isUsed(false), _isTilesPlayer(false) {}


/* ========= Getter ========= */
bool Cell::getIsUsed() const {
    return _isUsed;
}
bool Cell::getIsTilesPlayer() const {
    return _isTilesPlayer;
}

/* ========= Setter ========= */
void Cell::setUsed(const bool isUsed) {
    _isUsed = isUsed;
}