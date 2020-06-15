//
// Created by Javid Asgarov on 15.06.20.
//

#ifndef VIERGEWINNT_RANDOMBOT_H
#define VIERGEWINNT_RANDOMBOT_H


#include "../Board.h"
#include "IBot.h"

class RandomBot : public IBot {

public:
    int chooseColumn(Board board) override;
};


#endif //VIERGEWINNT_RANDOMBOT_H
