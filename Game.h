//
// Created by Javid Asgarov on 15.06.20.
//

#ifndef VIERGEWINNT_GAME_H
#define VIERGEWINNT_GAME_H

#include "Bot/RandomBot.h"
#include "Bot/FromLeftBot.h"

class Game {
    Board board;
    bool randomStrategy = false;

    RandomBot randomBot;
    FromLeftBot fromLeftBot;

    char playerColor = ' ';
    char computerColor = ' ';
    char colorThatWon = ' ';

    template<class T>
    int computerPlay(T bot);

public:
    bool isWon();

    void displayBoard();

    int computerPlay();

    //Getters and Setters
    [[nodiscard]] char getColorThatWon() const;

    void setColors(char playerColor);

    [[nodiscard]] Board &getBoard();

    Game(bool randomStrategy, char playerColor);

    void makePlayerMove(int column);

    void makeComputerMove(int column);
};


#endif //VIERGEWINNT_GAME_H
