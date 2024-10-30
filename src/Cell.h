#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell();

    /* ========= Getter ========= */
    [[nodiscard]] bool getIsUsed() const;
    [[nodiscard]] bool getIsTilesPlayer() const;
    bool getPlayer();

    /* ========= Setter ========= */
    void setUsed(bool isUsed);
    void setIdPlayer(int idPlayer);

private:
    bool _isUsed;
    bool _isTilesPlayer;
    int _idPlayer{};
};


#endif
