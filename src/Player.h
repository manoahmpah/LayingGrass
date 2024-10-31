#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"
#include "ShapeTile.h"

class Player {
public:
    Player(int idPlayer, Board& board);
    void placeTile(int x, int y) const;
    void placeTiles(int x, int y, ShapeTile &shapeTile) const;

    /* ========= Getter ========= */
    void getBoard() const;

private:
    int _idPlayer;
    std::string _name;
    Board& _board;
};



#endif //PLAYER_H
