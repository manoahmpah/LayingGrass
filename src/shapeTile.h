#ifndef SHAPETILE_H
#define SHAPETILE_H
#include <vector>


class shapeTile {
public:
    explicit shapeTile(const std::vector <std::vector <int> > &tile);

    /* ========= Getter ========= */
    [[nodiscard]] bool getIsPosed() const;
    [[nodiscard]] std::vector<std::vector<int>> getTile() const;

    /* ========= Getter ========= */
    void setPosed(bool isPosed);

private:
    std::vector<std::vector <int> > _tile;
    bool _isPosed;
};



#endif
