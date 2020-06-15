//
// Created by Javid Asgarov on 15.06.20.
//

#include "Game.h"


/**
 * Template method that is called with the correct Bot for the chosen strategy.
 * @tparam T
 * @param bot
 * @return column that the bot has chosen
 */
template<class T>
int Game::computerPlay(T bot) {
    if (randomStrategy) {
        return bot.chooseColumn(board);
    }
    return bot.chooseColumn(board);
}

/**
 * Method that calls the computer play method with the correct Bot based on the user chosen opponent
 * @return
 */
int Game::computerPlay() {
    if (randomStrategy) {
        return computerPlay(randomBot);
    }
    return computerPlay(fromLeftBot);
}

/**
 * Checks if the game has been won
 * @return boolean
 */
bool Game::isWon() {
    bool won = false;
    for (int i = 0; i < board.getNumberOfRows(); ++i) {
        for (int j = 0; j < board.getNumberOfRows(); ++j) {
            if (board.getBoard().at(i).at(j) == playerColor || board.getBoard().at(i).at(j) == computerColor) {
                won = board.checkHorizontalAndVertical(i, j)
                      || board.checkDiagonal(i, j);
                if (won) {
                    colorThatWon = board.getBoard().at(i).at(j);
                    return true;
                }
            }
        }
    }
    return won;
}

/**
 * Method used to display the board
 * (delegated to the board)
 */
void Game::displayBoard() {
    board.drawBoard();
}

/**
 * Drops the player color into the board in the user chosen column
 * @param column
 */
void Game::makePlayerMove(int column) {
    board.drop(playerColor, column);
}

/**
 * Drops the computer color into the board in the computer chosen column
 * @param column
 */
void Game::makeComputerMove(int column) {
    board.drop(computerColor, column);
}

/**
 * Constructor
 * @param strategy
 * @param color
 */
Game::Game(bool strategy, char color) {
    randomStrategy = strategy;
    setColors(color);
}

//Getters and Setters

char Game::getColorThatWon() const {
    return colorThatWon;
}

Board &Game::getBoard() {
    return board;
}

void Game::setColors(char color) {
    if (color == 'Y') {
        computerColor = 'R';
    } else {
        computerColor = 'Y';
    }
    playerColor = color;
}
