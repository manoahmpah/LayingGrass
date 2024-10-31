#include "shapeTile.h"
shapeTile::shapeTile(const std::vector <std::vector <int> > &tile) : _tile(tile), _isPosed(false) {}

bool shapeTile::getIsPosed() const {
    return _isPosed;
}

std::vector<std::vector<int>> shapeTile::getTile() const {
    return _tile;
}

void shapeTile::setPosed(const bool isPosed) {
    _isPosed = isPosed;
}