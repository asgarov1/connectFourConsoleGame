//
// Created by Javid Asgarov on 15.06.20.
//

#include "FromLeftBot.h"

/**
 * implements the Interface IBot method to choose column, chooses leftest available column
 * @param board
 * @return number of the chosen column
 */
int FromLeftBot::chooseColumn(Board board) {
    int randomNumber = 0;
    for (int i = 0; i < board.getNumberOfColumns(); ++i) {
        if(board.isColumnAvailable(i)){
            return i;
        }
    }
    return randomNumber;
}
