#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell();


    /* ========= Getter ========= */
    [[nodiscard]] bool getIsUsed() const;
    [[nodiscard]] bool getIsTilesPlayer() const;
    [[nodiscard]] bool getBonusTileExchange() const;
    [[nodiscard]] bool getBonusStone() const;
    [[nodiscard]] bool getBonusRobbery() const;
    [[nodiscard]] int getIDPlayer() const;

    /* ========= Setter ========= */
    void setUsed(bool isUsed);
    void setIdPlayer(int idPlayer);
    void setTilesPlayer(bool isTilesPlayer);
    void setBonusTileExchange(bool bonusTileExchange);
    void setBonusStone(bool bonusStone);
    void setBonusRobbery(bool bonusRobbery);

private:
    bool _isUsed;
    bool _isTilesPlayer;
    int _idPlayer = 10;
    struct Bonus {
        bool tileExchange = false;
        bool stone = false;
        bool robbery = false;
    } _bonus;
};

#endif