#ifndef ART_H
#define ART_H
#include "Player.h"

/**
 * \brief Class for the Art object.
 * \note This class stores the art of the game. All the art is made statically.
 */
class Art {
public:

    /**
     * \brief Displays the loading page.
     */
    static void loadingPage();

    /**
     * \brief Displays the loading bar.
     * \param time Time to display.
     */
    static void loadingBar(int time);

    /**
     * \brief Displays the landing page.
     */
    static void showLandingPage() ;
    /**
     * \brief Displays the instructions.
     */
    static void showInstructions() ;
    /**
     * \brief Displays an invalid option message.
     */
    static void invalidOption();

    /**
     * \brief Displays the players.
     * \param players List of players.
     * \note This function displays the players in a table format, we can this
     * display on the setting section in class `Game`.
     */
    static void showPlayers(const std::vector<Player> &players);

    /**
     * \brief Displays a player.
     * \param player Player to display.
     */
    static void showPlayer(const Player &player);

    /**
     * \brief Displays the color.
     */
    static void ShowColor();

    /**
     * \brief Displays the player on the Game to see which player need to play.
     * \param player Player to display.
     */
    static void showTurnOf(const Player &player);

   private:

    /**
     * \brief Displays a space.
     * \param number Amount of space to display.
     */
    static void space(size_t number);
};



#endif
