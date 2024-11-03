#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include <vector>
#include "Cell.h"
class Player;
class Board {
public:
    explicit Board(int numberPlayerPlaying);
    Board(const Board &other);
    ~Board();

    void displayBoard() const;
    void placeTile(int x, int y, int idPlayer) const;
    void adjustSize(int numberPlayerPlaying);
    void placeRandomlyBonus(int numberPlayerPlaying);
    void placeTiles(int x, int y, int idPlayer, const std::vector<std::vector<int>> &tiles) const;
    Board &operator=(const Board &other);

    /* ========= Getter ========= */
    [[nodiscard]] bool getIsUsed(int x, int y) const;
    [[nodiscard]] std::vector<Player>& getPlayers() const;

    /* ========= Setter ========= */
    void setIdPlayer(int x, int y, int idPlayer) const;
    void setPlayers (std::vector<Player> *players);

private:
    void createBoard();
    void placeBonusTileExchange(int x, int y) const;
    void placeBonusStone(int x, int y) const;
    void placeBonusRobbery(int x, int y) const;

    int _size;
    Cell **_board{};
    std::vector<std::pair<int, int>> _positionBonus;
    std::vector<Player> *_players;

    friend std::ostream &operator<<(std::ostream &os, const Board &board);
};

#endif
