#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"

class Player {
public:
    Player(int idPlayer, Board& board);
    void placeTile(int x, int y) const;
    void placeTiles(int x, int y, const std::vector<std::vector<int>> &tiles) const;


    void getBoard() const;

private:
    int _idPlayer;
    std::string _name;
    Board& _board;
};



#endif //PLAYER_H
