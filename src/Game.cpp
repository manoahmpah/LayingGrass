/**
* \file Game.cpp
 * \brief Implementation of the Game class.
 */
#include "Game.h"
#include <unistd.h>
#include <format>
#include "Art.h"
#include <iostream>
#include <regex>
#include <thread>

#ifdef _WIN32
    #include <windows.h>
    #define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
#else
    #define SET_CONSOLE_UTF8
#endif

Game::Game() : _numberPlayerPlaying(3), _board(_numberPlayerPlaying) {
    setNumberPlayerPlaying(_numberPlayerPlaying);
    createMussels();
}
void Game::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void Game::createMussels() {
    for (const auto& PositionTile : _shapeTiles) {
        MoldTiles moldTile1(PositionTile.getTile());
        _mussels.push_back(moldTile1);
    }
}
void Game::displayMold(const int index) const {
    _mussels[index].displayMold();
}
void Game::displayFiveTile(const int index) const {
#ifdef _WIN32
    SET_CONSOLE_UTF8
    #endif
    for (int i = 0; i < _mussels[index].getSize(); i++) {
        for (int g = 0; g < 5; g++) {
            for (int j = 0; j < _mussels[index+g].getSize(); j++) {
                if (_mussels[index+g].getMold()[i][j].getIsUsed()) {
                    std::cout << "▄▄ ";
                } else {
                    std::cout << "   ";
                }
            }
        }
        std::cout << std::endl;
    }
}
void Game::displayBoard() const {
    _board.displayBoard();
}
void Game::startGame() {

    loader();

    std::string choose;
    Art::showLandingPage();
    std::cin >> choose;

    verifyInputLandingPage(choose);

    switch (std::stoi(choose)) {
        case 1: { gameLoop(); break; };
        case 2: { instruction(); break; }
        case 3: { clearScreen(); settingGame(); break; }
        default: { exit(0); }
    }

}
int Game::gameLoop() {
    clearScreen();
    _board.placeRandomlyBonus(getNumberPlayerPlaying());
    for (auto const& player : _players) {
        clearScreen();
        Art::showTurnOf(player);
        displayBoard();
        int y; char letter;
        std::cout << std::endl << "Enter a letter or character between A to " << static_cast<char>(_board.getSize() + 64) <<" : ";
        std::cin >> letter;
        const int x = toupper(letter) - 64;
        std::cout << "\033[F\033[K";
        std::cout << "Enter the y position: ";
        std::cin >> y;
        player.placeTile(x-1, y-1);
        std::cout << "\033[F\033[K";
    }

    for (int i = 0; i < 3; i++) {
        clearScreen();
        displayFiveTile(i);
        std::cout << "\033[F\033[K";
        std::cout << "\033[F\033[K";
        displayBoard();
        std::cout << std::endl;
        std::cout << "choisir un moule >";
        int chooseMold; int x; int y;
        std::cin >> chooseMold;
        std::cout << "\033[F\033[K";
        std::cout << "Enter the x position: ";
        std::cin >> x;
        std::cout << "\033[F\033[K";
        std::cout << "Enter the y position: ";
        std::cin >> y;
        _board.placeTiles(x, y, _players[i].getIdPlayer(), _shapeTiles[(chooseMold + i)-1].getTile());

        sleep(1);
    }
    std::cout << std::endl;
    displayBoard();

    return 0;
}
void Game::settingGame() {
    Art::showPlayers(_players);
    std::string choose;
    std::cout << "[A] Rename players      [B] Change color      [C] Update number players      [D] Restore        [E] Menu" << std::endl;
    std::cout << "> ";
    std::cin >> choose;
    if (const std::regex number_regex("^[A-Ea-e]$"); !std::regex_match(choose, number_regex)) {
        clearScreen();
        Art::invalidOption();
        settingGame();
    }

    if (choose == "A" || choose == "a") {
        int numPlayer;
        std::string name;

        std::cout << "\033[F\033[K";
        std::cout << "\033[F\033[K";
        std::cout << "Enter the player number you want to rename: ";
        std::cin >> numPlayer;
        if (numPlayer > _numberPlayerPlaying) {
            clearScreen();
            Art::invalidOption();
            settingGame();
        }
        std::cout << "\033[F\033[K";
        std::cout << "Enter the new name: ";
        std::cin >> name;
        _players[numPlayer - 1].setName(name);
        clearScreen();
        settingGame();

    } else if (choose == "B" || choose == "b") {
        clearScreen();
        for (auto& player : _players) {
            player.setColor(Color::WHITE);
            Art::showPlayer(player);
            Art::ShowColor();
            std::string chooseColor;
            std::cout << "Enter the color you want to change: ";
            std::cin >> chooseColor;
        }
    } else if (choose == "C" || choose == "c") {
        std::cout << "\033[F\033[K";
        std::cout << "\033[F\033[K";
        std::cout << "Enter the number of players: ";
        int numberPlayerPlaying;
        std::cin >> numberPlayerPlaying;
        if (numberPlayerPlaying < 2 || numberPlayerPlaying > 9) {
            clearScreen();
            Art::invalidOption();
            settingGame();
        }
        setNumberPlayerPlaying(numberPlayerPlaying);
        setDefaultConfig();

        clearScreen();
        settingGame();
    } else if (choose == "D" || choose == "d") {
        std::cout << "Restore the default configuration" << std::endl;
    } else if (choose == "E" || choose == "e") {
        clearScreen();
        startGame();
    }
}


/* ========= Getter ========= */
int Game::getNumberPlayerPlaying() const {
    return _numberPlayerPlaying;
}
Player Game::getPlayer(const int index) const {
    return _players[index];
}
ShapeTile Game::getShapeTile(const int index) const {
    return _shapeTiles[index];
}


/* ========= Setter ========= */
void Game::setNumberPlayerPlaying(const int numberPlayerPlaying) {
    _players.clear();
    _numberPlayerPlaying = numberPlayerPlaying;
    for (int i = 0; i < numberPlayerPlaying; i++) {
        _players.emplace_back(i+1, _board);
    }
    _board.adjustSize(numberPlayerPlaying);
}
void Game::setDefaultColor(const int numberPlayerPlaying) {
    for (int i = 1; i < numberPlayerPlaying; i++) {
        _players[i].setColor(static_cast<Color>(i));
    }

}
void Game::setDefaultConfig() {
    /* ========= default configuration ========= */
    setDefaultColor(_numberPlayerPlaying);
    for (auto& player : _players) {
        player.setName(std::format("Player {} ", player.getIdPlayer()));
    }
    _board.setPlayers(&_players);
}
void Game::loader() {
    if (!_isGameRunning) {
        _isGameRunning = true;
        for (int time = 0; time <= 100; time += 7) {
            Art::loadingPage();
            Art::loadingBar(time);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "\r";
            if (time == 98) {
                sleep(3);
            }
            clearScreen();
            setDefaultConfig();
        }
        sleep(2);
    }
}
void Game::verifyInputLandingPage(const std::string& choose) {
    if (const std::regex number_regex("^[1-4]$"); !std::regex_match(choose, number_regex)) {
        clearScreen();
        Art::invalidOption();
        startGame();
    }
}
void Game::instruction() {
    clearScreen();
    Art::showInstructions();
    std::string chooseInstruction;
    std::getline(std::cin, chooseInstruction);
    clearScreen();
    startGame();
}


/* ========= Test =========  */