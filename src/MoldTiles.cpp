#ifdef _WIN32
#include <windows.h>
#define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
#else
#define SET_CONSOLE_UTF8
#endif
#include "MoldTiles.h"
#include <iostream>
#include <memory>

#include "Color.h"

/* ========= Constructor & Destructor ========= */
MoldTiles::MoldTiles(const std::vector <std::vector <int> > &tiles) : _mold(nullptr), _size(7) {
    createMold();
    addTiles(tiles);
}
MoldTiles::~MoldTiles() {
    for (int i = 0; i < _size; i++) {
        delete[] _mold[i];
    }
    delete[] _mold;
}

/* ========= Method ========= */
void MoldTiles::createMold() const {
    _mold = new Cell *[_size];
    for (int i = 0; i < _size; i++) {
        _mold[i] = new Cell[_size];
    }
}
void MoldTiles::displayMold() const {
    #ifdef _WIN32
        SET_CONSOLE_UTF8
    #endif
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (_mold[i][j].getIsUsed()) {
                std::cout << "██ ";
            } else {
                std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
}
void MoldTiles::addTile(const int x, const int y) const {
    if (x < 0 || x >= _size || y < 0 || y >= _size) {
        throw std::out_of_range("MoldTiles::addCell(const int x, const int y) : Out of range");
    }
    _mold[x][y].setUsed(true);
}
void MoldTiles::addTiles(const std::vector <std::vector <int> > &tiles) const {
    for (const auto & tile : tiles) {
        addTile(tile[0], tile[1]);
        _mold[tile[0]][tile[1]].setTilesPlayer(true);
    }
}
MoldTiles::MoldTiles(const MoldTiles& other) : _size(other._size) {
    _mold = new Cell*[_size];
    for (int i = 0; i < _size; ++i) {
        _mold[i] = new Cell[_size];
        for (int j = 0; j < _size; ++j) {
            _mold[i][j] = other._mold[i][j];
        }
    }
}
MoldTiles& MoldTiles::operator=(const MoldTiles& other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < _size; ++i) {
        delete[] _mold[i];
    }
    delete[] _mold;

    _size = other._size;

    _mold = new Cell*[_size];
    for (int i = 0; i < _size; ++i) {
        _mold[i] = new Cell[_size];
        for (int j = 0; j < _size; ++j) {
            _mold[i][j] = other._mold[i][j];
        }
    }
    return *this;
}

/* ========= Getter ========= */
Cell** MoldTiles::getMold() const {
    return _mold;
}
int MoldTiles::getSize() const {
    return _size;
}

void MoldTiles::rotateMold() {
    auto rotatedMold = std::make_unique<std::unique_ptr<Cell[]>[]>(_size);
    for (int i = 0; i < _size; ++i) {
        rotatedMold[i] = std::make_unique<Cell[]>(_size);
    }
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            rotatedMold[j][_size - 1 - i] = _mold[i][j];
        }
    }
    // Libérer la mémoire de l’ancien _mold
    if (_mold != nullptr) {
        for (int i = 0; i < _size; ++i) {
            delete[] _mold[i];
        }
        delete[] _mold;
    }
    _mold = new Cell*[_size];
    for (int i = 0; i < _size; ++i) {
        _mold[i] = rotatedMold[i].release();
    }
}

// MoldTiles.cpp
void MoldTiles::flipMold() const {
    if (_mold == nullptr || _size <= 0) {
        throw std::runtime_error("Mold is not initialized properly");
    }

    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size / 2; ++j) {
            std::swap(_mold[i][j], _mold[i][_size - 1 - j]);
        }
    }
}
bool MoldTiles::isUsed() const {
    // Parcourt toutes les cellules du _mold
    for (int i = 0; i < getSize(); i++) {
        for (int j = 0; j < getSize(); j++) {
            // Si au moins une cellule est marquée comme utilisée
            if (_mold[i][j].getIsUsed()) {
                return true; // La tuile entière est considérée comme utilisée
            }
        }
    }
    return false; // Toutes les cellules sont inutilisées
}

