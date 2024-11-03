#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "ShapeTile.h"
#include "Color.h"
#include "Board.h"

class Player {
public:
    Player(int idPlayer, Board& board);

    void placeTile(int x, int y) const;
    void placeTiles(int x, int y, ShapeTile &shapeTile) const;

    /* ========= Getter ========= */
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getIdPlayer() const;
    void getBoard() const;
    [[nodiscard]] std::string getColor() const;

    /* ========= Setter ========= */
    void setName(const std::string_view &name);
    void setColor(Color color);

private:
    int _idPlayer;
    std::string _name;
    Board& _board;
    Color _color;
};

#endif
