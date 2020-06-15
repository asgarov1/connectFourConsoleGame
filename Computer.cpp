//
// Created by extremer on 15.06.20.
//

#include <cstdlib>
#include "Computer.h"

int Computer::randomColumn(Board board) {
    int numberOfColumns = board.getNumberOfColumns();

    int randomNumber = rand() % numberOfColumns;
    while(!board.isColumnAvailable(randomNumber)){
        randomNumber = rand() % numberOfColumns;
    }
    return randomNumber;
}
