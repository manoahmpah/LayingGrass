#include "MoldTiles.h"

int main() {
    const std::vector<std::vector<int>> tiles1 = {{0, 0},{1, 0},{1, 1},{1, 2}};
    const std::vector<std::vector<int>> tiles2 = {{0, 0}, {0,1},{1, 0},{2, 0},{3, 0},{4, 0},{5, 0},{6, 0}};
    const MoldTiles moldTile1(tiles2);
    moldTile1.displayMold();
    return 0;
}
