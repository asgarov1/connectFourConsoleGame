#include <iostream>
#include "Board.h"
#include "Game.h"

/**
 * Prompts whether user would like 1. random strategy opponent or 2. starting from left one
 * @return boolean, true for random, false for starting from left
 */
bool promptForRandomStrategy();

/**
 * Promps for color, 'Y' for yellow or 'R' for Red
 * @return chosen CHAR
 */
char promptForColor();

using namespace std;

int main() {
    Game game(promptForRandomStrategy(), promptForColor());

    game.displayBoard();
    while (!game.isWon() && game.getBoard().hasSpace()) {
        int columnNumber = -1;
        while (!game.getBoard().isColumnAvailable(columnNumber)) {
            cout << "please choose where to drop from 0 to " << game.getBoard().getNumberOfColumns() << ": ";
            cin >> columnNumber;
        }
        cout << endl;

        game.makePlayerMove(columnNumber);
        if (!game.isWon()) {
            game.makeComputerMove(game.computerPlay());
        }
        game.displayBoard();
    }
    if (game.getBoard().hasSpace()) {
        cout << "\n=== Game over, " << game.getColorThatWon() << " has won ===\n";
    } else {
        cout << "\n=== Game ended with draw ===\n";
    }

    return 0;
}

char promptForColor() {
    char playerColor{' '};
    while (playerColor != 'Y' && playerColor != 'R') {
        cout << "Please choose your color: Y for yellow or R for red: ";
        cin >> playerColor;
    }
    return playerColor;
}

bool promptForRandomStrategy() {
    int i = 0;
    bool randomStrategy = false;
    while (i != 1 && i != 2) {
        cout << "Please choose your opponent: 1 for RANDOM BOT or 2 for STARTING FROM LEFT BOT: ";
        cin >> i;

        if (i == 1) {
            randomStrategy = true;
        }
    }
    return randomStrategy;
}
