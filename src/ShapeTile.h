#ifndef SHAPETILE_H
#define SHAPETILE_H
#include <vector>

/**
 * \brief Class for the ShapeTile object.
 * \note This class stores the shape of the tiles and the state like if
 * a tile is posed or not.
 */
class ShapeTile {
public:

    /**
     * \brief Constructor for the ShapeTile class.
     * \param tile Of vector of int. It's the coordinate of the tile.
     */
    explicit ShapeTile(const std::vector<std::vector<int>>& tile);

    /* ========= Getter ========= */
    /**
     * \brief Gets the state of the tile.
     * \return True if the tile is posed, false otherwise.
     */
    [[nodiscard]] bool getIsPosed() const;
    /**
     * \brief Gets the tile.
     * \return Tile.
     */
    [[nodiscard]] std::vector<std::vector<int>> getTile() const;

    /* ========= Setter ========= */
    /**
     * \brief Sets the state of the tile.
     * \param isPosed True if the tile is posed, false otherwise.
     */
    void setPosed(bool isPosed);

private:
    std::vector<std::vector<int>> _tile;
    bool _isPosed;
};



#endif
