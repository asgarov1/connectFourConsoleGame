#include <iostream>
#include "Board.h"
#include "Computer.h"

using namespace std;

int main() {
    Board board;
    Computer computer;

//    string playerColor{"Y"};

    while (board.getPlayerColor() != 'Y' && board.getPlayerColor() != 'R') {
        cout << "Please choose your color: Y for yellow or R for red" << endl;
        char color;
        cin >> color;
        board.setColors(color);
    }


    while (!board.isWon() && board.hasSpace()) {
        int columnNumber = -1;
        while (!board.isColumnAvailable(columnNumber)) {
            cout << "please choose where to drop from 0 to " << board.getNumberOfColumns() << ": ";
            cin >> columnNumber;
        }

        board.drop(board.getPlayerColor(), columnNumber);
        board.drop(board.getComputerColor(), computer.randomColumn(board));
        board.drawBoard();
    }
    cout << "\n=== Game over, " << board.getColorThatWon() << " has won ===\n";

    return 0;
}
