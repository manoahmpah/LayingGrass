#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "ShapeTile.h"
#include "Color.h"
#include "Board.h"


/**
 * \brief Class for the Player object.
 * \note This class stores the player's name, ID, color, and the game board.
 * We can find also the action that a player can do on the board.
 */
class Player {
public:
    /**
     * \brief Constructor for the Player class.
     * \param idPlayer ID of the player.
     * \param board Game board object.
     */
    Player(int idPlayer, Board& board);

    /**
     * \brief Copy constructor for the Player class.
     * \param other Player object to copy.
     */
    Player(const Player& other);
    /**
     * \brief Places a tile on the board.
     * \param x X coordinate of the tile.
     * \param y Y coordinate of the tile.
     */
    void placeTile(int x, int y) const;
    /**
     * \brief Places a tile on the board.
     * \param x X coordinate of the tile.
     * \param y Y coordinate of the tile.
     * \param shapeTile ShapeTile object to place.
     */
    void placeTiles(int x, int y, ShapeTile &shapeTile) const;

    /* ========= Getter ========= */
    /**
     * \brief Gets the name of the player.
     * \return Name of the player.
     */
    [[nodiscard]] std::string getName() const;
    /**
     * \brief Gets the ID of the player.
     * \return ID of the player.
     */
    [[nodiscard]] int getIdPlayer() const;
    /**
     * \brief Gets the game board.
     */
    void getBoard() const;
    /**
     * \brief Gets the color of the player.
     * \return Color of the player.
     */
    [[nodiscard]] std::string getColor() const;

    /* ========= Setter ========= */
    /**
     * \brief Sets the name of the player.
     * \param name Name of the player.
     */
    void setName(const std::string_view &name);
    /**
     * \brief Sets the color of the player.
     * \param color Color of the player.
     */
    void setColor(Color color);

private:
    /**
     * \brief ID of the player.
     */
    int _idPlayer;
    /**
     * \brief Name of the player.
     */
    std::string _name;
    /**
     * \brief Game board attribute.
     * \note This attribute is used to place tiles on the board.
     * Player can do action on the board.
     * As we can see this a reference of the board this means that
     * if a player do action he impacts the board that all players got.
     */
    Board& _board;
    /**
     * \brief Color of the player.
     */
    Color _color;
};

#endif
