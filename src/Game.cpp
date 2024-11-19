/**
* \file Game.cpp
 * \brief Implementation of the Game class.
 */
#include "Game.h"
#include <unistd.h>
#include <format>
#include "Art.h"
#include <iostream>
#include <random>
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
void Game::displayFiveTile(const int startIndex) const {
    int displayed = 0; // Nombre de tuiles affichées
    constexpr int maxToDisplay = 5;

    for (int i = startIndex; i < _mussels.size() && displayed < maxToDisplay; i++) {
        if (_mussels[i].isUsed()) { // Si la tuile est déjà utilisée, passer à la suivante
            continue;
        }

        std::cout << "Tile " << displayed + 1 << ":\n";

        for (int row = 0; row < _mussels[i].getSize(); row++) {
            for (int col = 0; col < _mussels[i].getSize(); col++) {
                if (_mussels[i].getMold()[row][col].getIsUsed()) {
                    std::cout << "██ ";
                } else {
                    std::cout << "   ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        displayed++;
    }

    if (displayed == 0) {
        std::cout << "No tiles available to display." << std::endl;
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
        case 1: { gameLoop(); break; }
        case 2: { instruction(); break; }
        case 3: { clearScreen(); settingGame(); break; }
        default: { exit(0); }
    }

}
int Game::gameLoop() {

    Board boardVerify(_numberPlayerPlaying);

    clearScreen();
    _board.placeRandomlyBonus(getNumberPlayerPlaying());
    /* Place start tiles on the board */
    for (auto const& player : _players) {
    clearScreen();
    Art::showTurnOf(player);
    int y = -1;
    char letter = ' ';
    int x = 0;
    displayBoard();

    while (y < 1 || y > _board.getSize() || toupper(letter) < 'A' || toupper(letter) > static_cast<char>(_board.getSize() + 'A' - 1)) {
        clearScreen();
        displayBoard();
        std::cout << "\nEnter a column letter (A to " << static_cast<char>(_board.getSize() + 'A' - 1) << "): ";
        std::cin >> letter;
        letter = toupper(letter);

        if (letter >= 'A' && letter <= static_cast<char>(_board.getSize() + 'A' - 1)) {
            x = letter - 'A' + 1;
            std::cout << "\033[F\033[K";
        } else {
            continue;
        }

        std::cout << "Enter the row number (1 to " << _board.getSize() << "): ";
        std::cin >> y;

        if (y < 1 || y > _board.getSize()) {
            std::cout << "Invalid row number. Please try again.\n";
        }
    }

    _startTiles.push_back({x, y});
    player.placeTile(x - 1, y - 1);
    clearScreen();
}

/* Place Mussels */
boardVerify = _board;
for (int i = 0; i < _players.size(); i++) {
    clearScreen();
    displayFiveTile(i);
    displayBoard();
    std::cout << "\nChoose a mold: ";
    int chooseMold;
    std::cin >> chooseMold;

    int x = -1, y = -1;
    while (x < 1 || x > _board.getSize() || y < 1 || y > _board.getSize()) {
        std::cout << "Enter the column letter (A to " << static_cast<char>(_board.getSize() + 'A' - 1) << "): ";
        char letter;
        std::cin >> letter;
        letter = toupper(letter);

        if (letter >= 'A' && letter <= static_cast<char>(_board.getSize() + 'A' - 1)) {
            x = letter - 'A' + 1; // Convertir la lettre en indice numérique
        } else {
            std::cout << "Invalid column letter. Please try again.\n";
            continue;
        }

        std::cout << "Enter the row number (1 to " << _board.getSize() << "): ";
        std::cin >> y;

        if (y < 1 || y > _board.getSize()) {
            std::cout << "Invalid row number. Please try again.\n";
        }
    }
    boardVerify.displayBoard();
    return 0;
    std::vector<std::vector<int>> visitedTiles;
    boardVerify.placeTiles(x - 1, y - 1, _players[i].getIdPlayer(), _shapeTiles[(chooseMold + i) - 1].getTile());
    isPlaceCorrectly(_startTiles[i][0], _startTiles[i][1], _players[i].getIdPlayer(), visitedTiles, boardVerify) ? std::cout << "Correctly placed" : std::cout << "Incorrectly placed";

    return 0;
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
int Game::countAround(const int x, const int y, const int playerID, std::vector<std::vector<int>>& visitedTiles, const Board& board) {
    if (isInVisited(visitedTiles, x, y)) {
        return 0;
    }
    visitedTiles.push_back({x, y});

    int count = 1;

    if ( x-1 >= 0 && board.getIsUsed(x - 1, y) && board.getIDPlayer(x - 1, y) == playerID) {
        count += countAround(x - 1, y, playerID, visitedTiles, board);
    }
    if (x+1 < board.getSize() && board.getIsUsed(x + 1, y) && board.getIDPlayer(x + 1, y) == playerID) {
        count += countAround(x + 1, y, playerID, visitedTiles, board);
    }
    if ( board.getIsUsed(x, y - 1) && board.getIDPlayer(x, y - 1) == playerID) {
        count += countAround(x, y - 1, playerID, visitedTiles, board);
    }
    if (board.getIsUsed(x, y + 1) && board.getIDPlayer(x, y + 1) == playerID) {
        count += countAround(x, y + 1, playerID, visitedTiles, board);
    }

    return count;
}
int Game::countAllTilesOfPlayer(const int playerID, const Board& board) {
    int numberTiles = 0;
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            if (board.getIsUsed(i, j) && board.getIDPlayer(i, j) == playerID) {
                numberTiles++;
            }
        }
    }
    return numberTiles;
}
bool Game::isInVisited(const std::vector<std::vector<int>>& visitedTiles, const int x, const int y) {
    for (const auto& tile : visitedTiles) {
        if (tile[0] == x && tile[1] == y) {
            return true;
        }
    }
    return false;
}
bool Game::isPlaceCorrectly(const int x, const int y, const int playerID, std::vector<std::vector<int>>& visitedTiles, const Board& board) {
    const int aroundCount = countAround(x, y, playerID, visitedTiles, board);
    const int totalTiles = countAllTilesOfPlayer(playerID, board);

    std::cout << "Count around: " << aroundCount << std::endl;
    std::cout << "Count all tiles of player: " << totalTiles << std::endl;

    return aroundCount == totalTiles;
}
/* ========= Getter ========= */
/**
 * \brief Gets the number of players currently playing.
 * \return Number of players.
 */
int Game::getNumberPlayerPlaying() const {
    return _numberPlayerPlaying;
}

void Game::displayTile(const int index) const {
#ifdef _WIN32
    SET_CONSOLE_UTF8
    #endif
    for (int i = 0; i < _mussels[index].getSize(); i++) {
        for (int g = 0; g < 5; g++) {
            for (int j = 0; j < _mussels[index+g].getSize(); j++) {
                if (_mussels[index+g].getMold()[i][j].getIsUsed()) {
                    std::cout << "██ ";
                } else {
                    std::cout << "   ";
                }
            }
        }
        std::cout << std::endl;
    }
}
/**
 * \brief Gets a player by index.
 * \param index Index of the player.
 * \return Player object.
 */
Player Game::getPlayer(const int index) const {
    return _players[index];
}
/**
 * \brief Gets a shape tile by index.
 * \param index Index of the shape tile.
 * \return ShapeTile object.
 */
ShapeTile Game::getShapeTile(const int index) const {
    return _shapeTiles[index];
}


/* ========= Setter ========= */
/**
 * \brief Sets the number of players currently playing.
 * \param numberPlayerPlaying Number of players.
 */

/* ========= Setter ========= */
void Game::setNumberPlayerPlaying(const int numberPlayerPlaying) {
    _players.clear();
    _numberPlayerPlaying = numberPlayerPlaying;
    for (int i = 0; i < numberPlayerPlaying; i++) {
        _players.emplace_back(i+1, _board);
    }
    _board.adjustSize(numberPlayerPlaying);
}

/**
 * \brief Sets the default color for players.
 * \param numberPlayerPlaying Number of players.
 */
void Game::setDefaultColor(const int numberPlayerPlaying) {
    for (int i = 1; i < numberPlayerPlaying; i++) {
        _players[i].setColor(static_cast<Color>(i));
    }

}

/**
 * \brief Sets the default configuration for the game.
 */
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
    void Game::_testCountTileAround() {
        setDefaultConfig();
        const std::vector<std::vector<int>> startTiles = {{9, 9}};
        _players[0].placeTile(startTiles[0][0], startTiles[0][1]);
        _players[0].placeTile(8, 9);
        _players[0].placeTile(8, 8);
        _players[0].placeTile(9, 8);
        _players[0].placeTile(9, 10);
        _players[0].placeTile(10, 9);
        _players[0].placeTile(11, 9);
        _players[1].placeTile(12, 9);

        displayBoard();

        std::cout << std::endl;
        std::vector<std::vector <int>> visitedTiles;
        isPlaceCorrectly(9, 9, 1, visitedTiles, _board) ?
        std::cout << "Respect low" : std::cout << "Do not respect low";

        visitedTiles.clear();

    }

void Game::_testCopyBoard() const {
    _board.placeTile(0, 0, 1);
    const Board board2 = _board;
    board2.displayBoard();
}
