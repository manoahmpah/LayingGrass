#include "Art.h"
#include "Color.h"
#include <iostream>

#include "Player.h"
#ifdef _WIN32
    #include <windows.h>
    #define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
#else
    #define SET_CONSOLE_UTF8
#endif

using namespace std;

void Art::loadingPage() {
    #ifdef _WIN32
    SET_CONSOLE_UTF8
    #endif
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "     ██╗      █████╗ ██╗   ██╗██╗███╗   ██╗ ██████╗      ██████╗ ██████╗  █████╗ ███████╗███████╗\n";
    cout << "     ██║     ██╔══██╗╚██╗ ██╔╝██║████╗  ██║██╔════╝     ██╔════╝ ██╔══██╗██╔══██╗██╔════╝██╔════╝\n";
    cout << "     ██║     ███████║ ╚████╔╝ ██║██╔██╗ ██║██║  ███╗    ██║  ███╗██████╔╝███████║███████╗███████╗\n";
    cout << "     ██║     ██╔══██║  ╚██╔╝  ██║██║╚██╗██║██║   ██║    ██║   ██║██╔══██╗██╔══██║╚════██║╚════██║\n";
    cout << "     ███████╗██║  ██║   ██║   ██║██║ ╚████║╚██████╔╝    ╚██████╔╝██║  ██║██║  ██║███████║███████║\n";
    cout << "     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝\n";


}

void Art::loadingBar(const int time) {
    if (time < 10) {
        cout << "     █████████ \n";

    } else if (time >= 10 && time < 20) {
        cout << "     █████████████████\n";

    } else if (time >= 20 && time < 30) {
        cout << "     █████████████████████████\n";

    } else if (time >= 30 && time < 40) {
        cout << "     █████████████████████████████████\n";

    } else if (time >= 40 && time < 50) {
        cout << "     █████████████████████████████████████████\n";

    } else if (time >= 50 && time < 60) {
        cout << "     █████████████████████████████████████████████████\n";

    } else if (time >= 60 && time < 70) {
        cout << "     █████████████████████████████████████████████████████████\n";

    } else if (time >= 70 && time < 80) {
        cout << "     █████████████████████████████████████████████████████████████████\n";

    } else if (time >= 80 && time < 90) {
        cout << "     █████████████████████████████████████████████████████████████████████████\n";

    } else if (time >= 90 && time < 100) {
        cout << "     ████████████████████████████████████████████████████████████████████████████████████████████\n";
        cout << "       •  ••   ••    • ••••  • •• •  • •• •••  ••  ••• •   ••• •••  •  ••    • •••  •• •••  ••";


    }
    cout << "\n";
    cout << "     © 2024 Manoah & David" << " [" << time << "%]" << "\n";
}


void Art::showLandingPage() {
    #ifdef _WIN32
    SET_CONSOLE_UTF8
    #endif
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                                                                      ║\n";
    cout << "║     ██╗      █████╗ ██╗   ██╗██╗███╗   ██╗ ██████╗      ██████╗ ██████╗  █████╗ ███████╗███████╗     ║\n";
    cout << "║     ██║     ██╔══██╗╚██╗ ██╔╝██║████╗  ██║██╔════╝     ██╔════╝ ██╔══██╗██╔══██╗██╔════╝██╔════╝     ║\n";
    cout << "║     ██║     ███████║ ╚████╔╝ ██║██╔██╗ ██║██║  ███╗    ██║  ███╗██████╔╝███████║███████╗███████╗     ║\n";
    cout << "║     ██║     ██╔══██║  ╚██╔╝  ██║██║╚██╗██║██║   ██║    ██║   ██║██╔══██╗██╔══██║╚════██║╚════██║     ║\n";
    cout << "║     ███████╗██║  ██║   ██║   ██║██║ ╚████║╚██████╔╝    ╚██████╔╝██║  ██║██║  ██║███████║███████║     ║\n";
    cout << "║     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝     ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║                               WELCOME TO THE LAYING GRASS STRATEGY GAME                              ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║                                 \"Expand your territory and dominate!\"                                ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║                                    ╔═══════════════════════════╗                                     ║\n";
    cout << "║                                    ║   [1] Start Game          ║                                     ║\n";
    cout << "║                                    ║   [2] Instructions        ║                                     ║\n";
    cout << "║                                    ║   [3] Setting             ║                                     ║\n";
    cout << "║                                    ║   [4] Exit                ║                                     ║\n";
    cout << "║                                    ╚═══════════════════════════╝                                     ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║                                  Select an option and press Enter...                                 ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << "> ";
}


