//
// Created by Javid Asgarov on 15.06.20.
//

#include <iostream>
#include "Board.h"

/**
 * Default constructor, initialeses board with empty spaces
 */
Board::Board() {
    for (int i = 0; i < numberOfRows; ++i) {
        std::vector<char> temp;
        temp.reserve(numberOfColumns);
        for (int j = 0; j < numberOfColumns; ++j) {
            temp.emplace_back(' ');
        }
        board.emplace_back(temp);
    }
}

/**
 * Method to print board in the console
 * STL library method was used to display vectors using iterator
 */
void Board::drawBoard() {
    for (int i = 0; i < numberOfColumns; ++i) {
        std::cout << "  " << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < numberOfRows; ++i) {
        std::cout << "| ";

        std::vector<char>::iterator iter;
        for (iter = board.at(i).begin(); iter != board.at(i).end(); iter++) {
            std::cout << *iter << " | ";
        }

        std::cout << std::endl;
    }
}

/**
 * Tells if board has space left (used to determine if the game has ended in draw)
 * @return
 */
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

/**
 * Checks if chosen column is available (i.e. not full)
 * @param columnNumber
 * @return true for yes, false if column is full
 */
bool Board::isColumnAvailable(int columnNumber) {
    if (columnNumber < 0 || columnNumber > numberOfColumns) {
        return false;
    }
    return board.at(0).at(columnNumber) == ' ';
}

/**
 * Method that drops the 'stone' down the column
 * @param color
 * @param columnNumber
 */
void Board::drop(char color, int columnNumber) {
    for (int i = 0; i < numberOfRows; ++i) {
        if (i < numberOfRows - 1 && board.at(i + 1).at(columnNumber) == ' ') {
            continue;
        } else {
            board.at(i).at(columnNumber) = color;
            break;
        }
    }
}


//Bunch of checking methods that check if the game has been won via connecting four pieces

bool Board::checkHorizontalAndVertical(int i, int j) {
    return checkLeft(i, j) || checkUp(i, j);
}


bool Board::checkDiagonal(int i, int j) {
    return checkLeftUp(i, j) || checkRightUp(i, j);
}

bool Board::checkLeft(int y, int x) {
    char color = board.at(y).at(x);
    if (x < 3) {
        return false;
    }
    return board.at(y).at(x - 1) == color && board.at(y).at(x - 2) == color &&
           board.at(y).at(x - 3) == color;
}

bool Board::checkUp(int y, int x) {
    char color = board.at(y).at(x);
    if (y < 3) {
        return false;
    }
    return board.at(y - 1).at(x) == color && board.at(y - 2).at(x) == color &&
           board.at(y - 3).at(x) == color;
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

//Getters
const std::vector<std::vector<char>> &Board::getBoard() const {
    return board;
}

int Board::getNumberOfRows() const {
    return numberOfRows;
}

int Board::getNumberOfColumns() const {
    return numberOfColumns;
}
