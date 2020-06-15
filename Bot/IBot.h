//
// Created by Javid Asgarov on 15.06.20.
//

#ifndef VIERGEWINNT_IBOT_H
#define VIERGEWINNT_IBOT_H


#include "../Board.h"

/**
 * Interface for the bots to implement, has one method choose column that each Bot will implement differently
 */
class IBot {
public:
    virtual int chooseColumn(Board board) = 0;
};


#endif //VIERGEWINNT_IBOT_H