void Art::showInstructions() {
#ifdef _WIN32
    SET_CONSOLE_UTF8
#endif
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                         LAYING GRASS INSTRUCTIONS                                    ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "╠══════════════════════════════════════════════════════════════════════════════════════════════════════╣\n";
    cout << "║  1. OBJECTIVE                                                                                        ║\n";
    cout << "║     Place grass tiles to create the largest square territory possible.                               ║\n";
    cout << "║     The player with the largest square wins.                                                         ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║  2. START                                                                                            ║\n";
    cout << "║     Players will enter their name, choose a color, and place a 1x1 starting tile.                    ║\n";
    cout << "║     Each player starts with one tile exchange coupon.                                                ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║  3. TILES                                                                                            ║\n";
    cout << "║     Each turn, players place a tile to expand their territory.                                       ║\n";
    cout << "║     Tiles must touch at least one side of their current territory.                                   ║\n";
    cout << "║     Players can use a tile exchange coupon to select from the next five tiles.                       ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║  4. BONUSES                                                                                          ║\n";
    cout << "║     Bonus squares provide special abilities:                                                         ║\n";
    cout << "║       - Tile Exchange: Gain one tile exchange coupon.                                                ║\n";
    cout << "║       - Stone: Place a stone tile to block opponents.                                                ║\n";
    cout << "║       - Robbery: Steal a tile from another player.                                                   ║\n";
    cout << "║     Bonus squares must be used immediately upon acquisition.                                         ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║  5. END OF GAME                                                                                      ║\n";
    cout << "║     After nine rounds, players can use any remaining coupons for a final 1x1 tile.                   ║\n";
    cout << "║     The player with the largest square territory wins!                                               ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "╠══════════════════════════════════════════════════════════════════════════════════════════════════════╣\n";
    cout << "║                                      Press Enter to return...                                        ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << "> ";
    cin.get();
}

void Art::invalidOption() {
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                 "<< "\033[31m" << "Invalid option. Please try again.  " <<"\033[0m" << "                                  ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << "" << endl;
}

void Art::showPlayers(const vector<Player> &players) {
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                                                                      ║\n";
    cout << "║                     ██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗ ███████╗                        ║\n";
    cout << "║                     ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗██╔════╝                        ║\n";
    cout << "║                     ██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝███████╗                        ║\n";
    cout << "║                     ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗╚════██║                        ║\n";
    cout << "║                     ██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║███████║                        ║\n";
    cout << "║                     ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝╚══════╝                        ║\n";
    cout << "║                                                                                                      ║\n";
    cout << "║                                                                                                      ║\n";
    for (size_t i = 0; i < players.size(); i += 2) {

        /* ========= About Name ========= */

        cout << "║                                    " << players[i].getIdPlayer() << ". " << players[i].getName();
        space(9 - players[i].getName().length());
        i+1 < players.size() ? cout << "    " << players[i+1].getIdPlayer() << ". " << players[i+1].getName() : cout << "       ";
        i+1 < players.size() ? space(47 - players[i+1].getName().length()) : space(56 - players[i].getName().length());

        cout << "║\n";

        /* ========= About Color ========= */

        cout << "║                                       " << players[i].getColor() << getColorString(players[i].getColor()) << "\033[0m";
        space(16 - getColorString(players[i].getColor()).length());
        i+1 < players.size() ? cout << players[i+1].getColor() << getColorString(players[i+1].getColor()) << "\033[0m" : cout << "     ";
        i+1 < players.size() ? space(47 - getColorString(players[i+1].getColor()).length()) : space(46 - getColorString(players[i].getColor()).length());

        cout << "║\n";
        cout << "║                                                                                                      ║\n";

    }
    cout << "║                                                                                                      ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
}
void Art::space(const size_t number) {
    for (int i = 0; i < number; i++) {
        cout << " ";
    }
}

void Art::showPlayer(const Player &player) {
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                        " << player.getName() << player.getColor() << "                                             █████" << "\033[0m" << "                   ║  "<< endl;
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";

}

void Art::ShowColor() {
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    for (int i = 0; i < 9; i++) {
        std::string colorCode = getColorCode(static_cast<Color>(i));
        cout << "║   " << i+1 << ". " << colorCode  << "█████" << "\033[0m";
        space(91);
        cout << "║" << "\033[0m\n";
    }
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";

}