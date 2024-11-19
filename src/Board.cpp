#include "Board.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

#include "Player.h"

#ifdef _WIN32
    #include <windows.h>
    #define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
#else
    #define SET_CONSOLE_UTF8
#endif



Board::Board(const int numberPlayerPlaying) : _size(20){
    adjustSize(numberPlayerPlaying);
    createBoard();

}
Board::Board(const Board &other) : _size(other._size), _players(other._players) {
    createBoard();
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _board[i][j] = other._board[i][j];
        }
    }

}


Board &Board::operator=(const Board &other) {
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

    _players = other._players;

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
    } else {
        _size = 20;
    }
}
void Board::displayBoard() const {
    std::cout << *this;
}
void Board::placeTile(const int x, const int y, const int idPlayer) const {
    _board[x][y].setUsed(true);
    _board[x][y].setIdPlayer(idPlayer);
    _board[x][y].setTilesPlayer(true);
}

void Board::placeBonusTileExchange(const int x, const int y) const {
    _board[x][y].setUsed(true);
    _board[x][y].setBonusTileExchange(true);
}

void Board::placeBonusStone(const int x, const int y) const {
    _board[x][y].setUsed(true);
    _board[x][y].setBonusStone(true);
}

void Board::placeBonusRobbery(const int x, const int y) const {
    _board[x][y].setUsed(true);
    _board[x][y].setBonusRobbery(true);
}

#include <functional>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

void Board::placeRandomlyBonus(const int numberPlayerPlaying) {

    const std::vector<int> numberEachBonus = {static_cast<int>(numberPlayerPlaying * 0.5), numberPlayerPlaying, static_cast<int>(numberPlayerPlaying * 1.5)};

    const std::vector<std::function<void(int, int)>> functionBonusPos = {
        [this](const int x, const int y) { placeBonusStone(x, y); },
        [this](const int x, const int y) { placeBonusRobbery(x, y); },
        [this](const int x, const int y) { placeBonusTileExchange(x, y); }
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, _size - 2);

    for (size_t i = 0; i < numberEachBonus.size(); i++) {
        const int numberBonus = numberEachBonus[i];

        for (int j = 0; j < numberBonus; j++) {
            int x; int y;
            do {
                x = dis(gen);
                y = dis(gen);
            } while (std::find(_positionBonus.begin(), _positionBonus.end(), std::make_pair(x, y)) != _positionBonus.end());

            _positionBonus.emplace_back(x, y);
            functionBonusPos[i](x, y);
        }
    }
}



void Board::placeTiles(const int x, const int y, const int idPlayer, const std::vector <std::vector<int> > &tiles) const {
    for (const auto & tile : tiles) {
        if (x + tile[0] < 0 || x + tile[0] >= _size || y + tile[1] < 0 || y + tile[1] >= _size) {
            throw std::out_of_range("Board::placeTiles(const int x, const int y, const int idPlayer, const std::vector<std::vector<int>> &tiles) : Out of range");
        }
        if (_board[x + tile[0]][y + tile[1]].getIsUsed()) {
            throw std::invalid_argument("Board::placeTiles(const int x, const int y, const int idPlayer, const std::vector<std::vector<int>> &tiles) : Cell already used");
        }
    }
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
                if (board._board[i][j].getIsTilesPlayer()) {
                    os << (*board._players)[board._board[i][j].getIDPlayer()-1].getColor() << "▄▄ " << "\033[0m";
                } else if (board._board[i][j].getBonusTileExchange()) {
                    os << " ↺ ";
                } else if (board._board[i][j].getBonusStone()) {
                    os << "🪨 ";
                } else if (board._board[i][j].getBonusRobbery()) {
                    os << "🕳️ ";
                }
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
std::vector<Player>& Board::getPlayers() const {
    return *_players;
}

void Board::setIdPlayer(const int x, const int y, const int idPlayer) const {
    _board[x][y].setIdPlayer(idPlayer);
}
void Board::setPlayers(std::vector<Player> *players) {
    _players = players;
}

int Board::getSize() const {
    return _size;
}

int Board::getIDPlayer(const int x, const int y) const {
    return _board[x][y].getIDPlayer();
}