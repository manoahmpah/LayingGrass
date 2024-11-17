#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include <vector>
#include "Cell.h"
class Player;

/**
 * \brief Class for the Board object.
 * \note This class stores the game board and the players.
 * We can find an action
 * that a player can do on the board, but it's only the player that plays that can
 * `activate` this option.
 * You'll never see in the code `_board.placeTile()` but
 * `player.placeTile()`.
 */
class Board {
public:
    /**
     * \brief Constructor for the Board class.
     * \param numberPlayerPlaying Number of players currently playing.
     */
    explicit Board(int numberPlayerPlaying);
    /**
     * \brief Copy constructor for the Board class.
     * \param other Board object to copy.
     */
    Board(const Board &other);
    /**
     * \brief Destructor for the Board class.
     */
    ~Board();
    /**
     * \brief Displays the game board.
     */
    void displayBoard() const;
    /**
     * \brief Places a tile on the board.
     * \param x X coordinate of the tile.
     * \param y Y coordinate of the tile.
     * \param idPlayer ID of the player.
     */
    void placeTile(int x, int y, int idPlayer) const;
    /**
     * \brief Adjusts the size of the board based on the number of players.
     * \param numberPlayerPlaying Number of players currently playing.
     */
    void adjustSize(int numberPlayerPlaying);
    /**
     * \brief Places Bonus tiles randomly on the board.
     * \param numberPlayerPlaying Number of players currently playing.
     */
    void placeRandomlyBonus(int numberPlayerPlaying);
    /**
     * \brief Places tiles on the board.
     * \param x X coordinate of the tile.
     * \param y Y coordinate of the tile.
     * \param idPlayer ID of the player.
     * \param tiles Tiles to place.
     */
    void placeTiles(int x, int y, int idPlayer, const std::vector<std::vector<int>> &tiles) const;
    /**
     * \brief Copy assignment operator for the Board class.
     * \param other Board object to copy.
     * \return Copied Board object.
     */
    Board &operator=(const Board &other);

    /* ========= Getter ========= */
    /**
     * \brief Gets the used status of a cell.
     * \param x X coordinate of the cell.
     * \param y Y coordinate of the cell.
     * \return Used status of the cell.
     */
    [[nodiscard]] bool getIsUsed(int x, int y) const;
    /**
     * \brief Gets the used status of a cell.
     * \param x X coordinate of the cell.
     * \param y Y coordinate of the cell.
     * \return Used status of the cell.
     */
    [[nodiscard]] bool getIsTilesPlayer(int x, int y) const;

   /**
    * \brief  Get a list of players.
    * \return List of players.
    */
    [[nodiscard]] std::vector<Player>& getPlayers() const;

    /**
     * \brief Gets the size of the board.
     * \return Size of the board.
     */
    [[nodiscard]] int getSize() const;

    /**
     * \brief Gets the ID of the player in a specific Pos.
     * \param x X coordinate of the cell.
     * \param y Y coordinate of the cell.
     * \return ID of the player.
     */
    [[nodiscard]] int getIDPlayer(int x, int y) const;

    /* ========= Setter ========= */
    /**
     * \brief Sets ID of player.
     * \param x X coordinate of the cell.
     * \param y Y coordinate of the cell.
     * \param idPlayer new ID player.
     */
    void setIdPlayer(int x, int y, int idPlayer) const;

    /**
     * \brief Sets the list of players.
     * \param players List of players.
     */
    void setPlayers (std::vector<Player> *players);

private:
    /**
     * \brief Creates the game board.
     */
    void createBoard();
    /**
     * \brief Places a Bonus Tile Exchange on the board.
     * \param x X coordinate of the tile.
     * \param y Y coordinate of the tile.
     */
    void placeBonusTileExchange(int x, int y) const;
    /**
     * \brief Places a Bonus Stone on the board.
     * \param x X coordinate of the tile.
     * \param y Y coordinate of the tile.
     */
    void placeBonusStone(int x, int y) const;
    /**
     * \brief Places a Bonus Robbery on the board.
     * \param x X coordinate of the tile.
     * \param y Y coordinate of the tile.
     */
    void placeBonusRobbery(int x, int y) const;
    /**
     * \brief Size of the board.
     */
    int _size;
    /**
     * \brief Game board.
     */
    Cell **_board{};
    /**
     * \brief List of bonus positions.
     */
    std::vector<std::pair<int, int>> _positionBonus;

    /**
     * \brief List of players.
     */
    std::vector<Player> *_players;
    /**
     * \brief Overloaded operator to display the board.
     * \param os Output stream.
     * \param board Board object to display.
     * \return Output stream.
     * \sa displayBoard()
     *
     */
    friend std::ostream &operator<<(std::ostream &os, const Board &board);
};

#endif
