#ifndef GAME_H
#define GAME_H
#include <vector>

#include "Board.h"
#include "MoldTiles.h"
#include "Player.h"
#include "ShapeTile.h"

class Game {
public:
    Game();

    void createMussels();
    void displayMold(int index) const;
    void displayBoard() const;
    void startGame();

    /* Not yet implement */
    int gameLoop();
    void settingGame() const;

    /* ========= Getter ========= */
    [[nodiscard]] int getNumberPlayerPlaying() const;
    [[nodiscard]] Player getPlayer(int index) const;
    [[nodiscard]] ShapeTile getShapeTile(int index) const;

    /* ========= Setter ========= */
    void setNumberPlayerPlaying(int numberPlayerPlaying);
    void setDefaultColor(int numberPlayerPlaying);

private:
    static void clearScreen();

    int _numberPlayerPlaying;
    std::vector<MoldTiles> _mussels;
    std::vector<Player> _players;
    Board _board;

    std::vector<ShapeTile> _shapeTiles = {
        ShapeTile({{0, 0},{1, 0},{1, 1},{1, 2}}),
        ShapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {2, 2}}),
        ShapeTile({{0, 0}, {0,1},{1, 0},{2, 0},{3, 0},{4, 0},{5, 0},{6, 0}})
    };

};


#endif
