#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"


class Board {
public:
    explicit Board(int numberPlayerPlaying);

    Board(const Board &other);

    ~Board();

    void displayBoard() const;
    void adjustSize(int numberPlayerPlaying);

private:
    Board &operator=(const Board &other);

    void createBoard();
    int _size;
    Cell **_board{};

    friend std::ostream &operator<<(std::ostream &os, const Board &board);
};



#endif
