#ifndef CELL_H
#define CELL_H

#include "Player.h"


class Cell {
public:
    Cell();

    /* ========= Getter ========= */
    [[nodiscard]] bool getIsUsed() const;
    [[nodiscard]] bool getIsTilesPlayer() const;

    /* ========= Setter ========= */
    void setUsed(bool isUsed);

private:
    bool _isUsed;
    bool _isTilesPlayer;
    Player _player;
};



#endif //CELL_H
