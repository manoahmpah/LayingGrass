#ifndef GAME_H
#define GAME_H
#include <vector>

#include "Board.h"
#include "MoldTiles.h"
#include "Player.h"
#include "shapeTile.h"

class Game {
public:
    Game();
    void createMussels();
    void displayMold(int index) const;
    void displayBoard() const;

    void startGame();

    /* ========= Getter ========= */
    [[nodiscard]] int getNumberPlayerPlaying() const;
    [[nodiscard]] Player getPlayer(int index) const;
    [[nodiscard]] shapeTile getShapeTile(int index) const;

    /* ========= Setter ========= */
    void setNumberPlayerPlaying(int numberPlayerPlaying);

private:
    int _numberPlayerPlaying;
    std::vector<MoldTiles> _mussels;
    std::vector<Player> _players;
    Board _board;

    std::vector<shapeTile> _shapeTiles = {
        shapeTile({{0, 0},{1, 0},{1, 1},{1, 2}}),
        shapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {2, 2}}),
        shapeTile({{0, 0}, {0,1},{1, 0},{2, 0},{3, 0},{4, 0},{5, 0},{6, 0}})
    };

};


#endif
