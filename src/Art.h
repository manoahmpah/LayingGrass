#ifndef ART_H
#define ART_H
#include "Player.h"


class Art {
public:
    static void loadingPage();

    static void loadingBar(int time);

    static void showLandingPage() ;
    static void showInstructions() ;
    static void invalidOption();

    static void showPlayers(const std::vector<Player> &players);
    static void showPlayer(const Player &player);

private:
    static void space(size_t number);
};



#endif
