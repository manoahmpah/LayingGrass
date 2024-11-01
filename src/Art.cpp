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
    cout << "║                                WELCOME TO THE LAYING GRASS STRATEGY GAME                             ║\n";
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
    cout << "║                                   Invalid option. Please try again.                                  ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << "" << endl;
}

void Art::showSetting(const vector<Player> &players) {
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
    for (size_t i = 0; i < players.size(); i += 2) { // Pas de 2

        cout << "║                                     " << players[i].getIdPlayer() << ". " << players[i].getName();
        i+1 < players.size() ? cout << " " << players[i+1].getName() : cout << "";
        for (int j = 0; j < 65 - players[i].getName().length() - 4 - players[i+1].getName().length(); j++) {
            cout << " ";
        }
        cout << "║\n";
        cout << "║                                        " << getColorString(players[i].getColor());
        i+1 < players.size() ? cout << "       " << getColorString(players[i+1].getColor()) : cout << "";
        for (int j = 0; j < 62 - getColorString(players[i].getColor()).length() - getColorString(players[i+1].getColor()).length() -1; j++) {
            cout << " ";
        }
        cout << "║\n";
        cout << "║                                                                                                      ║\n";
    }

       cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << "> ";
}