//
// Created by extremer on 15.06.20.
//

#ifndef VIERGEWINNT_BOARD_H
#define VIERGEWINNT_BOARD_H


#include <vector>
#include <string>

class Board {
    //Numbers are chosen based on wikipedia article's most common size
    int numberOfColumns{7};
    int numberOfRows{6};

    char playerColor = ' ';
    char computerColor = ' ';

    char colorThatWon;

    std::vector<std::vector<char>> board;

    bool checkHorizontalAndVertical(int i, int j);

    bool checkLeft(int y, int x);

    bool checkUp(int y, int x);

    bool checkLeftUp(int y, int x);

    bool checkRightUp(int y, int x);

public:
    Board();

    bool isWon();

    void drawBoard();

    bool checkDiagonal(int i, int j);

    [[nodiscard]] int getNumberOfColumns() const;

    bool hasSpace();

    bool isColumnAvailable(int columnNumber);

    char getPlayerColor() const;

    void setPlayerColor(char playerColor);

    char getComputerColor() const;

    void setComputerColor(char computerColor);

    void drop(char color, int columnNumber);

    void setColors(char playerColor);

    char getColorThatWon() const;
};

#endif //VIERGEWINNT_BOARD_H
