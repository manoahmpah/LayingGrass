#ifndef MOLDTILES_H
#define MOLDTILES_H

#include <vector>

#include "Cell.h"
#include "Player.h"

class MoldTiles {
public:

    /* ========= Constructor & Deconstruct ========= */
    explicit MoldTiles(const std::vector <std::vector <int> > &tiles);
    ~MoldTiles();

    /* ========= Method ========= */
    void displayMold() const;

private:

    /* ========= Method ========= */
    void createMold();
    void addTiles(const std::vector <std::vector <int> > &tiles) const;
    void addTile(int x, int y) const;

    Cell **_mold;
    Player _player;
    int _size;

};



#endif