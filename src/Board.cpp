#include "Board.h"
#ifdef _WIN32
    #include <windows.h>
    #define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
#else
    #define SET_CONSOLE_UTF8
#endif

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

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
    if (numberPlayerPlaying >= 5 && numberPlayerPlaying <= 9) {
        _size = 30;
    } else if (numberPlayerPlaying < 2 || numberPlayerPlaying > 9) {
        throw std::invalid_argument("Board::adjustSize(const int numberPlayerPlaying) : Invalid number of player");
    }
    createBoard();
}
void Board::displayBoard() const {
    std::cout << *this;
}
void Board::placeTile(const int x, const int y, const int idPlayer) const {
    _board[x][y].setUsed(true);
    _board[x][y].setIdPlayer(idPlayer);
}

void Board::placeTiles(const int x, const int y, const int idPlayer, const std::vector <std::vector<int> > &tiles) const {
    for (const auto & tile : tiles) {
        placeTile(tile[0] + x , tile[1] + y, idPlayer);
    }
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
#ifdef _WIN32
    SET_CONSOLE_UTF8
#endif
    for (int i = 0; i < board._size; i++) {
        os << " " << static_cast<char>(65 + i) << " ";
        for (int j = 0; j < board._size; j++) {
            if (board._board[i][j].getIsUsed()) {
                os << "██ ";
            } else {
                os << " . ";
            }
        }
        os << std::endl;

    }
    for (int j = 0; j < board._size; j++) {
        if (j == 0) {
            os << "    " << j + 1 << " ";
        } else if (std::to_string(j).length() == 2) {
            os << j + 1 << " ";
        } else {
            os << " " << j + 1 << " ";
        }
    }
    return os;
}

bool Board::getIsUsed(const int x, const int y) const {
    return _board[x][y].getIsUsed();
}

void Board::setIdPlayer(const int x, const int y, const int idPlayer) const {
    _board[x][y].setIdPlayer(idPlayer);
}
