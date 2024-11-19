#include "ShapeTile.h"

ShapeTile::ShapeTile(const std::vector <std::vector <int> > &tile) : _tile(tile), _isPosed(false) {}

bool ShapeTile::getIsPosed() const {
    return _isPosed;
}

std::vector<std::vector<int>> ShapeTile::getTile() const {
    return _tile;
}

void ShapeTile::setPosed(const bool isPosed) {
    _isPosed = isPosed;
}
