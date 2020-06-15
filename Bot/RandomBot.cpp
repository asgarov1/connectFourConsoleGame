//
// Created by Javid Asgarov on 15.06.20.
//

#include <cstdlib>
#include "RandomBot.h"

/**
 * implements the Interface method to choose column, chooses column randomly
 * @param board
 * @return number of the chosen column
 */
int RandomBot::chooseColumn(Board board) {
    int numberOfColumns = board.getNumberOfColumns();

    int randomNumber = rand() % numberOfColumns;
    while(!board.isColumnAvailable(randomNumber)){
        randomNumber = rand() % numberOfColumns;
    }
    return randomNumber;
}
