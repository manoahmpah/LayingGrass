#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Board.h"
#include "MoldTiles.h"
#include "Player.h"
#include "ShapeTile.h"

/**
 * \brief Class for the Game object.
 * \note all the game logic is implemented in this class, we can find
 * players & Tiles but also the starting point of what we can see in the
 * command-line tool.
 */
class Game {
public:
    /**
 * \brief Constructor for the Game class.
    */
    Game();
    /**
 * \brief Creates mussels based on the shape tiles.
    */
    void createMussels();
   /**
* \brief Starts the game.
   */
    void startGame();

    /* ========= Display ========= */
    /**
 * \brief Displays the mold at the given index.
 * \param index Index of the mold to display.
      */
    void displayMold(int index) const;
   /**
* \brief Displays the game board.
   */
    void displayBoard() const;
   /**
 * \brief Displays the first five tiles.
 * \param index Index of the first tile to display.
   */
    void displayFiveTile(int index) const;
   /**
 * \brief Main game loop.
 * \return Status code.
   */
    int gameLoop();
   /**
 * \brief Settings menu for the game.
    */
    void settingGame();

    /* ========= Getter ========= */
    /**
* \brief Gets the number of players currently playing.
* \return Number of players.
    */
    [[nodiscard]] int getNumberPlayerPlaying() const;
    /**
     * \brief Gets a player by index.
     * \param index Index of the player.
     * \return Player object.
     */
    [[nodiscard]] Player getPlayer(int index) const;
    /**
 * \brief Gets a shape tile by index.
 * \param index Index of the shape tile.
 * \return ShapeTile object.
    */
    [[nodiscard]] ShapeTile getShapeTile(int index) const;

    /* ========= Setter ========= */
    /**
 * \brief Sets the number of players currently playing.
 * \param numberPlayerPlaying Number of players.
   */
    void setNumberPlayerPlaying(int numberPlayerPlaying);
    /**
 * \brief Sets the default color for players.
 * \param numberPlayerPlaying Number of players.
   */
    void setDefaultColor(int numberPlayerPlaying);

    void _testCountTileAround();

private:
    explicit Game(int initialPlayerCount);
    /**
 * \brief Clears the console screen.
 *
 * \note This method is platform dependent. It uses the `cls` command
 * on Windows and the `clear` command on Unix-based systems.
    */
    static void clearScreen();
    /**
     * \brief Displays the landing page.
     */
    void loader();
    /**
 * \brief Verifies the input on the landing page.
 * \param choose Input to verify.
    */
    void verifyInputLandingPage(const std::string &choose);
    /**
     * \brief Displays the instructions.
     */
    void instruction();

