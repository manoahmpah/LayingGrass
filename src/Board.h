#ifndef BOARD_H
#define BOARD_H
#include <ostream>

#include "Cell.h"


class Board {
public:
    explicit Board(int numberPlayerPlaying);

    Board(const Board &other);

    ~Board();

    void displayBoard() const;
    void placeTile(int x, int y) const;
    void adjustSize(int numberPlayerPlaying);
    Board &operator=(const Board &other);

    [[nodiscard]] bool getIsUsed(int x, int y) const;

    void setIdPlayer(int x, int y, int idPlayer) const;

private:
    void createBoard();
    int _size;
    Cell **_board{};

    friend std::ostream &operator<<(std::ostream &os, const Board &board);
};



#endif
