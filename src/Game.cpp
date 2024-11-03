#include "Game.h"
#include <unistd.h>
#include <format>

#include "Art.h"

#include <iostream>
#include <regex>
#include <thread>


Game::Game() : _numberPlayerPlaying(2), _board(_numberPlayerPlaying) {
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
void Game::displayBoard() const {
    _board.displayBoard();
}

void Game::startGame() {

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
        }
        sleep(2);
    }

    std::string choose;
    Art::showLandingPage();

    /* ========= default configuration ========= */
    _players.clear();
    setNumberPlayerPlaying(9);
    setDefaultColor(_numberPlayerPlaying);
    for (auto& player : _players) {
        player.setName(std::format("Player {} ", player.getIdPlayer()));
    }
    _board.setPlayers(&_players);


    std::cin >> choose;
    if (const std::regex number_regex("^[1-4]$"); !std::regex_match(choose, number_regex)) {
        clearScreen();
        Art::invalidOption();
        startGame();
    }

    switch (std::stoi(choose)) {
        case 1:
            gameLoop();
            break;
        case 2:
            {
            clearScreen();
            Art::showInstructions();
            std::string chooseInstruction;
            std::getline(std::cin, chooseInstruction);
            clearScreen();
            startGame();
            break;
            }
        case 3:
            clearScreen();
            settingGame();
            break;
        case 4:
            exit(0);
        default:
            break;
    }
}

int Game::gameLoop() {
    _board.placeRandomlyBonus(getNumberPlayerPlaying());
    _players[1].placeTiles(5, 5, _shapeTiles[0]);
    // _players[0].placeTiles(9, 9, _shapeTiles[1]);

    displayBoard();
    return 0;
}

void Game::settingGame() {
    Art::showPlayers(_players);
    std::string choose;
    std::cout << "[A] Rename players      [B] Change color      [C] Reset number players      [D] Restore       [E] Cancel" << std::endl;
    std::cout << "> ";
    std::cin >> choose;
    if (const std::regex number_regex("^[A-Ea-e]$"); !std::regex_match(choose, number_regex)) {
        clearScreen();
        Art::invalidOption();
        settingGame();
    }

    if (choose == "A" || choose == "a") {
        std::cout << "Enter the player number you want to rename: ";
    } else if (choose == "B" || choose == "b") {
        std::cout << "Enter the player number you want to change the color: ";
    } else if (choose == "C" || choose == "c") {
        std::cout << "Enter the number of players: ";
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
