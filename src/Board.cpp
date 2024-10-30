#include "Board.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

Board::Board(const int numberPlayerPlaying) : _size(20){
    adjustSize(numberPlayerPlaying);
    createBoard();
}

Board::Board(const Board &other) : _size(other._size) {
    createBoard();
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _board[i][j] = other._board[i][j];
        }
    }
}

Board& Board::operator=(const Board &other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < _size; i++) {
        delete[] _board[i];
    }
    delete[] _board;

    _size = other._size;

    createBoard();
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _board[i][j] = other._board[i][j];
        }
    }

    return *this;
}

void Board::createBoard() {
    _board = new Cell*[_size];
    for (int i = 0; i < _size; i++) {
        _board[i] = new Cell[_size];
    }
}

Board::~Board() {
    for (int i = 0; i < _size; i++) {
        delete[] _board[i];
    }
    delete[] _board;
}

void Board::adjustSize(const int numberPlayerPlaying) {
    if (numberPlayerPlaying >= 2 && numberPlayerPlaying <= 4) {
        _size = 20;
    } else if (numberPlayerPlaying >= 5 && numberPlayerPlaying <= 9) {
        _size = 30;
    } else {
        throw std::invalid_argument("Board::adjustSize(const int numberPlayerPlaying) : Invalid number of player");
    }
    createBoard();
}
void Board::displayBoard() const {
    std::cout << *this;
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    for (int i = 0; i < board._size; i++) {
        for (int j = 0; j < board._size; j++) {
            if (board._board[i][j].getIsUsed()) {
                os << "██ ";
            } else {
                os << " . ";
            }
        }
        os << std::endl;
    }
    return os;
}