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

    static void showSetting(const std::vector<Player> &players);
};



#endif