    /* ========= Setter ========= */
    /**
 * \brief Sets the default configuration for the game.
 *
 * \note The default configuration includes setting the color of players
 * and setting the name of players (Player x). The default configuration
 * also includes set a reference in _board of players. In board, we used it
 * to display the color of the player in the Board.
    */
    void setDefaultConfig();
    /**
     * \brief The number of players currently in the game.
     */
    int _numberPlayerPlaying;
    /**
     * \brief Collection of mold tiles (MoldTiles) used in the game.
     * \note The mussels is a list of mussels.
     * mussel is used to set the orientation of tiles.
     */
    std::vector<MoldTiles> _mussels;
    /**
     * \brief Collection of players (Player) in the game.
     */
    std::vector<Player> _players;
    /**
     * \brief Game board (Board) object.
     */
    Board _board;
    /**
     * \brief Collection of shape tiles (ShapeTile) used in the game.
     *
     * \sa `loader()`
     * \note This attribute is used for the begging of the game.
     * The Game will starting with the loader in `startGame()`
     * and if in the game we need to refer to `startGame()` we no
     * longer need to call the loader.
     */
    bool _isGameRunning = false;
    /**
 * \brief Collection of shape tiles available in the game.
 * \note This vector contains the positions of the tiles.
 * These tiles are arranged starting from the top left.
 * This class not only stores these positions but also allows
 * checking if a tile is available or already placed.
     */
    std::vector<ShapeTile> _shapeTiles = {
        ShapeTile({{0, 0},{1, 0},{1, 1},{1, 2}}),
        ShapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {2, 2}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{1, 2}, {2, 1}}),
        ShapeTile({{0, 2},{1, 0},{1, 1},{1, 2}, {2, 0}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{1, 2}}),
        ShapeTile({{0, 0},{0, 1},{1, 0},{1, 1}}),
        ShapeTile({{0, 0},{0, 2},{1, 0}, {1, 1},{1, 2}}),
        ShapeTile({{0, 0},{0, 1},{0, 2}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{2, 0}}),
        ShapeTile({{0, 0},{1, 0},{1, 1}}),
        ShapeTile({{0, 2},{1, 1},{1, 2}, {2, 0}, {2, 1}}),
        ShapeTile({{0, 0},{0, 1}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{2, 0}, {3, 0}, {4, 0}, {4, 1}}),
        ShapeTile({{0, 0},{0, 1},{0, 2},{1, 0}, {2, 0}, {3, 0}, {4, 0}}),
        ShapeTile({{0, 3},{1, 3},{2, 3},{2, 4}, {3, 1}, {3, 2}, {3, 3}, {4, 0}, {4, 1}}),
        ShapeTile({{0, 2},{1, 1},{1, 2},{2, 0}, {2, 1}, {3, 0}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{1, 2}, {2, 0}, {2, 1}}),
        ShapeTile({{0, 0},{0, 1},{0, 2}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{2, 0}, {3, 0}}), //23
        ShapeTile({{0, 1},{0, 2},{1, 0},{1, 1}, {2, 0}, {2, 1}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{2, 0}, {2, 1}, {2, 2}}),
        ShapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {2, 2}, {3, 0}}),
        ShapeTile({{0, 0},{1, 0},{1, 1}}),
        ShapeTile({{0, 0},{0, 1},{1, 0},{1, 1}, {2, 0}, {2, 1}}),
        ShapeTile({{0, 0},{0, 1},{0, 2},{1, 1}, {2, 1}, {3, 1}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{2, 1}, {2, 2}, {3, 2},{3, 3}}),
        ShapeTile({{0, 0},{0, 1},{0, 2},{0, 3}, {0, 4}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{1, 2}, {2, 2}, {3, 2}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{2, 0}, {3, 0}, {3, 1},{4, 0}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{2, 0}, {2, 1}, {3, 0}}),
        ShapeTile({{0, 1},{1, 1},{2, 1},{3, 0}, {3, 1}, {3, 2},{4, 0},{4, 2}}),
        ShapeTile({{0, 0},{0, 1}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{1, 2}, {2, 0}, {2, 2},{2, 3}}),
        ShapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {3, 0}, {4, 0}}),
        ShapeTile({{0, 0},{0, 1},{1, 1},{2, 1}, {2, 2}, {2, 3},{3, 0},{3, 1},{4, 0}}),
        ShapeTile({{0, 0},{1, 0},{2, 0},{2, 1}, {3, 0}}),//35
        ShapeTile({{0, 1},{1, 0},{1, 1},{2, 0}}),
        ShapeTile({{0, 0},{0, 3},{1, 0},{1, 1}, {1, 2}, {1, 3}}),
        ShapeTile({{0, 4},{0, 5},{1, 0},{1, 5}, {2, 0}, {2, 1},{2, 2},{2, 3},{2, 4},{2, 5}}),
        ShapeTile({{0, 0},{1, 0},{2, 0},{2, 1}, {3, 1}, {3, 2},{3, 3}}),
        ShapeTile({{0, 0},{0, 1},{1, 1},{1, 2}, {2, 0}, {2, 1},{3, 1},{3, 2},{4, 1}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{2, 0}, {2, 1}}),
        ShapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {2, 2}, {2, 3}}),
        ShapeTile({{0, 0},{0, 1},{1, 0},{1, 1}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{2, 0}, {2, 1}, {3, 0}}),
        ShapeTile({{0, 0},{0, 1},{0, 2},{1, 1}, {2, 0}, {2, 1}}),
        ShapeTile({{0, 0},{0, 1},{0, 2},{0, 3}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{1, 2}}),
        ShapeTile({{0, 0},{1, 0},{2, 0},{2, 1}, {2, 2}, {2, 3}}),
        ShapeTile({{0, 1},{0, 2},{1, 0},{1, 1}, {2, 1}, {2, 2},{2, 3}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{2, 0}, {3, 0}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{1, 2}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{2, 0}, {3, 0}, {4, 0}}),
        ShapeTile({{0, 2},{0, 3},{0, 4},{1, 2}, {2, 2}, {3, 2},{4, 0},{4, 1},{4, 2}}),
        ShapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {3, 0}, {4, 0},{4, 1},{5, 0}}),
        ShapeTile({{0, 0},{0, 1},{0, 2},{0, 3}}),
        ShapeTile({{0, 0},{0, 1},{1, 1},{2, 1}, {2, 2}, {2, 3},{3, 3}}),
        ShapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {2, 2}, {3, 1},{4, 1}}),
        ShapeTile({{0, 2},{1, 2},{2, 0},{2, 1}, {2, 2}}),
        ShapeTile({{0, 0},{1, 0},{2, 0},{3, 0}, {4, 0}, {5, 0}}),
        ShapeTile({{0, 0},{0, 2},{1, 0},{1, 1}, {1, 2}, {2, 1},{3, 0},{3, 1}}),//60
        ShapeTile({{0, 2},{1, 0},{1, 1},{1, 2}, {2, 1}, {2, 2},{2, 3},{3, 1}}),//61
        ShapeTile({{0, 1},{0, 2},{1, 1},{2, 1}, {3, 0}, {3, 1},{3, 2}}),
        ShapeTile({{0, 0},{1, 0},{2, 0},{2, 1}, {3, 0}, {4, 0}}),
        ShapeTile({{0, 0},{0, 1},{1, 1},{2, 1},{2, 3}, {3, 0}, {3, 1},{3, 2},{3, 3}}), //64
        ShapeTile({{0, 2},{1, 1},{1, 2},{2, 0}, {2, 1}, {3, 0},{4, 0},{4, 1}}),
        ShapeTile({{0, 1},{0, 2},{1, 1},{2, 1}, {3, 1}, {4, 0},{4, 1},{5, 0}}),
        ShapeTile({{0, 0},{0, 2},{1, 0},{1, 1}, {1, 2}, {1, 3}}),
        ShapeTile({{0, 0},{0, 1},{1, 1},{1, 3}, {2, 1}, {2, 3},{3, 1},{3, 2},{3, 3}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{2, 0}, {3, 0}, {4, 0}}),
        ShapeTile({{0, 0},{1, 0},{1, 2},{2, 0}, {2, 1}, {2, 2},{2, 3},{3, 1},{4, 1}}),
        ShapeTile({{0, 0}, {0,1},{1, 0},{2, 0},{3, 0},{4, 0},{5, 0},{6, 0}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{1, 2}, {2, 0}, {3, 0}}),
        ShapeTile({{0, 0},{0, 1}}),
        ShapeTile({{0, 2},{1, 0},{1, 2},{2, 0}, {2, 1}, {2, 2}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{1, 2}, {2, 0}, {2, 2}}),
        ShapeTile({{0, 2},{1, 2},{2, 0},{2, 1}, {2, 2}, {2, 3},{2, 4},{3, 2},{4, 2}}),
        ShapeTile({{0, 3},{1, 2},{1, 3},{2, 2}, {3, 2}, {4, 1},{4, 2},{5, 0},{5, 1}}),
        ShapeTile({{0, 0},{0, 1},{1, 0},{2, 0}, {2, 1}, {3, 0},{4, 0},{4, 1}}),
        ShapeTile({{0, 1},{1, 1},{2, 1},{3, 0}, {3, 1}, {3, 2},{3, 3},{4, 1}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{2, 0}, {3, 0}, {4, 0}}),
        ShapeTile({{0, 1},{0, 2},{1, 1},{2, 0}, {2, 1}, {3, 0}}),
        ShapeTile({{0, 1},{0, 2},{1, 1},{2, 0}, {2, 1}, {3, 1},{3, 2},{4, 1},{5, 1}}),//82
        ShapeTile({{0, 0},{0, 1},{1, 0},{1, 1}, {2, 1}, {2, 2},{3, 1},{4, 1},{5, 1}}),
        ShapeTile({{0, 1},{1, 1},{1, 2},{2, 0}, {2, 1}, {3, 1}}),
        ShapeTile({{0, 0},{0, 1},{1, 0},{1, 1}, {1, 2}, {1, 3}}),
        ShapeTile({{0, 2},{0, 3},{1, 0},{1, 1}, {1, 2}, {2, 0},{3, 0},{3, 1}}),
        ShapeTile({{0, 1},{0, 2},{1, 1},{2, 1}, {3, 0}, {3, 1}}),
        ShapeTile({{0, 1},{1, 1},{2, 0},{2, 1}, {2, 2}, {3, 1}}),
        ShapeTile({{0, 0},{0, 1},{0, 2},{1, 0}, {1, 2}, {2, 0},{3, 0},{3, 1}}),
        ShapeTile({{0, 1},{1, 1},{1, 2},{2, 0}, {2, 1}, {3, 0}}),
        ShapeTile({{0, 0},{1, 0},{1, 1},{2, 0}, {2, 1}, {2, 2}}),
        ShapeTile({{0, 0},{1, 0},{2, 0},{3, 0}, {3, 1}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{1, 2}, {1, 3}, {2, 0}}),
        ShapeTile({{0, 1},{0, 2},{1, 0},{1, 1}, {2, 0}, {3, 0}}),
        ShapeTile({{0, 1},{1, 0},{1, 1},{2, 0}, {3, 0}, {3, 1}}),
    };

    [[nodiscard]] int countAround(int x, int y, int playerID, std::vector<std::vector<int>>& visitedTiles) const;
    static bool isInVisited(const std::vector<std::vector<int>>& visitedTiles, int x, int y);
};


#endif
