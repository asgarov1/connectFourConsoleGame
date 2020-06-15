//
// Created by extremer on 15.06.20.
//

#include <iostream>
#include "Board.h"

Board::Board() {

    //Initialising the board with empty spaces
    for (int i = 0; i < numberOfRows; ++i) {
        std::vector<char> temp;
        temp.reserve(numberOfColumns);
        for (int j = 0; j < numberOfColumns; ++j) {
            temp.emplace_back(' ');
        }
        board.emplace_back(temp);
    }
}

void Board::drawBoard() {
    for (int i = 0; i < numberOfColumns; ++i) {
        std::cout <<"  "<< i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < numberOfRows; ++i) {
        std::cout << "| ";
        for (int j = 0; j < numberOfColumns; ++j) {
            std::cout << board.at(i).at(j) << " | ";
        }
        std::cout << std::endl;
    }
}

bool Board::isWon() {
    bool won = false;
    for (int i = 0; i < numberOfRows; ++i) {
        for (int j = 0; j < numberOfColumns; ++j) {
            if (board.at(i).at(j) == playerColor || board.at(i).at(j) == computerColor) {
                won = checkHorizontalAndVertical(i, j)
                      || checkDiagonal(i, j);
                if (won) {
                    colorThatWon = board.at(i).at(j);
                    return true;
                }
            }
        }
    }
    return won;
}

bool Board::checkHorizontalAndVertical(int i, int j) {
    return checkLeft(i, j) ||
           checkUp(i, j);
}

bool Board::checkDiagonal(int i, int j) {
    return checkLeftUp(i, j) ||
           checkRightUp(i, j);
}

bool Board::checkLeft(int y, int x) {
    char color = board.at(y).at(x);
    if (x < 3) {
        return false;
    }
    return board.at(y).at(x - 1) == color && board.at(y).at(x - 2) == color && board.at(y).at(x - 3) == color;
}

bool Board::checkUp(int y, int x) {
    char color = board.at(y).at(x);
    if (y < 3) {
        return false;
    }
    return board.at(y - 1).at(x) == color && board.at(y - 2).at(x) == color && board.at(y - 3).at(x) == color;
}

bool Board::checkLeftUp(int y, int x) {
    char color = board.at(y).at(x);
    if (y < 3 || x < 3) {
        return false;
    }
    return board.at(y - 1).at(x - 1) == color &&
           board.at(y - 2).at(x - 2) == color &&
           board.at(y - 3).at(x - 3) == color;
}

bool Board::checkRightUp(int y, int x) {
    char color = board.at(y).at(x);
    if (y < 3 || x > numberOfColumns - 4) {
        return false;
    }
    return board.at(y - 1).at(x + 1) == color &&
           board.at(y - 2).at(x + 2) == color &&
           board.at(y - 3).at(x + 3) == color;
}

int Board::getNumberOfColumns() const {
    return numberOfColumns;
}

bool Board::hasSpace() {
    for (int i = 0; i < numberOfRows; ++i) {
        for (int j = 0; j < numberOfColumns; ++j) {
            if (board.at(i).at(j) == ' ') {
                return true;
            }
        }
    }
    return false;
}

bool Board::isColumnAvailable(int columnNumber) {
    if(columnNumber < 0 || columnNumber > numberOfColumns){
        return false;
    }
    return board.at(0).at(columnNumber) == ' ';
}

void Board::drop(char color, int columnNumber) {
    for (int i = 0; i < numberOfRows; ++i) {
        if (i < numberOfRows-1 && board.at(i + 1).at(columnNumber) == ' ') {
            continue;
        } else {
            board.at(i).at(columnNumber) = color;
            break;
        }
    }
}

char Board::getPlayerColor() const {
    return playerColor;
}

void Board::setPlayerColor(char playerColor) {
    Board::playerColor = playerColor;
}

char Board::getComputerColor() const {
    return computerColor;
}

void Board::setComputerColor(char computerColor) {
    Board::computerColor = computerColor;
}

void Board::setColors(char playerColor) {
    if (playerColor == 'Y') {
        setComputerColor('R');
    } else {
        setComputerColor('Y');
    }
    setPlayerColor(playerColor);
}

char Board::getColorThatWon() const {
    return colorThatWon;
}
