//
// Created by Javid Asgarov on 15.06.20.
//

#ifndef VIERGEWINNT_FROMLEFTBOT_H
#define VIERGEWINNT_FROMLEFTBOT_H


#include "IBot.h"

class FromLeftBot : public IBot  {
public:
    int chooseColumn(Board board) override;
};


#endif //VIERGEWINNT_FROMLEFTBOT_H
